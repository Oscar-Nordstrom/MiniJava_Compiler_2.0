// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 12 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  

#line 56 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 129 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_classList: // classList
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclarationList: // varDeclarationList
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_argumentList: // argumentList
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodBodyList: // methodBodyList
      case symbol_kind::S_methodBody: // methodBody
      case symbol_kind::S_type: // type
      case symbol_kind::S_ifStatement: // ifStatement
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expressionListComma: // expressionListComma
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQUALEQUAL: // EQUALEQUAL
      case symbol_kind::S_LESSTHAN: // LESSTHAN
      case symbol_kind::S_MORETHAN: // MORETHAN
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_classList: // classList
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclarationList: // varDeclarationList
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_argumentList: // argumentList
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodBodyList: // methodBodyList
      case symbol_kind::S_methodBody: // methodBody
      case symbol_kind::S_type: // type
      case symbol_kind::S_ifStatement: // ifStatement
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expressionListComma: // expressionListComma
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQUALEQUAL: // EQUALEQUAL
      case symbol_kind::S_LESSTHAN: // LESSTHAN
      case symbol_kind::S_MORETHAN: // MORETHAN
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_ELSE: // ELSE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_classList: // classList
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclarationList: // varDeclarationList
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_argumentList: // argumentList
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodBodyList: // methodBodyList
      case symbol_kind::S_methodBody: // methodBody
      case symbol_kind::S_type: // type
      case symbol_kind::S_ifStatement: // ifStatement
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expressionListComma: // expressionListComma
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQUALEQUAL: // EQUALEQUAL
      case symbol_kind::S_LESSTHAN: // LESSTHAN
      case symbol_kind::S_MORETHAN: // MORETHAN
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_ELSE: // ELSE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_classList: // classList
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclarationList: // varDeclarationList
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_argumentList: // argumentList
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodBodyList: // methodBodyList
      case symbol_kind::S_methodBody: // methodBody
      case symbol_kind::S_type: // type
      case symbol_kind::S_ifStatement: // ifStatement
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expressionListComma: // expressionListComma
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQUALEQUAL: // EQUALEQUAL
      case symbol_kind::S_LESSTHAN: // LESSTHAN
      case symbol_kind::S_MORETHAN: // MORETHAN
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_ELSE: // ELSE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_classList: // classList
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclarationList: // varDeclarationList
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_argumentList: // argumentList
      case symbol_kind::S_argument: // argument
      case symbol_kind::S_arg: // arg
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodBodyList: // methodBodyList
      case symbol_kind::S_methodBody: // methodBody
      case symbol_kind::S_type: // type
      case symbol_kind::S_ifStatement: // ifStatement
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expressionListComma: // expressionListComma
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQUALEQUAL: // EQUALEQUAL
      case symbol_kind::S_LESSTHAN: // LESSTHAN
      case symbol_kind::S_MORETHAN: // MORETHAN
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // goal: mainClass classList "end of file"
#line 64 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(GOAL, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    root = yylhs.value.as < Node * > ();
  }
#line 845 "parser.tab.cc"
    break;

  case 3: // classList: %empty
#line 74 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(CLASS_LIST, "", yylineno);
  }
#line 853 "parser.tab.cc"
    break;

  case 4: // classList: classDeclaration
#line 78 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(CLASS_LIST, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 862 "parser.tab.cc"
    break;

  case 5: // classList: classList classDeclaration
#line 83 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 871 "parser.tab.cc"
    break;

  case 6: // mainClass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB statement RCB RCB
#line 91 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(MAIN_CLASS, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 882 "parser.tab.cc"
    break;

  case 7: // classDeclaration: CLASS identifier LCB varDeclarationList methodDeclarationList RCB
#line 101 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(CLASS_DECLARATION, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 893 "parser.tab.cc"
    break;

  case 8: // varDeclarationList: %empty
#line 111 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(VAR_DECLARATION_LIST, "", yylineno);
  }
