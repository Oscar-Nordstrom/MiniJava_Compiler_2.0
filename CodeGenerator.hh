#pragma once


#include <fstream>
#include <vector>

#include "SymbolTable.hh"
#include "ByteCode.hh"
#include "TacTranslator.hh"
#include "IntermediateRepresentation.hh"

class CodeGeneartor
{
public:
    CodeGeneartor(SymbolTable* st);
    void generate(CFG_program* program);
    void printCode();
    void writeToFile();
private:
    void generateCode(BBlock *block, std::string className, std::string methodName, ByteCodeMethod &method);
    std::string getTypeString(InstructionType type);
    TacTranslator translator;
    SymbolTable* st;
    ByteCodeProgram prog;
};