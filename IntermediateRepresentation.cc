#include "IntermediateRepresentation.hh"

IR::IR(SymbolTable *st)
    :st(st)
{
    this->blockID = 0;
}

void IR::createCFG(Node *root)
{
    this->setup(root);
    this->st->reset();
    //Eneter program scope
    this->st->enterScope();
    for(auto& c: this->program.cfg_classes)
    {
        //Set current class
        this->currentClass = (Class*)this->st->lookup(c.name);

        //Enter class scope
        this->st->enterScope();

        for(auto& m: c.methods)
        {
            //Set current method
            this->currentMethod = this->currentClass->lookupMethod(m.name);
            //Enter method scope
            this->st->enterScope();
            //Traverse tree for current method
            this->traverseTree(m.rootNode, m.rootBlock);
            //Exit method scope
            this->st->exitScope();

        }

        //Exir class scope
        this->st->exitScope();
    }
    //Exit program scope
    this->st->exitScope();
}

void IR::printCFG()
{
    std::ofstream file;
    file.open("CFGs.dot");
    if(!file.is_open())
    {
        std::cout<<"Could not create file: CFGs.dot\n";
        return;
    }

    file << "digraph {"<<std::endl;
    file << "\tgraph [splines=ortho];"<<std::endl;
    file << "\tnode [shape=box];"<<std::endl;


    for(auto& c: this->program.cfg_classes)
    {
        file << "subgraph cluster_" << c.name << " {" << std::endl; 
        file << "label = \""<< c.name <<"\";" << std::endl;  
        for(auto& m: c.methods)
        {
           this->printMethod(m, file);
        }
        file << "}" << std::endl; 
    }

    file <<"}";
    file.close();
}

CFG_program *IR::getProg()
{
    return &this->program;
}

void IR::setup(Node *node)
{
    if(node->type == CLASS_DECLARATION)
    {
        this->program.cfg_classes.push_back(CFG_class(node->children[0]->value));
        this->fillClass(node, node->children[0]->value);
    }
    else if(node->type == MAIN_CLASS)
    {
        this->program.cfg_classes.push_back(CFG_class(node->children[0]->value));
        this->program.cfg_classes.at(this->program.cfg_classes.size()-1).methods.push_back(CFG_method("main", node->children[0]->value, node, new BBlock("block"+std::to_string(this->blockID++))));
    }
    for(auto c: node->children)
    {
        this->setup(c);
    }
}

void IR::fillClass(Node *node, std::string className)
{
    if(node->type == METHOD_DECLARATION || node->type == METHOD_DECLARATION_ARGUMENTS)
    {
        getCfgClass(className)->methods.push_back(CFG_method(node->children[1]->value, className, node, new BBlock("block"+std::to_string(this->blockID++))));
    }
    for(auto c: node->children)
    {
        this->fillClass(c, className);
    }
}

void IR::printClasses()
{
    std::cout<<"Printing classes:\n";
    for(auto& c: this->program.cfg_classes)
    {
        std::cout<<"Class: "<<c.name<<std::endl;
        for(auto& m: c.methods)
        {
            std::cout<<"\tMethod: "<<m.name<<std::endl;
        }
    }
}