#line 901 "parser.tab.cc"
    break;

  case 9: // varDeclarationList: varDeclaration
#line 115 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(VAR_DECLARATION_LIST, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 910 "parser.tab.cc"
    break;

  case 10: // varDeclarationList: varDeclarationList varDeclaration
#line 120 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 919 "parser.tab.cc"
    break;

  case 11: // varDeclaration: type identifier SEMICOLON
#line 128 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(VAR_DECLARATION, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 929 "parser.tab.cc"
    break;

  case 12: // argumentList: %empty
#line 137 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(ARGUMENT_LIST, "", yylineno);
  }
#line 937 "parser.tab.cc"
    break;

  case 13: // argumentList: argument
#line 141 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(ARGUMENT_LIST, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 946 "parser.tab.cc"
    break;

  case 14: // argumentList: argumentList argument
#line 146 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 955 "parser.tab.cc"
    break;

  case 15: // argument: COMMA type identifier
#line 152 "parser.yy"
          {
            yylhs.value.as < Node * > () = new Node(ARGUMENT, "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 965 "parser.tab.cc"
    break;

  case 16: // arg: type identifier
#line 159 "parser.yy"
          {
            yylhs.value.as < Node * > () = new Node(ARGUMENT, "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 975 "parser.tab.cc"
    break;

  case 17: // methodDeclarationList: %empty
#line 168 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_DECLARATION_LIST, "", yylineno);
  }
#line 983 "parser.tab.cc"
    break;

  case 18: // methodDeclarationList: methodDeclaration
#line 172 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_DECLARATION_LIST, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 992 "parser.tab.cc"
    break;

  case 19: // methodDeclarationList: methodDeclarationList methodDeclaration
#line 177 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1001 "parser.tab.cc"
    break;

  case 20: // methodDeclaration: PUBLIC type identifier LP RP LCB methodBodyList RETURN expression SEMICOLON RCB
#line 184 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_DECLARATION, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1013 "parser.tab.cc"
    break;

  case 21: // methodDeclaration: PUBLIC type identifier LP arg argumentList RP LCB methodBodyList RETURN expression SEMICOLON RCB
#line 192 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_DECLARATION_ARGUMENTS, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1027 "parser.tab.cc"
    break;

  case 22: // methodBodyList: %empty
#line 206 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_BODY_EMPTY, "", yylineno);
  }
#line 1035 "parser.tab.cc"
    break;

  case 23: // methodBodyList: methodBody
#line 210 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1043 "parser.tab.cc"
    break;

  case 24: // methodBodyList: methodBodyList methodBody
#line 214 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1052 "parser.tab.cc"
    break;

  case 25: // methodBody: varDeclaration
#line 220 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_BODY_VAR, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1061 "parser.tab.cc"
    break;

  case 26: // methodBody: statement
#line 225 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(METHOD_BODY_STAT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1070 "parser.tab.cc"
    break;

  case 27: // type: INT LB RB
#line 233 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(TYPE, INT_ARR , yylineno);

  }
#line 1079 "parser.tab.cc"
    break;

  case 28: // type: BOOLEAN
#line 238 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(TYPE, BOOLEAN , yylineno);
  }
#line 1087 "parser.tab.cc"
    break;

  case 29: // type: INT
#line 242 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(TYPE, INT, yylineno);
  }
#line 1095 "parser.tab.cc"
    break;

  case 30: // type: identifier
#line 246 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1103 "parser.tab.cc"
    break;

  case 31: // ifStatement: IF LP expression RP statement
#line 253 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(IF_STATEMENT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1113 "parser.tab.cc"
    break;

  case 32: // ifStatement: IF LP expression RP statement ELSE statement
#line 259 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(IF_ELSE_STATEMENT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1124 "parser.tab.cc"
    break;

  case 33: // statementList: %empty
#line 268 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(STATEMENT_LIST, "", yylineno);
  }
#line 1132 "parser.tab.cc"
    break;

  case 34: // statementList: statement
