#pragma once

#include <string>

enum class TacType
{
    Expression,
    UnaryExpression,
    Copy,
    ArrayAccessFrom,
    ArrayAccessTo,
    New,
    NewArray,
    Length,
    PrintLn,
    Param,
    MethodCall,
    Return,
    UnconditionalJump,
    ConditionalJump,
    Default
};

class Tac
{
public:
    Tac(std::string result,std::string lhs,std::string op,std::string rhs);
    std::string result, lhs, op, rhs;
    TacType type;
    virtual std::string getTAC();
    //virtual std::vector<ByteCode> getByteCode();

};

class Expression: public Tac
{
public:
    Expression(std::string result, std::string lhs, std::string op, std::string rhs);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class UnaryExpression: public Tac
{
public:
    UnaryExpression(std::string result, std::string op, std::string rhs);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class Copy: public Tac
{
public:
    Copy(std::string result, std::string lhs);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class ArrayAccess: public Tac
{
public:
    ArrayAccess(std::string result, std::string lhs);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class New: public Tac
{
public:
    New(std::string result, std::string type);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class NewArray: public Tac
{
public:
    NewArray(std::string result, std::string type, std::string size);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class Length: public Tac
{
public:
    Length(std::string result, std::string lhs);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class PrintLn: public Tac
{
public:
    PrintLn(std::string toPrint);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class Param: public Tac
{
public:
    Param(std::string param);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class MethodCall: public Tac
{
public:
    MethodCall(std::string result, std::string function, std::string numParams);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
    std::string className;
};

class Return: public Tac
{
public:
    Return(std::string ret);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class Jump: public Tac
{
public:
    Jump(std::string goTO);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};

class ConditionalJump: public Tac
{
public:
    ConditionalJump(std::string iffalse, std::string goTO);
    std::string getTAC() override;
    //std::vector<ByteCode> getByteCode() override;
};