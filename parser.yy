%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #include "spec.hh"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  
}

// definition of set of tokens. All tokens are of type string
//Types
%token <std::string> INT BOOLEAN STRING VOID CLASS
//Operations
%token <std::string> EQUAL
//Statements
%token <std::string> IF WHILE
//Other
%token <std::string> PUBLIC STATIC MAIN COMMA NUMBER
//(){}[]
%token <std::string> LP LB RB LCB RCB
//More other
%token <std::string> RETURN PRINTLN LENGTH TRUE FALSE THIS NEW SEMICOLON ID

%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
//Reference for Operator Precedence https://examradar.com/operators-precedence-c/ AND https://introcs.cs.princeton.edu/java/11precedence/
%left     <std::string> OR                  //Logical OR
%left     <std::string> AND                 //Logical AND
%left     <std::string> EQUALEQUAL          //Equality
%left     <std::string> LESSTHAN MORETHAN   //Relational
%right    <std::string> PLUSOP MINUSOP NOT  //Additive
%left     <std::string> MULTOP DIVOP        //Multiplicative
%left     <std::string> DOT                 //Postfix

%nonassoc <std::string> RP
%nonassoc <std::string> ELSE


// definition of the production rules. All production rules are of type Node
%type <Node *> goal mainClass classDeclaration varDeclaration methodDeclaration type statement expression identifier
%type <Node *> classList statementList varDeclarationList methodDeclarationList
%type <Node *> arg argument argumentList expressionListComma
%type <Node *> methodBody methodBodyList
%type <Node *> ifStatement

%%


