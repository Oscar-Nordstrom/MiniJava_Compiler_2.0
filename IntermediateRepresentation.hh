#pragma once

#include <string>
#include <vector>

#include "SymbolTable.hh"
#include "BBlock.hh"

struct CFG_method
{
    std::string name;
    std::string className;
    BBlock* rootBlock;
};

struct CFG_class
{
    std::string name;
    std::vector<CFG_method> methods;
};



class IR
{
public:
    IR(SymbolTable* st);
    //Run setup. Fill each method by traversing ast
    void createCFG(Node* root);
    void printCFG();
private:
    //Fill cfg_classes vector with all calsses, and all calsses with methods
    void setup(Node* root);
    void traverseTree(Node* node);

    std::vector<CFG_class> cfg_classes;
    
};