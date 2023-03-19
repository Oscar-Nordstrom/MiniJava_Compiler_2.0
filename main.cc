#include<iostream>
#include <vector>
#include "parser.tab.hh"
#include "SymbolTable.hh"
#include "SymanticAnalyzer.hh"
#include "ErrorHandler.hh"
#include "IntermediateRepresentation.hh"

extern Node* root;
extern FILE* yyin;
extern int yylineno;
extern int lexical_errors;

enum errCodes
{
    SUCCESS         = 0,
    FAILED_GRAMMAR  = 1,
    FAILED_TREE     = 2,
    FAILED_SEMANTIC = 3,
    SEGMENT_FAULT   = 139 
};

int errCode = errCodes::SUCCESS;

void yy::parser::error(std::string const&err)
{ 
  printf("Syntax errors found! See the logs below: \n");
  fprintf(stderr, "@error at line %d. Cannot generate a syntax for this input: %s\n", yylineno, err.c_str()); 
  errCode = errCodes::FAILED_GRAMMAR;
}


int main(int argc, char **argv)
{
  //Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if(argc > 1) {
    if(!(yyin = fopen(argv[1], "r"))) {
      perror(argv[1]);
      errCode = errCodes::FAILED_GRAMMAR;
      return errCode;
    }
  }

  yy::parser parser;
  ErrorHandler eh;
  SymbolTable st(&eh);
  SymanticAnalyzer sa(&st, &eh);
  IR ir(&st);

  if(!parser.parse() && !lexical_errors) {

    printf("\nThe compiler successfuly generated a syntax tree for the given input! \n");

    if(PRINT_AST)
    {
      printf("\nPrint Tree:  \n");
      root->print_tree();
    }
    root->generate_tree();
    std::cout<<std::endl;
    st.createSymbolTable(root);


    if(PRINT_ST)
    {
      st.printTable();
    }
    sa.analyzeAst(root);
    if(eh.hasErrors())
    {
      errCode = FAILED_SEMANTIC;
      eh.printErrors();
    }
    else
    {
      ir.createCFG(root);
      ir.printCFG();
    }
  }
  else
  {
    if (errCode == errCodes::SUCCESS)
    {
      errCode = errCodes::FAILED_TREE;
    }
  }

  
  return errCode;
}