goal:
  mainClass classList END
  {
    $$ = new Node(GOAL, "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    root = $$;
  }
;

classList:
  %empty
  {
    $$ = new Node(CLASS_LIST, "", yylineno);
  }
  |classDeclaration
  {
    $$ = new Node(CLASS_LIST, "", yylineno);
    $$->children.push_back($1);
  }
  |classList classDeclaration
  {
    $$ = $1;
    $$->children.push_back($2);
  }
;

mainClass:
  PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB statement RCB RCB
  {
    $$ = new Node(MAIN_CLASS, "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($13);
    $$->children.push_back($16);
  } 
;

classDeclaration:
  CLASS identifier LCB varDeclarationList methodDeclarationList RCB
  {
    $$ = new Node(CLASS_DECLARATION, "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($4);
    $$->children.push_back($5);
  }     
;

varDeclarationList:
  %empty
  {
    $$ = new Node(VAR_DECLARATION_LIST, "", yylineno);
  }
  |varDeclaration
  {
    $$ = new Node(VAR_DECLARATION_LIST, "", yylineno);
    $$->children.push_back($1);
  }
  |varDeclarationList varDeclaration
  {
    $$ = $1;
    $$->children.push_back($2);
  }


varDeclaration:
  type identifier SEMICOLON
  {
    $$ = new Node(VAR_DECLARATION, "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
;

argumentList:
  %empty
  {
    $$ = new Node(ARGUMENT_LIST, "", yylineno);
  }
  |argument
  {
    $$ = new Node(ARGUMENT_LIST, "", yylineno);
    $$->children.push_back($1);
  }
  |argumentList argument
  {
    $$ = $1;
    $$->children.push_back($2);
  }
argument:
          COMMA type identifier
          {
            $$ = new Node(ARGUMENT, "", yylineno);
            $$->children.push_back($2);
            $$->children.push_back($3);
          }
arg:
          type identifier
          {
            $$ = new Node(ARGUMENT, "", yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
          }
;

methodDeclarationList:
  %empty
  {
    $$ = new Node(METHOD_DECLARATION_LIST, "", yylineno);
  }
  |methodDeclaration
  {
    $$ = new Node(METHOD_DECLARATION_LIST, "", yylineno);
    $$->children.push_back($1);
  }
  | methodDeclarationList methodDeclaration
  {
    $$ = $1;
    $$->children.push_back($2);
  }

methodDeclaration:
  PUBLIC type identifier LP RP LCB methodBodyList RETURN expression SEMICOLON RCB
  {
    $$ = new Node(METHOD_DECLARATION, "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($7);
    $$->children.push_back($9);
  }
  |PUBLIC type identifier LP arg argumentList RP LCB methodBodyList RETURN expression SEMICOLON RCB
  {
    $$ = new Node(METHOD_DECLARATION_ARGUMENTS, "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($6);
    $$->children.push_back($9);
    $$->children.push_back($11);
  }
;         


methodBodyList:
  %empty
  {
    $$ = new Node(METHOD_BODY_EMPTY, "", yylineno);
  }
  |methodBody
  {
    $$ = $1;
  }
  |methodBodyList methodBody
  {
    $$ = $1;
    $$->children.push_back($2);
  }
methodBody:
  varDeclaration
  {
    $$ = new Node(METHOD_BODY_VAR, "", yylineno);
    $$->children.push_back($1);
  }
  |statement
  {
    $$ = new Node(METHOD_BODY_STAT, "", yylineno);
    $$->children.push_back($1);
  }
;

type:
  INT LB RB
  {
    $$ = new Node(TYPE, INT_ARR , yylineno);

  }
  |BOOLEAN
  {
    $$ = new Node(TYPE, BOOLEAN , yylineno);
  }
  |INT
  {
    $$ = new Node(TYPE, INT, yylineno);
  }
  |identifier
  {
    $$ = $1;
  }
;

ifStatement:
  IF LP expression RP statement
  {
    $$ = new Node(IF_STATEMENT, "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  |IF LP expression RP statement ELSE statement  %prec ELSE
  {
    $$ = new Node(IF_ELSE_STATEMENT, "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($7);
  }  

statementList:
  %empty
  {
    $$ = new Node(STATEMENT_LIST, "", yylineno);
  }
  |statement
  {
    $$ = $1;
  }
  |
  statementList statement
  {
    $$ = $1;
    $$->children.push_back($2);
  }


statement:
  LCB statementList RCB
  {
    $$ = new Node(STATEMENT_LIST, "", yylineno);
    $$->children.push_back($2);
  }
  |ifStatement
  {
    $$ = $1;
  }
  |WHILE LP expression RP statement
  {
    $$ = new Node(WHILE_STATEMENT, "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  |PRINTLN LP expression RP SEMICOLON
  {
    $$ = new Node(PRINTLN_STATEMENT, "", yylineno);
    $$->children.push_back($3);
  }
  |identifier EQUAL expression SEMICOLON
  {
    $$ = new Node(EQUAL_STATEMENT, "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |identifier LB expression RB EQUAL expression SEMICOLON
  {
    $$ = new Node(EQUAL_ARR_STATEMENT, "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
  }
;


expressionListComma:
  %empty
  {
    $$ = new Node(EXPRESSION_LIST_COMMA, "", yylineno);
  }
  |COMMA expression
  {
    $$ = new Node(EXPRESSION_LIST_COMMA, "", yylineno);
    $$->children.push_back($2);
  }
  |
  expressionListComma COMMA expression
  {
    $$ = $1;
    $$->children.push_back($3);
  }

expression: 
  expression AND expression 
  {     
    $$ = new Node(EXPRESSION_OP, AND_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression OR expression 
  {     
    $$ = new Node(EXPRESSION_OP, OR_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression LESSTHAN expression 
  {     
    $$ = new Node(EXPRESSION_OP, LESS_THAN_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression MORETHAN expression 
  {     
    $$ = new Node(EXPRESSION_OP, MORE_THAN_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression PLUSOP expression 
  {     
    $$ = new Node(EXPRESSION_OP, PLUS_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression MINUSOP expression 
  {     
    $$ = new Node(EXPRESSION_OP, MINUS_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression MULTOP expression 
  {     
    $$ = new Node(EXPRESSION_OP, MULT_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression DIVOP expression 
  {     
    $$ = new Node(EXPRESSION_OP, DIV_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression EQUALEQUAL expression 
  {     
    $$ = new Node(EXPRESSION_OP, EQUAL_EXPRESSION, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression LB expression RB
  {
    $$ = new Node(EXPRESSION_ARR, "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |expression DOT LENGTH
  {
    $$ = new Node(EXPRESSION_LEN, "", yylineno);
    $$->children.push_back($1);
  } 
  |expression DOT identifier LP expression expressionListComma RP
  {
    $$ = new Node(EXPRESSION_X, "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($6);
  } 
  |expression DOT identifier LP RP
  {
    $$ = new Node(EXPRESSION_X2,"" , yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }                        
  |NUMBER 
  {
    $$ = new Node(INT,$1 , yylineno);
  }
  |TRUE
  {
    $$ = new Node(BOOLEAN,$1 , yylineno);
  }
  |FALSE
  {
    $$ = new Node(BOOLEAN,$1 , yylineno);
  }
  |identifier
  {
    $$ = $1;
  }
  |THIS
  {
    $$ = new Node(THIS,$1 , yylineno);
  }
  |NEW INT LB expression RB
  {
    $$ = new Node(NEW_INT_ARR,"" , yylineno);
    $$->children.push_back($4);
  }
  |NEW identifier LP RP
  {
    $$ = new Node(NEW_IDENTIFIER,"" , yylineno);
    $$->children.push_back($2);
  }
  |NOT expression
  {
    $$ = new Node(NOT_EXPRESSION,"" , yylineno);
    $$->children.push_back($2);
  }
  |LP expression RP
  {
    $$ = $2;
  }         
;


identifier:
  ID 
  {
    $$ = new Node(IDENTIFIER, $1, yylineno);
  } 