Ret* IR::traverseTree(Node *node, BBlock* block)
{
    Ret* ret = new Ret("", block);

    //std::cout<<"Node: "<<node->type<<" "<<node->value<<std::endl;

    if(node->type == IF_ELSE_STATEMENT)
    {
        //Create new blocks
        BBlock* newTrueBlock   = new BBlock("trueBlock"+getID());
        BBlock* newFalseBlock  = new BBlock("falseBlock"+getID());
        BBlock* newJoinBlock   = new BBlock("joinBlock"+getID());

        //Connect current block to true and false blocks
        block->trueExit = newTrueBlock;
        block->falseExit = newFalseBlock;

        //Traverse true and false block to handle nested statements
        Ret* t = this->traverseTree(node->children[1], newTrueBlock);
        Ret* f = this->traverseTree(node->children[2], newFalseBlock);

        //Set true and false blocks true exit
        t->block->trueExit = newJoinBlock;
        f->block->trueExit = newJoinBlock;

        //Get if expression
        std::string ifExpressionName = this->traverseTree(node->children[0], block)->name;
        //Add three address code instructions
        block->tacs.push_back(new ConditionalJump(ifExpressionName, newFalseBlock->name));
        t->block->tacs.push_back(new Jump(newJoinBlock->name));
        f->block->tacs.push_back(new Jump(newJoinBlock->name));

        //Set return to join block
        ret->block = newJoinBlock;
        ret->name = newJoinBlock->name;

    }
    else if(node->type == WHILE_STATEMENT)
    {
        //Create new blocks
        BBlock* newWhileBlock = new BBlock("whileBlock"+getID());
        BBlock* newTrueExit = new BBlock("trueExit"+getID());
        BBlock* newFalseExit = new BBlock("falseExit"+getID());

        //Connect current block
        block->trueExit = newWhileBlock;

        //Connect true and false block
        newWhileBlock->trueExit = newTrueExit;
        newWhileBlock->falseExit = newFalseExit;

        //Traverse statement to get the block that connects back to the while block
        BBlock* trueJoinBlock = this->traverseTree(node->children[1], newTrueExit)->block;
        //Connect block to while block
        trueJoinBlock->trueExit = newWhileBlock;

        //Get expression name
        std::string expressionName = this->traverseTree(node->children[0], newWhileBlock)->name;

        //Add three address code instructions
        newWhileBlock->tacs.push_back(new ConditionalJump(expressionName, newFalseExit->name));
        trueJoinBlock->tacs.push_back(new Jump(newWhileBlock->name));

        //Set ret to false block
        ret->block = newFalseExit;
        ret->name = newFalseExit->name;
    }
    else if(node->type == EQUAL_STATEMENT)
    {
        //Get identifiers
        std::string identifier = node->children[0]->value;
        std::string equalExpression = this->traverseTree(node->children[1], block)->name;
        //Add three address code instruction
        block->tacs.push_back(new Copy(identifier, equalExpression));
    }
    else if(node->type == EQUAL_ARR_STATEMENT)
    {
        //Get all identifiers
        std::string identifier = node->children[0]->value;
        std::string bracketExpression = this->traverseTree(node->children[1], block)->name;
        std::string equalExpression = this->traverseTree(node->children[2], block)->name;
        //Add three addres code instruction
        block->tacs.push_back(new ArrayAccess(identifier+"[" + bracketExpression + "]", equalExpression));
    }
    else if(node->type == IDENTIFIER)
    {
        ret->name = node->value;
    }
    else if(node->type == THIS)
    {
        ret->name = "this";
    }
    else if(node->type == PRINTLN_STATEMENT)
    {
        std::string expressionName = this->traverseTree(node->children[0], block)->name;
        block->tacs.push_back(new PrintLn(expressionName));
    }
    else if(node->type == EXPRESSION_X || node->type == EXPRESSION_X2)
    {
        //Get name of expression
        std::string targetExpressionName = this->traverseTree(node->children[0], block)->name;
        //Store parameter for target
        block->tacs.push_back(new Param(targetExpressionName));
        //Store number of parameters
        int numParams = 1;
        //Store rest of parameters (only expression_x has parameters)
        if(node->type == EXPRESSION_X )
        {
            //Store parameter for first paramater
            std::string par1Name = this->traverseTree(node->children[2], block)->name;
            block->tacs.push_back(new Param(par1Name));
            //Add number of params
            numParams++;
            //Traverse rest of parameters and store each one
            std::string parxName;
            for(auto c: node->children[3]->children)
            {
                parxName = this->traverseTree(c, block)->name;
                block->tacs.push_back(new Param(parxName));
                //Add number of params
                numParams++;
            }

        }
         
        //Get class
        Record* recClass = this->st->lookup(targetExpressionName);
        Class* cls;
        if(recClass->type == CLASS)
            cls = this->st->program->lookupClass(recClass->id);
        else
            cls = this->st->program->lookupClass(recClass->type);
        //Get the method name
        std::string methodName = node->children[1]->value;
        //Get method
        Method* meth = cls->lookupMethod(methodName);
        //Create new variable for result
        Variable* res = new Variable("var"+getID(), meth->type);
        //insert new variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add three address code instruction
        block->tacs.push_back(new MethodCall(res->id, methodName, std::to_string(numParams)));
        //Set return to result var name
        ret->name = res->id;
    }
    else if(node->type == EXPRESSION_OP)
    {
        //Get names of expressions
        std::string expressionName1 = this->traverseTree(node->children[0], block)->name;
        std::string expressionName2 = this->traverseTree(node->children[1], block)->name;

        //Get specific type and operator
        std::string type, op;
        this->handleExpressionOp(type, op, node->value);
        //Create new var for result
        Variable* res = new Variable("var"+getID(), type);
        //Insert new variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add three address code instruction
        block->tacs.push_back(new Expression(res->id, expressionName1, op, expressionName2));
        //Set return name to result var name
        ret->name = res->id;
    }
    else if(node->type == EXPRESSION_ARR)
    {
        //Get expression and index
        std::string expressionName = this->traverseTree(node->children[0], block)->name;
        std::string indexName = this->traverseTree(node->children[1], block)->name;
        //Create new var for result
        Variable* res = new Variable("var"+getID(), INT);
        //Insert new Variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add three address code instruction
        block->tacs.push_back(new ArrayAccess(res->id, expressionName+"["+indexName+"]"));
        //Set return name to result var name
        ret->name = res->id;

    }
    else if(node->type == NOT_EXPRESSION)
    {
        //Get name of expression
        std::string expressionName = this->traverseTree(node->children[0], block)->name;
        //Create new Variable for result
        Variable* res = new Variable("var"+getID(), BOOLEAN);
        //Insesrt new variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add Three address code
        block->tacs.push_back(new UnaryExpression(res->id,"!", expressionName));
        //Sert return name to result var name
        ret->name = res->id;

    }
    else if(node->type == EXPRESSION_LEN)
    {
        //Get expression name
        std::string expressionName = this->traverseTree(node->children[0], block)->name;
        //Create new variable for result
        Variable* res = new Variable(INT, std::string("var"+getID()));
        //Insert new variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add three address code instruction
        block->tacs.push_back(new Length(res->id, expressionName));
        //Set return name to the result var name
        ret->name = res->id;
    }
    else if(node->type == NEW_IDENTIFIER)
    {
        //Get type
        std::string type = node->children[0]->value;
        //Create new var for result
        Variable* res = new Variable("var"+getID(), type);
        //insert new variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add three address code
        block->tacs.push_back(new New(res->id, type));
        //Set return to name of result var
        ret->name = res->id;
    }
    else if(node->type == NEW_INT_ARR)
    {
        //Get expression insode brackets
        std::string expressionInBrackets = this->traverseTree(node->children[0], block)->name;
        //Create new variable for result
        Variable* res = new Variable("var"+getID(), INT_ARR);
        //Insert new variable
        this->st->put(res->id, res);
        this->currentMethod->addVariable(res);
        //Add three address code instructions
        block->tacs.push_back(new NewArray(res->id, INT_ARR, expressionInBrackets));
        //Set return name to result var name
        ret->name = res->id;
    }
    else if(node->type == MAIN_CLASS)
    {
        ret = this->traverseTree(node->children[2], block);
    }
    else if(node->type == METHOD_DECLARATION || node->type == METHOD_DECLARATION_ARGUMENTS)
    {
        //Set return expression of method call as return block
        if(node->type == METHOD_DECLARATION)
        {
            ret->block = this->traverseTree(node->children[3], block)->block;
        }
        else
        {
            ret->block = this->traverseTree(node->children[5], block)->block;
        }
        //Traverse children nodes
        for(auto n: node->children)
        {
            ret = this->traverseTree(n, ret->block);
        }
    }
    else if(node->type == RETURN_TYPE)
    {
        //Get expression name
        std::string expressionName = this->traverseTree(node->children[0], block)->name;
        //Add three address code
        block->tacs.push_back(new Return(expressionName));
    }
    else if(node->type == INT || node->type == BOOLEAN)
    {
        //Set $ in front of constant
        ret->name = "$"+node->value;
    }
    else
    {
        ret->block = block;
        for(auto c: node->children)
        {
            ret = this->traverseTree(c, ret->block);
        }
    }

    return ret;
}

