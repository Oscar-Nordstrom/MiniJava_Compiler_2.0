#include "TacTranslator.hh"

Bytecode::Bytecode()
    :type(InstructionType::nothing), what("")
{
}

Bytecode::Bytecode(InstructionType type, std::string what)
    :type(type), what(what)
{
}

std::string Bytecode::getString()
{
    std::string ret = "";
    switch (this->type)
    {
    case InstructionType::iload: 
        ret = "iload";
        break;
    case InstructionType::iconst: 
        ret = "iconst";
        break;
    case InstructionType::istore: 
        ret = "istore";
        break;
    case InstructionType::iadd: 
        ret = "iadd";
        break;
    case InstructionType::isub: 
        ret = "isub";
        break;
    case InstructionType::imul: 
        ret = "imul";
        break;
    case InstructionType::idiv: 
        ret = "idiv";
        break;
    case InstructionType::ilt: 
        ret = "ilt";
        break;
    case InstructionType::igt: 
        ret = "igt";
        break;
    case InstructionType::ieq: 
        ret = "ieq";
        break;
    case InstructionType::iand: 
        ret = "iand";
        break;
    case InstructionType::ior: 
        ret = "ior";
        break;
    case InstructionType::inot: 
        ret = "inot";
        break;
    case InstructionType::goto_i: 
        ret = "goto_i";
        break;
    case InstructionType::iffalse_goto_i: 
        ret = "iffalse_goto_i";
        break;
    case InstructionType::invokevirtual_m: 
        ret = "invokevirtual_m";
        break;
    case InstructionType::ireturn: 
        ret = "ireturn";
        break;
    case InstructionType::print: 
        ret = "print";
        break;
    case InstructionType::stop: 
        ret = "stop";
        break;
    case InstructionType::nothing: 
        ret = "nothing";
        break;
    }
    ret = ret + " " + this->what;
    return ret;
}

TacTranslator::TacTranslator()
{
}

std::vector<Bytecode> TacTranslator::translateTac(Tac* tac)
{
    std::vector<Bytecode> ret;
    switch (tac->type)
    {
    case TacType::Expression :
    {

        InstructionType LHS = determineType(tac->lhs);
        InstructionType OP  = determineOpType(tac->op);
        InstructionType RHS = determineType(tac->rhs);

        ret.push_back(Bytecode(LHS, tac->lhs));
        ret.push_back(Bytecode(RHS, tac->rhs));
        ret.push_back(Bytecode(OP, tac->op));
        ret.push_back(Bytecode(InstructionType::istore, tac->result));
        break;
    }
    case TacType::UnaryExpression :
    {
        InstructionType RHS = this->determineType(tac->rhs);
        ret.push_back(Bytecode(RHS, tac->rhs));
        ret.push_back(Bytecode(InstructionType::inot));
        ret.push_back(Bytecode(InstructionType::istore, tac->result));
        break;
    }   
    case TacType::Copy :
    {
        InstructionType LHS = this->determineType(tac->lhs);
        ret.push_back(Bytecode(LHS, tac->lhs));
        ret.push_back(Bytecode(InstructionType::istore, tac->result));
        break;
    }   
    case TacType::PrintLn :
    {
        InstructionType RESULT = this->determineType(tac->result);
        ret.push_back(Bytecode(RESULT, tac->result));
        ret.push_back(Bytecode(InstructionType::print));
        break;
    }  
    case TacType::Param :
    {
        InstructionType RES = this->determineType(tac->result);
        ret.push_back(Bytecode(RES, tac->result));
        break;
    }  
    case TacType::MethodCall :
    {
        ret.push_back(Bytecode(InstructionType::invokevirtual_m, ((MethodCall*)tac)->className+"."+tac->lhs));
        ret.push_back(Bytecode(InstructionType::istore, tac->result));
        break;
    }  
    case TacType::Return :
    {
        InstructionType RES = this->determineType(tac->result);
        ret.push_back(Bytecode(RES, tac->result));
        ret.push_back(Bytecode(InstructionType::ireturn));
        break;
    }  
    case TacType::Jump :
    {
        ret.push_back(Bytecode(InstructionType::goto_i, tac->result));
        break;
    }  
    case TacType::ConditionalJump :
    {
        InstructionType RESULT = this->determineType(tac->result);
        ret.push_back(Bytecode(RESULT, tac->result));
        ret.push_back(Bytecode(InstructionType::iffalse_goto_i, tac->op));
        break;
    }  
    }
    return ret;
}

InstructionType TacTranslator::determineType(std::string &what)
{
    InstructionType ret;
    if(what[0]=='$')
    {
        ret = InstructionType::iconst;
        what.erase(0,1);
    }
    else
    {
        ret = InstructionType::iload;
    }
    return ret;
}

InstructionType TacTranslator::determineOpType(std::string &op)
{
    InstructionType ret;
    if(op == "+")
    {
        ret = InstructionType::iadd;
    }
    else if(op == "-")
    {
        ret = InstructionType::isub;
    }
    else if(op == "*")
    {
        ret = InstructionType::imul;
    }
    else if(op == "/")
    {
        ret = InstructionType::idiv;
    }
    else if(op == "<")
    {
        ret = InstructionType::ilt;
    }
    else if(op == ">")
    {
        ret = InstructionType::igt;
    }
    else if(op == "||")
    {
        ret = InstructionType::ior;
    }
    else if(op == "&&")
    {
        ret = InstructionType::iand;
    }
    else if(op == "!")
    {
        ret = InstructionType::inot;
    }
    else if(op == "==")
    {
        ret = InstructionType::ieq;
    }
    return ret;
}
