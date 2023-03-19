#include "ThreeAddressCode.hh"

Tac::Tac(std::string result, std::string lhs, std::string op, std::string rhs)
    :result(result), lhs(lhs), op(op), rhs(rhs)
{
    this->type = TacType::Default;
}

std::string Tac::getTAC()
{
    return std::string();
}

Expression::Expression(std::string result, std::string lhs, std::string op, std::string rhs)
    :Tac(result, lhs, op, rhs)
{
    this->type = TacType::Expression;
}

std::string Expression::getTAC()
{
    std::string retTac = result + " := " + lhs + " " + op + " " + rhs;
    return retTac;
}

UnaryExpression::UnaryExpression(std::string result, std::string op, std::string rhs)
    :Tac(result, "", op, rhs)
{
    this->type = TacType::UnaryExpression;
}

std::string UnaryExpression::getTAC()
{
    std::string retTac = result + " := " + op + " " + rhs;
    return retTac;
}

Copy::Copy(std::string result, std::string lhs)
    :Tac(result, lhs, "", "")
{
    this->type = TacType::Copy;
}

std::string Copy::getTAC()
{
    std::string retTac = result + " := " + lhs;
    return retTac;
}

ArrayAccess::ArrayAccess(std::string result, std::string lhs)
    :Tac(result, lhs, "", "")
{
    this->type = TacType::ArrayAccess;
}

std::string ArrayAccess::getTAC()
{
    std::string retTac = result + " := " + lhs;
    return retTac;
}

New::New(std::string result, std::string type)
    :Tac(result, type, "", "")
{
    this->type = TacType::New;
}

std::string New::getTAC()
{
    std::string retTac = result + " := new " + lhs;
    return retTac;
}

NewArray::NewArray(std::string result, std::string type, std::string size)
    :Tac(result, type, size, "")
{
    this->type = TacType::NewArray;
}

std::string NewArray::getTAC()
{
    std::string retTac = result + " := new " + lhs + ", " + op;
    return retTac;
}

Length::Length(std::string result, std::string lhs)
    :Tac(result, lhs, "", "")
{
    this->type = TacType::Length;
}

std::string Length::getTAC()
{
    std::string retTac = result + " := length " + lhs;
    return retTac;
}

PrintLn::PrintLn(std::string toPrint)
    :Tac(toPrint, "", "", "")
{
    this->type = TacType::PrintLn;
}

std::string PrintLn::getTAC()
{
    std::string retTac = "print " + result;
    return retTac;
}

Param::Param(std::string param)
    :Tac(param, "", "", "")
{
    this->type = TacType::Param;
}

std::string Param::getTAC()
{
    std::string retTac = "param " + result;
    return retTac;
}

MethodCall::MethodCall(std::string result, std::string function, std::string numParams)
    :Tac(result, function, numParams, "")
{
    this->type = TacType::MethodCall;
}

std::string MethodCall::getTAC()
{
    std::string retTac = result + " := call " + lhs + ", " + op;
    return retTac;
}

Return::Return(std::string ret)
    :Tac(ret, "", "", "")
{
    this->type = TacType::Return;
}

std::string Return::getTAC()
{
    std::string retTac = "return " + result;
    return retTac;
}

Jump::Jump(std::string goTO)
    :Tac(goTO, "", "", "")
{
    this->type = TacType::Jump;
}

std::string Jump::getTAC()
{
    std::string retTac = "goto " + result;
    return retTac;
}

ConditionalJump::ConditionalJump(std::string iffalse, std::string goTO)
    :Tac(iffalse, goTO, "", "")
{
    this->type = TacType::ConditionalJump;
}

std::string ConditionalJump::getTAC()
{
    std::string retTac = "iffalse " + result + " goto " + lhs;
    return retTac;
}
