#include "CodeGenerator.hh"

CodeGeneartor::CodeGeneartor(SymbolTable *st)
    :st(st)
{
}

void CodeGeneartor::generate(CFG_program *program)
{
    for(auto& c: program->cfg_classes)
    {
        for(auto& m: c.methods)
        {
            Method* met = this->st->lookupMethod(m.className, m.name);
            ByteCodeMethod method;
            method.instructions.push_back(ByteCodeInstruction());
            method.instructions.back().name = "parameters";
            method.setData(std::string(m.className+"."+m.name));


            for(auto p: met->parameters)
            {
                method.vars.push_back(p.var);
                method.instructions[0].arguments.insert(method.instructions[0].arguments.begin(), Bytecode(InstructionType::istore, p.var->id));
            }
            for(auto v: met->variables)
            {
                method.vars.push_back(v.var);
            }
            this->generateCode(m.rootBlock, m.className, m.name, method);
            this->prog.methods.insert({m.name, &method});
            this->prog.methodsVec.push_back(method);
        }
    }
}

void CodeGeneartor::printCode()
{
    for(auto m: this->prog.methodsVec)
    {
        std::cout<<"\n";
        std::cout<<m.data<<"\n";
        for(auto v: m.vars)
        {
            std::cout<<v->id<<std::endl;
        }
        for(auto i: m.instructions)
        {
            std::cout<<"\t"<<i.name<<std::endl;
            for(auto a: i.arguments)
            {
                std::cout<<"\t\t"<<a.getString()<<std::endl;
            }
        }
    }
}

void CodeGeneartor::writeToFile()
{
    std::ofstream file("byte_code.txt");
    if(!file.is_open())
    {
        std::cout<<"Could not create file\n";
        return;
    }

   
    file<<this->prog.methodsVec.size()<<std::endl;

    for(auto m: this->prog.methodsVec)
    {

        file<<m.data<<std::endl;

        file<<m.vars.size()<<std::endl;
        for(auto v: m.vars)
        {
            file<<v->type<<std::endl;
            file<<v->id<<std::endl;
        }
        file<<m.instructions.size()<<std::endl;
        for(auto i: m.instructions)
        {
            file<<i.name<<std::endl;
            file<<i.arguments.size()<<std::endl;
            for(auto a: i.arguments)
            {
                file<<getTypeString(a.type)<<std::endl;
                file<<a.what<<std::endl;
            }
        }
    }

    file.close();
}

void CodeGeneartor::generateCode(BBlock *block, std::string className, std::string methodName, ByteCodeMethod &method)
{
    if(block->visited)
    {
        return;
    }
    block->visited = true;

    method.instructions.push_back(ByteCodeInstruction());
    method.instructions.back().name = block->name;
    //std::cout<<"Pusing back instruction: "<< method.instructions.back().name<<std::endl;

    //Method* curMeth = this->st->lookupMethod(className, methodName);
    //std::stack<Param*> parameters;
    
    for(auto t: block->tacs)
    {
        // //Push parameter to a stack
        // if(t->type == TacType::Param)
        // {
        //     parameters.push((Param*)t);
        // }
        // //If we find a method call, then ew need to use the correct class name for the Tac
        // else if(t->type == TacType::MethodCall)
        // {
        //     //remove all but one parameter
        //     int numParams = std::stoi(t->rhs);
        //     for(int i = 0; i < numParams-1; i++)
        //     {
        //         parameters.pop();
        //     }
            
        //     std::string classToUse;

        //     //If the parameter was "this", use the current class
        //     if(parameters.top()->result == "this")
        //     {
        //         classToUse = className;
        //     }
        //     //If the parameter was not "this", use the type of the variable
        //     else
        //     {
        //         Variable* v1 = curMeth->lookupVar(parameters.top()->result);
        //         if(v1 == nullptr)
        //         {
        //             v1 = curMeth->lookupParam(parameters.top()->result);
        //         }
        //         classToUse = v1->type;
        //     }
        //     //Set the class name
        //     ((MethodCall*)t)->className = classToUse;
        //     //pop last parameter
        //     parameters.pop();
        // }
        //Get the bytecode
        std::vector<Bytecode> ret = this->translator.translateTac(t);
        for(auto c: ret)
        {
            //Push back all arguments
            method.instructions.back().arguments.push_back(c);
        }
    }
    
    //Gererate code for true and false block
    if(block->trueExit != nullptr)
    {
        this->generateCode(block->trueExit, className, methodName, method);
    }
    if(block->falseExit != nullptr)
    {
        this->generateCode(block->falseExit, className, methodName, method);
    }

    //If the method is main, push back a stop argument last
    if(methodName == "main")
    {
        method.instructions.back().arguments.push_back(Bytecode(InstructionType::stop));
    }
}

std::string CodeGeneartor::getTypeString(InstructionType type)
{
     std::string ret = "";
    switch (type)
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
    return ret;
}
