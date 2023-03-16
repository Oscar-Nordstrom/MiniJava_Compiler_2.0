#pragma once

#include "Node.h"
#include "Scope.hh"
#include "Records.hh"
#include "spec.hh"

#include <vector>
#include <string>


class SymbolTable
{
public:
    SymbolTable();
    void createSymbolTable(Node* root);
    void printTable();
private:
    void printIndents(int indents);
    void enterScope();
    void exitScope();
    bool put(std::string key, Record* rec);
    Record* lookup(std::string key);
    void traverseAST(Node* node);
private:
    Scope* root;
    Scope* currentScope;
    Program* program;
};