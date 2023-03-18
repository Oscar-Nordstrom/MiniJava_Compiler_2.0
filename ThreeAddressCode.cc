#include "ThreeAddressCode.hh"

Tac::Tac(std::string result, std::string lhs, std::string op, std::string rhs)
    :result(result), lhs(lhs), op(op), rhs(rhs)
{
}

std::string Tac::getTAC()
{
    return std::string();
}

Expression::Expression(std::string result, std::string lhs, std::string op, std::string rhs)
    :Tac(result, lhs, op, rhs)
{
}

std::string Expression::getTAC()
{
    std::string retTac = result + " := " + lhs + " " + op + " " + rhs;
    return retTac;
}

UnaryExpression::UnaryExpression(std::string result, std::string op, std::string rhs)
    :Tac(result, "", op, rhs)
{
}

std::string UnaryExpression::getTAC()
{
    std::string retTac = result + " := " + op + " " + rhs;
    return retTac;
}

Copy::Copy(std::string result, std::string lhs)
    :Tac(result, lhs, "", "")
{
}

std::string Copy::getTAC()
{
    std::string retTac = result + " := " + lhs;
    return retTac;
}

ArrayAccess::ArrayAccess(std::string result, std::string lhs)
    :Tac(result, lhs, "", "")
{
}

std::string ArrayAccess::getTAC()
{
    std::string retTac = result + " := " + lhs;
    return retTac;
}

New::New(std::string result, std::string type)
    :Tac(result, type, "", "")
{
}

std::string New::getTAC()
{
    std::string retTac = result + " := new " + lhs;
    return retTac;
}

NewArray::NewArray(std::string result, std::string type, std::string size)
    :Tac(result, type, size, "")
{
}

std::string NewArray::getTAC()
{
    std::string retTac = result + " := new " + lhs + ", " + op;
    return retTac;
}

Length::Length(std::string result, std::string lhs)
    :Tac(result, lhs, "", "")
{
}

std::string Length::getTAC()
{
    std::string retTac = result + " := length " + lhs;
    return retTac;
}

PrintLn::PrintLn(std::string toPrint)
    :Tac(toPrint, "", "", "")
{
}

std::string PrintLn::getTAC()
{
    std::string retTac = "print " + result;
    return retTac;
}

Param::Param(std::string param)
    :Tac(param, "", "", "")
{
}

std::string Param::getTAC()
{
    std::string retTac = "param " + result;
    return retTac;
}

MethodCall::MethodCall(std::string result, std::string function, std::string numParams)
    :Tac(result, function, numParams, "")
{
}

std::string MethodCall::getTAC()
{
    std::string retTac = result + " := call " + lhs + ", " + op;
    return retTac;
}

Return::Return(std::string ret)
    :Tac(ret, "", "", "")
{
}

std::string Return::getTAC()
{
    std::string retTac = "return " + result;
    return retTac;
}

Jump::Jump(std::string goTO)
    :Tac(goTO, "", "", "")
{
}

std::string Jump::getTAC()
{
    std::string retTac = "goto " + result;
    return retTac;
}

ConditionalJump::ConditionalJump(std::string iffalse, std::string goTO)
    :Tac(iffalse, goTO, "", "")
{
}

std::string ConditionalJump::getTAC()
{
    std::string retTac = "iffalse " + result + " goto " + lhs;
    return retTac;
}
