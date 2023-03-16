#include "SymbolTable.hh"

SymbolTable::SymbolTable()
{
    this->root = new Scope();
    this->currentScope = root;
    this->program = new Program("MiniJava_program", "Program");
    this->put(this->program->id, (Record*)this->program);
}

void SymbolTable::createSymbolTable(Node *root)
{
    this->enterScope();
    this->traverseAST(root);
    this->exitScope();
}

void SymbolTable::printTable()
{
    std::cout<<program->type<<" "<<program->id<<std::endl;
    printIndents(1);
    std::cout<<"Classes:\n";
    for(auto& c: program->classes)
    {
        printIndents(2);
        std::cout<<c.cls->type<<" "<<c.cls->id<<std::endl;
        printIndents(3);
        std::cout<<"Class Variables:\n";
        for(auto& v: c.cls->variables)
        {
            printIndents(4);
            std::cout<<v.var->type<<" "<<v.var->id<<std::endl;
        }
        printIndents(3);
        std::cout<<"Class Methods:\n";
        for(auto& m: c.cls->methods)
        {
            printIndents(4);
            std::cout<<m.meth->type<<" "<<m.meth->id<<std::endl;
            printIndents(5);
            std::cout<<"Method Parameters:\n";
            for(auto& p: m.meth->parameters)
            {
                printIndents(6);
                std::cout<<p.var->type<<" "<<p.var->id<<std::endl;
            }
            printIndents(5);
            std::cout<<"Method Variables:\n";
            for(auto& v: m.meth->variables)
            {
                printIndents(6);
                std::cout<<v.var->type<<" "<<v.var->id<<std::endl;
            }
        }
    }
}

void SymbolTable::printIndents(int indents)
{
    for(int i = 0; i < indents; i++)
    {
        std::cout<<"\t";
    }
}

void SymbolTable::enterScope()
{
    this->currentScope = this->currentScope->NextChild();
}

void SymbolTable::exitScope()
{
    this->currentScope = this->currentScope->parentScope;
}

bool SymbolTable::put(std::string key, Record *rec)
{
    int size_before = this->currentScope->records.size();
    this->currentScope->records.insert({key, rec});
    if(size_before == this->currentScope->records.size())
    {
        return false;
    }
    return true;
}

Record *SymbolTable::lookup(std::string key)
{
    return this->currentScope->lookup(key);
}

void SymbolTable::traverseAST(Node *node)
{
    static Class*       tempClass    = nullptr;
    static Method*      tempMethod   = nullptr;
    static Variable*    tempVariable = nullptr;

    if(node->type == CLASS_DECLARATION)
    {
        //Get className
        std::string classIdentifier = node->children[0]->value;
        //create new calss
        tempClass = new Class(classIdentifier, CLASS);
        //insert the new class into the current scope
        this->put(classIdentifier, (Record*)tempClass);
        this->program->addClass(tempClass);
        tempMethod = nullptr;

        //Enter the new scope
        this->enterScope();
            //insert new variable "this" to the new class
            tempVariable = new Variable("this", classIdentifier);
            this->put("this", (Record*)tempVariable);
            tempClass->addVaraible(tempVariable);
            //traverse rest of nodes
            this->traverseAST(node->children[1]);
            this->traverseAST(node->children[2]);
        this->exitScope();
    }
    else if(node->type == MAIN_CLASS)
    {
        //Get class name
        std::string classIdentifier = node->children[0]->value;
        //Create new class with that name
        tempClass = new Class(classIdentifier, CLASS);
        //insert the new class
        this->put(classIdentifier, (Record*)tempClass);
        this->program->addClass(tempClass);
        tempMethod = nullptr;

        //Enter new scope
        this->enterScope();
            //create new main method
            tempMethod = new Method("main", "VOID");
            //insert new main method
            this->put(tempMethod->id, (Record*)tempMethod);
            tempClass->addMethod(tempMethod);
            //Create new var "this"
            tempVariable = new Variable("this", classIdentifier);
            //insert new var
            this->put(tempVariable->id, (Record*)tempVariable);
            tempClass->addVaraible(tempVariable);
        this->exitScope();
    }
    else if(node->type == METHOD_DECLARATION || node->type == METHOD_DECLARATION_ARGUMENTS)
    {
        //Get type and id
        std::string type        = node->children[0]->value;
        std::string identifier  = node->children[1]->value;
        //create new method
        tempMethod = new Method(identifier, type);
        //Insert new method
        this->put(identifier, (Record*)tempMethod);
        tempClass->addMethod(tempMethod);
        //Enetert new scope
        this->enterScope();
        //Traverse child
        this->traverseAST(node->children[2]);
        if(node->type == METHOD_DECLARATION_ARGUMENTS)
        {
            this->traverseAST(node->children[3]);
            this->traverseAST(node->children[4]);
        }
        this->exitScope();
    }
    else if(node->type == VAR_DECLARATION)
    {
        //Get type and id
        std::string type = node->children[0]->value;
        std::string identifier = node->children[1]->value;
        //Create new Variable
        tempVariable = new Variable(identifier, type);
        //Insert new variable in method
        if(tempMethod != nullptr)
        {
            tempMethod->addVaraible(tempVariable);
        }
        //Insert new variable in class
        else
        {
            tempClass->addVaraible(tempVariable);
        }
        this->put(identifier, (Record*)tempVariable);

    }
    else if(node->type == ARGUMENT)
    {
        //Get type and id
        std::string type = node->children[0]->value;
        std::string identifier = node->children[1]->value;
        //Cretae new variable
        tempVariable = new Variable(identifier, type);
        //Insert new variable
        this->put(identifier, (Record*)tempVariable);
        tempMethod->addParameter(tempVariable);
    }
    else
    {
        for(auto& c: node->children)
        {
            this->traverseAST(c);
        }
    }
}
