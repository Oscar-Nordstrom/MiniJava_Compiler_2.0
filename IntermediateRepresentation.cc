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
        //Enter class scope
        this->st->enterScope();

        for(auto& m: c.methods)
        {
            this->traverseTree(m.rootNode);
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
    for(auto& c: node->children)
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

    //Check statements and expressions

    return ret;
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
