#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>





class Record
{
public:
    Record(std::string id = "Empty", std::string type = "Empty");
    std::string id;
    std::string type;
    //Getters/setters
    void printRecord();
};

class Variable : public Record
{
public:
    Variable(std::string id = "Empty", std::string type = "Empty");
};

struct StrVar
{
    std::string id;
    Variable* var;
};

class Method: public Record
{
public:
    Method(std::string id = "Empty", std::string type = "Empty");
    bool addVariable(Variable* variable);
    bool addParameter(Variable* parameter);
    Variable* lookupVar(std::string id);
    Variable* lookupParam(std::string id);
    std::vector<StrVar> variables;
    std::vector<StrVar> parameters;
private:
    bool canAddVar(Variable* variable);
    bool canAddParam(Variable* parameter);
};

struct StrMeth
{
    std::string id;
    Method* meth;
};

class Class: public Record
{
public:
    Class(std::string id = "Empty", std::string type = "Empty");
    bool addVariable(Variable* variable);
    bool addMethod(Method* method);
    Variable* lookupVar(std::string id);
    Method* lookupMethod(std::string id);
    std::vector<StrVar> variables;
    std::vector<StrMeth> methods;
private:
    bool canAddVar(Variable* variable);
    bool canAddMethod(Method* method);
};

struct StrCls
{
    std::string id;
    Class* cls;
};

class Program: public Record
{
public:
    Program(std::string id = "Empty", std::string type = "Empty");
    bool addClass(Class* cls);
    Class* lookupClass(std::string id);
    std::vector<StrCls> classes;
private:
    bool canAddClass(Class* cls);
};