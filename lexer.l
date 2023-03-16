%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
#include "spec.hh"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 


intager 0|[1-9][0-9]*
id      [a-zA-Z][a-zA-Z0-9_]*

%%

"class"                 {if(PRINT_LEX){printf("class ");}           return yy::parser::make_CLASS(yytext);}                      
"public"                {if(PRINT_LEX){printf("public ");}          return yy::parser::make_PUBLIC(yytext);}     
"static"                {if(PRINT_LEX){printf("static ");}          return yy::parser::make_STATIC(yytext);}                      
"void"                  {if(PRINT_LEX){printf("void ");}            return yy::parser::make_VOID(yytext);}                      
"main"                  {if(PRINT_LEX){printf("main ");}            return yy::parser::make_MAIN(yytext);}
"String"                {if(PRINT_LEX){printf("string ");}          return yy::parser::make_STRING(yytext);}
"return"                {if(PRINT_LEX){printf("return ");}          return yy::parser::make_RETURN(yytext);}
"int"                   {if(PRINT_LEX){printf("int ");}             return yy::parser::make_INT(yytext);}
"boolean"               {if(PRINT_LEX){printf("bool ");}            return yy::parser::make_BOOLEAN(yytext);}
"if"                    {if(PRINT_LEX){printf("if ");}              return yy::parser::make_IF(yytext);}
"else"                  {if(PRINT_LEX){printf("else ");}            return yy::parser::make_ELSE(yytext);}
"while"                 {if(PRINT_LEX){printf("while ");}           return yy::parser::make_WHILE(yytext);}
"System.out.println"    {if(PRINT_LEX){printf("System ");}          return yy::parser::make_PRINTLN(yytext);}
"length"                {if(PRINT_LEX){printf("length ");}          return yy::parser::make_LENGTH(yytext);}
"true"                  {if(PRINT_LEX){printf("true ");}            return yy::parser::make_TRUE(yytext);}
"false"                 {if(PRINT_LEX){printf("false ");}           return yy::parser::make_FALSE(yytext);}
"this"                  {if(PRINT_LEX){printf("this ");}            return yy::parser::make_THIS(yytext);}
"new"                   {if(PRINT_LEX){printf("new ");}             return yy::parser::make_NEW(yytext);}

{intager}               {if(PRINT_LEX){printf("INT:%s ", yytext);}  return yy::parser::make_NUMBER(yytext);}
{id}                    {if(PRINT_LEX){printf("ID:%s ", yytext);}   return yy::parser::make_ID(yytext);}

                       
"{"                     {if(PRINT_LEX){printf("{ ");}               return yy::parser::make_LCB(yytext);}
"}"                     {if(PRINT_LEX){printf("} ");}               return yy::parser::make_RCB(yytext);}
"["                     {if(PRINT_LEX){printf("[ ");}               return yy::parser::make_LB(yytext);}         
"]"                     {if(PRINT_LEX){printf("] ");}               return yy::parser::make_RB(yytext);}
"("                     {if(PRINT_LEX){printf("( ");}               return yy::parser::make_LP(yytext);}
")"                     {if(PRINT_LEX){printf(") ");}               return yy::parser::make_RP(yytext);}
";"                     {if(PRINT_LEX){printf("; ");}               return yy::parser::make_SEMICOLON(yytext);}
"&&"                    {if(PRINT_LEX){printf("&& ");}              return yy::parser::make_AND(yytext);}
"||"                    {if(PRINT_LEX){printf("|| ");}              return yy::parser::make_OR(yytext);}
"<"                     {if(PRINT_LEX){printf("< ");}               return yy::parser::make_LESSTHAN(yytext);}
">"                     {if(PRINT_LEX){printf("> ");}               return yy::parser::make_MORETHAN(yytext);}
"=="                    {if(PRINT_LEX){printf("== ");}              return yy::parser::make_EQUALEQUAL(yytext);}
"+"                     {if(PRINT_LEX){printf("+ ");}               return yy::parser::make_PLUSOP(yytext);}
"-"                     {if(PRINT_LEX){printf("- ");}               return yy::parser::make_MINUSOP(yytext);}
"*"                     {if(PRINT_LEX){printf("* ");}               return yy::parser::make_MULTOP(yytext);} 
"/"                     {if(PRINT_LEX){printf("/ ");}               return yy::parser::make_DIVOP(yytext);}
"!"                     {if(PRINT_LEX){printf("! ");}               return yy::parser::make_NOT(yytext);}
"."                     {if(PRINT_LEX){printf(". ");}               return yy::parser::make_DOT(yytext);}
","                     {if(PRINT_LEX){printf(", ");}               return yy::parser::make_COMMA(yytext);}
"="                     {if(PRINT_LEX){printf("= ");}               return yy::parser::make_EQUAL(yytext);}


[\t\r]+                 {}
" "+                    {}
\n+                     {if(PRINT_LEX){printf("\n");}}
"//".*                  {if(PRINT_LEX){printf("Comment\n");}}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                 return yy::parser::make_END();
%%