#line 272 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1140 "parser.tab.cc"
    break;

  case 35: // statementList: statementList statement
#line 277 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1149 "parser.tab.cc"
    break;

  case 36: // statement: LCB statementList RCB
#line 285 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(STATEMENT_LIST, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1158 "parser.tab.cc"
    break;

  case 37: // statement: ifStatement
#line 290 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1166 "parser.tab.cc"
    break;

  case 38: // statement: WHILE LP expression RP statement
#line 294 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(WHILE_STATEMENT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1176 "parser.tab.cc"
    break;

  case 39: // statement: PRINTLN LP expression RP SEMICOLON
#line 300 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(PRINTLN_STATEMENT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1185 "parser.tab.cc"
    break;

  case 40: // statement: identifier EQUAL expression SEMICOLON
#line 305 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EQUAL_STATEMENT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1195 "parser.tab.cc"
    break;

  case 41: // statement: identifier LB expression RB EQUAL expression SEMICOLON
#line 311 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EQUAL_ARR_STATEMENT, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1206 "parser.tab.cc"
    break;

  case 42: // expressionListComma: %empty
#line 322 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EXPRESSION_LIST_COMMA, "", yylineno);
  }
#line 1214 "parser.tab.cc"
    break;

  case 43: // expressionListComma: COMMA expression
#line 326 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EXPRESSION_LIST_COMMA, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1223 "parser.tab.cc"
    break;

  case 44: // expressionListComma: expressionListComma COMMA expression
#line 332 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1232 "parser.tab.cc"
    break;

  case 45: // expression: expression AND expression
#line 339 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, AND_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1242 "parser.tab.cc"
    break;

  case 46: // expression: expression OR expression
#line 345 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, OR_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1252 "parser.tab.cc"
    break;

  case 47: // expression: expression LESSTHAN expression
#line 351 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, LESS_THAN_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1262 "parser.tab.cc"
    break;

  case 48: // expression: expression MORETHAN expression
#line 357 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, MORE_THAN_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1272 "parser.tab.cc"
    break;

  case 49: // expression: expression PLUSOP expression
#line 363 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, PLUS_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1282 "parser.tab.cc"
    break;

  case 50: // expression: expression MINUSOP expression
#line 369 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, MINUS_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1292 "parser.tab.cc"
    break;

  case 51: // expression: expression MULTOP expression
#line 375 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, MULT_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1302 "parser.tab.cc"
    break;

  case 52: // expression: expression DIVOP expression
#line 381 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, DIV_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1312 "parser.tab.cc"
    break;

  case 53: // expression: expression EQUALEQUAL expression
#line 387 "parser.yy"
  {     
    yylhs.value.as < Node * > () = new Node(EXPRESSION_OP, EQUAL_EXPRESSION, yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1322 "parser.tab.cc"
    break;

  case 54: // expression: expression LB expression RB
#line 393 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EXPRESSION_ARR, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1332 "parser.tab.cc"
    break;

  case 55: // expression: expression DOT LENGTH
#line 399 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EXPRESSION_LEN, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1341 "parser.tab.cc"
    break;

  case 56: // expression: expression DOT identifier LP expression expressionListComma RP
#line 404 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EXPRESSION_X, "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1353 "parser.tab.cc"
    break;

  case 57: // expression: expression DOT identifier LP RP
#line 412 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(EXPRESSION_X2,"" , yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1363 "parser.tab.cc"
    break;

  case 58: // expression: NUMBER
#line 418 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(INT,yystack_[0].value.as < std::string > () , yylineno);
  }
#line 1371 "parser.tab.cc"
    break;

  case 59: // expression: TRUE
#line 422 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(BOOLEAN,yystack_[0].value.as < std::string > () , yylineno);
  }
#line 1379 "parser.tab.cc"
    break;

  case 60: // expression: FALSE
#line 426 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(BOOLEAN,yystack_[0].value.as < std::string > () , yylineno);
  }
#line 1387 "parser.tab.cc"
    break;

  case 61: // expression: identifier