std::string IR::getID()
{
    static int id = 0;
    return std::to_string(id++);
}

CFG_class *IR::getCfgClass(std::string className)
{
    for(auto& c: this->program.cfg_classes)
    {
        if(className == c.name)
        {
            return &c;
        }
    }
    return nullptr;
}

void IR::handleExpressionOp(std::string &type, std::string &op, std::string nodeVal)
{
    if(nodeVal == AND_EXPRESSION)
    {
        type = BOOLEAN;
        op = "&&";
    }
    else if(nodeVal == OR_EXPRESSION)
    {
        type = BOOLEAN;
        op = "||";
    }
    else if(nodeVal == LESS_THAN_EXPRESSION)
    {
        type = BOOLEAN;
        op = "<";
    }
    else if(nodeVal == MORE_THAN_EXPRESSION)
    {
        type = BOOLEAN;
        op = ">";
    }
    else if(nodeVal == PLUS_EXPRESSION)
    {
        type = INT;
        op = "+";
    }
    else if(nodeVal == MINUS_EXPRESSION)
    {
        type = INT;
        op = "-";
    }
    else if(nodeVal == MULT_EXPRESSION)
    {
        type = INT;
        op = "*";
    }
    else if(nodeVal == DIV_EXPRESSION)
    {
        type = INT;
        op = "/";
    }
    else if(nodeVal == EQUAL_EXPRESSION)
    {
        type = BOOLEAN;
        op = "==";
    }
}

void IR::printMethod(CFG_method& method, std::ofstream& file)
{
    file << "subgraph cluster_" << method.name << " {" << std::endl; 
    file << "label = \""<< method.name <<"\";" << std::endl;  
    this->printMethodContents(method.rootBlock, file);
    file << "}" << std::endl; 
}

void IR::printMethodContents(BBlock* block, std::ofstream& file)
{

    if(block->printed)
    {
        return;
    }
    block->printed = true;

    file <<block->name<<"[label=\""<<block->name<<std::endl;

    for(auto& t: block->tacs)
    {
        file<<t->getTAC()<<std::endl;
    }

    file << "\"];"<<std::endl;



    if(block->trueExit != nullptr)
    {
        this->printMethodContents(block->trueExit, file);
        file << block->name << "->"  << block->trueExit->name << "[label=\"true\"];";
    }
    if(block->falseExit != nullptr)
    {
        this->printMethodContents(block->falseExit, file);
        file << block->name << "->"  << block->falseExit->name << "[label=\"false\"];";
    }
}
