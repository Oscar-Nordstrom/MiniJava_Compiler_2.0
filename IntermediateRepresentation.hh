#pragma once

#include <string>
#include <vector>

#include "SymbolTable.hh"
#include "BBlock.hh"
#include "spec.hh"

struct Ret
{
    Ret(std::string name, BBlock* block, Node* node)
        :name(name), block(block), node(node)
    {

    }
    Ret(std::string name)
        :name(name), block(nullptr), node(nullptr)
    {

    }
    Ret()
        :name(""), block(nullptr), node(nullptr)
    {

    }
    std::string name;
    BBlock* block;
    Node* node;
};

struct CFG_method
{
    CFG_method(std::string name, std::string className, Node* node, BBlock *block)
    {
        this->name = name;
        this->className = className;
    }
    std::string name;
    std::string className;
    BBlock *rootBlock;
    Node* rootNode;
};

struct CFG_class
{
    CFG_class(std::string name)
    {
        this->name = name;
    }
    std::string name;
    std::vector<CFG_method> methods;
};

class IR
{
public:
    IR(SymbolTable *st);
    // Run setup. Fill each method by traversing ast
    void createCFG(Node *root);
    void printCFG();

private:
    // Fill cfg_classes vector with all calsses, and all calsses with methods
    void setup(Node *node);
    void fillClass(Node *node, std::string className);
    void printClasses();
    Ret* traverseTree(Node *node, BBlock* block);
    SymbolTable *st;
    int blockID;
    std::vector<CFG_class> cfg_classes;
    CFG_class* getCfgClass(std::string className);
};