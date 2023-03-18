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
    for(auto& c: this->cfg_classes)
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
}

void IR::setup(Node *node)
{
    if(node->type == CLASS_DECLARATION)
    {
        this->cfg_classes.push_back(CFG_class(node->children[0]->value));
        this->fillClass(node, node->children[0]->value);
    }
    else if(node->type == MAIN_CLASS)
    {
        this->cfg_classes.push_back(CFG_class(node->children[0]->value));
        this->cfg_classes.at(this->cfg_classes.size()-1).methods.push_back(CFG_method("main", node->children[0]->value, node, new BBlock("block"+std::to_string(this->blockID++))));
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
    for(auto& c: this->cfg_classes)
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
    Ret* ret = new Ret("", block, node);

    //std::cout<<"Node: "<<node->type<<" "<<node->value<<std::endl;

    if(node->type == IF_ELSE_STATEMENT)
    {

    }
    else if(node->type == WHILE_STATEMENT)
    {

    }
    else if(node->type == EQUAL_STATEMENT)
    {

    }
    else if(node->type == EQUAL_ARR_STATEMENT)
    {

    }
    else if(node->type == PRINTLN_STATEMENT)
    {

    }
    else if(node->type == EXPRESSION_X || node->type == EXPRESSION_X2)
    {

    }
    else if(node->type == EXPRESSION_OP)
    {

    }
    else if(node->type == EXPRESSION_ARR)
    {

    }
    else if(node->type == NOT_EXPRESSION)
    {

    }
    else if(node->type == EXPRESSION_LEN)
    {
        //Traverse for expression
        Ret* exp = this->traverseTree(node->children[0], block);
        //Create new variable
        Variable* var = new Variable(INT, std::string("var"+getID()));
        this->st->put(var->id, var);
        this->currentMethod->addVariable(var);

        block->tacs.push_back(new Length(var->id, exp->name));

        ret->name = var->id;
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
        std::string exp = this->traverseTree(node->children[0], block)->name;
        block->tacs.push_back(new Return(exp));
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
    for(auto& c: this->cfg_classes)
    {
        if(className == c.name)
        {
            return &c;
        }
    }
    return nullptr;
}
