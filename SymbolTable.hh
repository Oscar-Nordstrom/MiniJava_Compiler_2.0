#pragma once

#include "Node.h"
#include "Scope.hh"
#include "Records.hh"
#include "spec.hh"
#include "ErrorHandler.hh"

#include <vector>
#include <string>


class SymbolTable
{
public:
    SymbolTable(ErrorHandler* eh);
    void createSymbolTable(Node* root);
    void printTable();
    void reset();
    void enterScope();
    void exitScope();
    Record* lookup(std::string key);
    bool put(std::string key, Record* rec);
private:
    void printIndents(int indents);
    void traverseAST(Node* node);
private:
    Scope* root;
    Scope* currentScope;
    Program* program;
    ErrorHandler* eh;
};