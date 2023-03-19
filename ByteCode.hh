#pragma once

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>


#include "TacTranslator.hh"
#include "Records.hh"


class ByteCodeInstruction
{
public:
    ByteCodeInstruction();
    std::string name;
    std::vector<Bytecode> arguments;
    void setData(std::string data);
    std::string getData();
private:
    std::string data;
};

class ByteCodeMethod
{
public:
    ByteCodeMethod();
    std::vector<Variable*> vars;
    std::vector<ByteCodeInstruction> instructions;
    void setData(std::string data);
    std::string getData();
    std::string data;
private:
};

class ByteCodeProgram
{
public:
    ByteCodeProgram();
    std::unordered_map<std::string, ByteCodeMethod*> methods;
    std::vector<ByteCodeMethod> methodsVec;
    void setData(std::string data);
    std::string getData();
private:
    std::string data;
};