#line 430 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1395 "parser.tab.cc"
    break;

  case 62: // expression: THIS
#line 434 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(THIS,yystack_[0].value.as < std::string > () , yylineno);
  }
#line 1403 "parser.tab.cc"
    break;

  case 63: // expression: NEW INT LB expression RB
#line 438 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(NEW_INT_ARR,"" , yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1412 "parser.tab.cc"
    break;

  case 64: // expression: NEW identifier LP RP
#line 443 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(NEW_IDENTIFIER,"" , yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1421 "parser.tab.cc"
    break;

  case 65: // expression: NOT expression
#line 448 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(NOT_EXPRESSION,"" , yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1430 "parser.tab.cc"
    break;

  case 66: // expression: LP expression RP
#line 453 "parser.yy"
  {
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
  }
#line 1438 "parser.tab.cc"
    break;

  case 67: // identifier: ID
#line 461 "parser.yy"
  {
    yylhs.value.as < Node * > () = new Node(IDENTIFIER, yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1446 "parser.tab.cc"
    break;


#line 1450 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -50;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -1,     9,    50,    46,    27,   -50,    27,    86,   -50,   -50,
      40,    43,   -50,   -50,    63,    19,    65,    58,   -50,    29,
     -50,    27,   -50,    99,    74,    19,   -50,    -7,   -50,    82,
     100,   -50,    27,   -50,   -50,   -50,   101,   102,   110,     2,
     103,    97,   105,    27,   106,    15,    19,   -11,   -50,   -50,
      27,   107,   135,   399,   139,   -50,   150,   -50,   -50,   -50,
      12,    27,   137,   -50,    81,   386,   386,   397,   -50,    12,
     386,   386,   -50,   386,   386,   -50,    15,   138,   -50,   386,
     -50,   -50,   -50,    -2,   386,   165,   -50,   177,   -50,   -50,
     197,   229,   249,   273,   164,   399,   209,   144,   147,   104,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     -15,   399,   399,   136,   145,   -50,   158,   386,   155,   -50,
     386,   129,   284,    49,   316,   259,   104,   104,   104,   104,
      21,    21,   -50,   160,   142,   -50,   -50,   -50,   386,   304,
     157,   328,   -50,   -50,   121,   399,   348,   161,   -50,   -50,
     -50,    95,   -50,   -50,   -50,   386,    -5,   360,   386,   -50,
     360
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     0,     1,     0,     0,     4,    67,
       0,     0,     2,     5,     0,     8,     0,    29,    28,    17,
       9,     0,    30,     0,     0,     0,    10,     0,    18,     0,
       0,    27,     0,     7,    19,    11,     0,     0,     0,     0,
       0,     0,    12,     0,     0,    22,     0,     0,    13,    16,
       0,     0,     0,    33,     0,    25,     0,    23,    37,    26,
      30,     0,     0,    14,     0,     0,     0,     0,    34,     0,
       0,     0,    24,     0,     0,    15,    22,     0,    58,     0,
      59,    60,    62,     0,     0,     0,    61,     0,    36,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,    66,
       0,     0,     0,    46,    45,    53,    47,    48,    49,    50,
      51,    52,    55,     0,    31,    38,    39,    20,     0,     0,
       0,     0,    64,    54,     0,     0,     0,     0,     6,    63,
      57,    42,    32,    41,    21,     0,     0,    43,     0,    56,
      44
  };

  const short
  parser::yypgoto_[] =
  {
     -50,   -50,   -50,   -50,   171,   -50,    32,   -50,   133,   -50,
     -50,   162,   111,   -49,    30,   -50,   -50,   -41,   -50,    -6,
      -4
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     7,     3,     8,    19,    55,    47,    48,    42,
      27,    28,    56,    57,    21,    58,    67,    59,   156,    85,
      86
  };

  const unsigned char
  parser::yytable_[] =
  {
      10,    97,    11,    46,    25,    17,    18,    72,   132,   158,
       1,    22,    68,    33,     9,    22,     4,    29,    17,    18,
      73,    22,    17,    18,    51,    52,    89,     9,    37,    74,
      62,     9,    17,    18,    53,    22,   159,    54,   100,    49,
      25,    60,    22,    41,     9,    72,    64,    20,     9,    69,
       5,    26,    60,     6,   118,    32,     9,    75,     9,    14,
      87,   110,    15,    69,    90,    91,   100,    92,    93,    43,
     134,   135,    60,    96,    16,    24,    61,    23,    99,    98,
     102,   103,   104,   105,   106,   107,    12,   108,   109,   110,
      60,    69,    31,     6,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   152,    30,   133,    69,    69,   155,
      35,   139,   100,    36,   141,    40,    45,    38,    39,    46,
      44,   100,    77,    65,    50,   101,   102,   103,   104,   105,
     106,   107,   146,   108,   109,   110,    78,    79,   151,   106,
     107,    69,   108,   109,   110,    80,    81,    82,    83,   157,
       9,    66,   160,    17,    18,    70,    76,    95,    84,    51,
      52,   120,   150,   121,   136,   137,   138,    17,    18,    53,
     142,    71,    54,    51,    52,   140,   144,   148,    13,     9,
      63,   154,   100,    53,   145,   117,    54,    94,     0,    34,
       0,     0,     0,     9,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,   110,   111,   101,   102,   103,
     104,   105,   106,   107,   100,   108,   109,   110,   112,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,   110,   113,   101,
     102,   103,   104,   105,   106,   107,   100,   108,   109,   110,
     119,     0,     0,     0,     0,     0,     0,   114,     0,   101,
     102,   103,   104,   105,   106,   107,   100,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   100,   115,     0,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,   110,
     100,   116,   104,   105,   106,   107,     0,   108,   109,   110,
       0,   100,   143,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,   110,   101,   102,   103,   104,   105,   106,
     107,   100,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   147,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,   109,   110,   100,   149,     0,   103,   104,
     105,   106,   107,     0,   108,   109,   110,     0,   101,   102,
     103,   104,   105,   106,   107,   100,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   153,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,   110,     0,
     101,   102,   103,   104,   105,   106,   107,     0,   108,   109,
     110,    78,    79,     0,     0,     0,    51,    52,    51,    52,
      80,    81,    82,    83,     0,     9,    53,    88,    53,    54,
       0,    54,     0,    84,     0,     0,     9,     0,     9
  };

  const short
  parser::yycheck_[] =
  {
       4,     3,     6,    14,    11,     3,     4,    56,    23,    14,
      11,    15,    53,    20,    29,    19,     7,    21,     3,     4,
       8,    25,     3,     4,     9,    10,    67,    29,    32,    17,
      41,    29,     3,     4,    19,    39,    41,    22,    17,    43,
      11,    45,    46,    41,    29,    94,    50,    15,    29,    53,
       0,    19,    56,     7,    95,    25,    29,    61,    29,    19,
      66,    40,    19,    67,    70,    71,    17,    73,    74,    39,
     111,   112,    76,    79,    11,    17,    46,    12,    84,    83,
      31,    32,    33,    34,    35,    36,     0,    38,    39,    40,
      94,    95,    18,     7,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   145,     6,   110,   111,   112,    14,
      28,   117,    17,    13,   120,     5,    19,    16,    16,    14,
      17,    17,    41,    16,    18,    30,    31,    32,    33,    34,
      35,    36,   138,    38,    39,    40,    15,    16,   144,    35,
      36,   145,    38,    39,    40,    24,    25,    26,    27,   155,
      29,    16,   158,     3,     4,    16,    19,    19,    37,     9,
      10,    17,    41,    16,    28,    20,     8,     3,     4,    19,
      41,    21,    22,     9,    10,    20,    16,    20,     7,    29,
      47,    20,    17,    19,    42,    21,    22,    76,    -1,    27,
      -1,    -1,    -1,    29,    17,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    30,    31,    32,
      33,    34,    35,    36,    17,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    30,
      31,    32,    33,    34,    35,    36,    17,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    17,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      17,    18,    33,    34,    35,    36,    -1,    38,    39,    40,
      -1,    17,    18,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    30,    31,    32,    33,    34,    35,
      36,    17,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    17,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    17,    18,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    -1,    30,    31,
      32,    33,    34,    35,    36,    17,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    17,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    15,    16,    -1,    -1,    -1,     9,    10,     9,    10,
      24,    25,    26,    27,    -1,    29,    19,    20,    19,    22,
      -1,    22,    -1,    37,    -1,    -1,    29,    -1,    29
  };

  const signed char
  parser::yystos_[] =
  {
       0,    11,    44,    46,     7,     0,     7,    45,    47,    29,
      63,    63,     0,    47,    19,    19,    11,     3,     4,    48,
      49,    57,    63,    12,    17,    11,    49,    53,    54,    63,
       6,    18,    57,    20,    54,    28,    13,    63,    16,    16,
       5,    41,    52,    57,    17,    19,    14,    50,    51,    63,
      18,     9,    10,    19,    22,    49,    55,    56,    58,    60,
      63,    57,    41,    51,    63,    16,    16,    59,    60,    63,
      16,    21,    56,     8,    17,    63,    19,    41,    15,    16,
      24,    25,    26,    27,    37,    62,    63,    62,    20,    60,
      62,    62,    62,    62,    55,    19,    62,     3,    63,    62,
      17,    30,    31,    32,    33,    34,    35,    36,    38,    39,
      40,    41,    41,    41,    28,    28,    18,    21,    60,    41,
      17,    16,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    23,    63,    60,    60,    28,    20,     8,    62,
      20,    62,    41,    18,    16,    42,    62,    28,    20,    18,
      41,    62,    60,    28,    20,    14,    61,    62,    14,    41,
      62
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    45,    46,    47,    48,    48,
      48,    49,    50,    50,    50,    51,    52,    53,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     0,     1,     2,    18,     6,     0,     1,
       2,     3,     0,     1,     2,     3,     2,     0,     1,     2,
      11,    13,     0,     1,     2,     1,     1,     3,     1,     1,
       1,     5,     7,     0,     1,     2,     3,     1,     5,     5,
       4,     7,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     7,     5,     1,     1,
       1,     1,     1,     5,     4,     2,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INT", "BOOLEAN",
  "STRING", "VOID", "CLASS", "EQUAL", "IF", "WHILE", "PUBLIC", "STATIC",
  "MAIN", "COMMA", "NUMBER", "LP", "LB", "RB", "LCB", "RCB", "RETURN",
  "PRINTLN", "LENGTH", "TRUE", "FALSE", "THIS", "NEW", "SEMICOLON", "ID",
  "OR", "AND", "EQUALEQUAL", "LESSTHAN", "MORETHAN", "PLUSOP", "MINUSOP",
  "NOT", "MULTOP", "DIVOP", "DOT", "RP", "ELSE", "$accept", "goal",
  "classList", "mainClass", "classDeclaration", "varDeclarationList",
  "varDeclaration", "argumentList", "argument", "arg",
  "methodDeclarationList", "methodDeclaration", "methodBodyList",
  "methodBody", "type", "ifStatement", "statementList", "statement",
  "expressionListComma", "expression", "identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    63,    63,    73,    77,    82,    90,   100,   110,   114,
     119,   127,   136,   140,   145,   151,   158,   167,   171,   176,
     183,   191,   205,   209,   213,   219,   224,   232,   237,   241,
     245,   252,   258,   267,   271,   276,   284,   289,   293,   299,
     304,   310,   321,   325,   331,   338,   344,   350,   356,   362,
     368,   374,   380,   386,   392,   398,   403,   411,   417,   421,
     425,   429,   433,   437,   442,   447,   452,   460
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2068 "parser.tab.cc"

