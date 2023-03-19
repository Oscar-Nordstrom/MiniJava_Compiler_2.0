#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "SymbolTable.hh"
#include "BBlock.hh"
#include "spec.hh"

struct Ret
{
    Ret(std::string name, BBlock* block)
        :name(name), block(block)
    {

    }
    Ret(std::string name)
        :name(name), block(nullptr)
    {

    }
    Ret()
        :name(""), block(nullptr)
    {

    }
    std::string name;
    BBlock* block;
};

struct CFG_method
{
    CFG_method(std::string name, std::string className, Node* node, BBlock *block)
    {
        this->name = name;
        this->className = className;
        this->rootBlock = block;
        this->rootNode = node;
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

struct CFG_program
{
    std::vector<CFG_class> cfg_classes;
};

class IR
{
public:
    IR(SymbolTable *st);
    // Run setup. Fill each method by traversing ast
    void createCFG(Node *root);
    void printCFG();
    CFG_program* getProg();
private:
    // Fill cfg_classes vector with all calsses, and all calsses with methods
    void setup(Node *node);
    void fillClass(Node *node, std::string className);
    void printClasses();
    Ret* traverseTree(Node *node, BBlock* block);
    std::string getID();
    CFG_class* getCfgClass(std::string className);
    void handleExpressionOp(std::string& type, std::string& op, std::string nodeVal);

    void printMethod(CFG_method& method, std::ofstream& file);
    void printMethodContents(BBlock* block, std::ofstream& file);
private:
    int blockID;
    SymbolTable *st;
    Class* currentClass;
    Method* currentMethod;
    CFG_program program;
};