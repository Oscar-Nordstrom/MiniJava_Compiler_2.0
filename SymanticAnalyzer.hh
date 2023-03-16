#pragma once

#include "Node.h"
#include "SymbolTable.hh"
#include "ErrorHandler.hh"

#include <string>
#include <iostream>

class SymanticAnalyzer
{
public:
    SymanticAnalyzer(SymbolTable* st, ErrorHandler* eh);
    void analyzeAst(Node* root);
private:
    Node* traverseTree(Node* node);
    bool checkEnterScope(Node* node);
    bool checkMethodType(Node* n1, Node* n2);
    SymbolTable* st;
    ErrorHandler* eh;

    std::vector<Node*> nodeVec;
};