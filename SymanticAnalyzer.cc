#include "SymanticAnalyzer.hh"

SymanticAnalyzer::SymanticAnalyzer(SymbolTable* st, ErrorHandler* eh)
    :st(st), eh(eh)
{
}

void SymanticAnalyzer::analyzeAst(Node *root)
{
    this->st->reset();
    this->traverseTree(root);
}

Node* SymanticAnalyzer::traverseTree(Node *node)
{
    if(this->checkEnterScope(node))
        this->st->enterScope();

        //std::cout<<"Node : "<<node->type << " " << node->value <<" Line:" << node->lineno << "\n";

        if(node->type == MAIN_CLASS)
        {
            this->traverseTree(node->children[2]);
        }
        else if(node->type == METHOD_DECLARATION)
        {
            //Get the specified return type
            Node* wantedRetType = this->traverseTree(node->children[0]);
            //Get the actual return type
            Node* actualReturnType = this->traverseTree(node->children[3]);
            //Check that tey are the same type
            //std::cout<<wantedRetType->type<<" "<<wantedRetType->value<<std::endl;
            //std::cout<<actualReturnType->type<<" "<<actualReturnType->value<<std::endl;
            if(!checkMethodType(wantedRetType, actualReturnType))
            {
                std::string errStr = "Method return type not correct type, expected: "+wantedRetType->type+", got: "+actualReturnType->type;
                this->eh->addError(errStr, node->lineno);
            }
            //Traverse method body list
            this->traverseTree(node->children[2]);
        }
        else if(node->type == METHOD_DECLARATION_ARGUMENTS)
        {
            //Get the specified return type
            Node* wantedRetType = this->traverseTree(node->children[0]);
            //Get the actual return type
            Node* actualReturnType = this->traverseTree(node->children[5]);
            //Check that tey are the same type
            //std::cout<<wantedRetType->type<<" "<<wantedRetType->value<<std::endl;
            //std::cout<<actualReturnType->type<<" "<<actualReturnType->value<<std::endl;
            if(!checkMethodType(wantedRetType, actualReturnType))
            {
                std::string errStr = "Method return type not correct type, expected: "+wantedRetType->type+", got: "+actualReturnType->type;
                this->eh->addError(errStr, node->lineno);
            }
            //Traverse method body list
            this->traverseTree(node->children[4]);
        }
        else if(node->type == EXPRESSION_X || node->type == EXPRESSION_X2)
        {    
            Class* cls = this->methodCallGetClass(node->children[0]);
            if(cls != nullptr)
            {
                Method* meth = cls->lookupMethod(node->children[1]->value);
                if(meth == nullptr)
                {
                    std::string errStr = node->children[1]->value + " not defined";
                    this->eh->addError(errStr, node->lineno);
                }
                else
                {
                    if(node->type == EXPRESSION_X)
                    {
                        this->checkMethodCallArgs(node->children[2], node->children[3]->children, meth, node);
                        this->traverseTree(node->children[2]);
                        this->traverseTree(node->children[3]);
                    }
                    this->nodeVec.push_back(new Node(meth->type, meth->id, node->lineno));
                    return this->nodeVec.back();
                }
            }
            
            



        }
        else if(node->type == IF_ELSE_STATEMENT)
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
        else if(node->type == EXPRESSION_ARR)
        {

        }
        else if(node->type == EXPRESSION_LEN)
        {

        }
        else if(node->type == NEW_INT_ARR)
        {

        }
        else if(node->type == NEW_IDENTIFIER)
        {
            Record* rec = this->st->lookup(node->children[0]->value);
            if(rec == nullptr)
            {
                std::string errStr = node->children[0]->value + " not defined";
                this->eh->addError(errStr, node->lineno);
            }
            else
            {
                this->nodeVec.push_back(new Node(rec->type, rec->id, node->lineno));
                return this->nodeVec.back();
            }
        }
        else if(node->type == NOT_EXPRESSION)
        {

        }
        else if(node->type == EXPRESSION_OP)
        {

        }
        else if(node->type == IDENTIFIER)
        {
            Record* rec = this->st->lookup(node->value);
            if(rec == nullptr)
            {
                this->eh->addError("Undeclared identifier", node->lineno);
            }
            else
            {
                nodeVec.push_back(new Node(rec->type, rec->id, node->lineno));
                return nodeVec.back();
            }
        }
        else if(node->type == THIS)
        {
            Record* rec = this->st->lookup("this");
            this->nodeVec.push_back(new Node(rec->type, rec->id, node->lineno));
            return this->nodeVec.back();
        }
        else if(node->type == TYPE)
        {
            nodeVec.push_back(new Node(node->value, node->type, node->lineno));
            return nodeVec.back();
        }
        else
        {
            for(auto c: node->children)
            {
                this->traverseTree(c);
            }
        }



    if(this->checkEnterScope(node))
        this->st->exitScope();


    return node;
}

bool SymanticAnalyzer::checkEnterScope(Node *node)
{
     if(node->type == GOAL
        ||node->type == MAIN_CLASS
        ||node->type == CLASS_DECLARATION
        ||node->type == METHOD_DECLARATION
        ||node->type == METHOD_DECLARATION_ARGUMENTS)
    {
        return true;
    }
    return false;
}

bool SymanticAnalyzer::checkMethodType(Node* n1, Node* n2)
{

    if(n1->type == n2->type)
    {
        return true;
    }
    std::string one = n1->type;
    std::string two = n2->type;
    if(n1->type == CLASS || n1->type == THIS)
    {
        one = n1->value;
    }
    if(n2->type == CLASS || n2->type == THIS)
    {
        two = n1->value;
    }

    if(one == two)
    {
        return true;
    }


    return false;
}

void SymanticAnalyzer::checkMethodCallArgs(Node *arg1, std::vector<Node *> argList, Method *method, Node *node)
{
    std::vector<Node*> args;
    args.push_back(arg1);
    for(auto a: argList)
    {
        args.push_back(a);
    }
    


    if(args.size() != method->parameters.size())
    {
        this->eh->addError("Incorrect number of arguments", node->lineno);
        return;
    }
    std::string nodeType;
    //std::cout<<"Checking "<<args.size()<<" args!\n";
    for(int i = 0; i < args.size(); i++)
    {
        //std::cout<<"Checking "<<args[i]->type<<" and "<<method->parameters[i].var->type<<std::endl;
        //std::cout<<"Checking "<<args[i]->value<<" and "<<method->parameters[i].var->id<<std::endl;
        if(args[i]->type != method->parameters[i].var->type)
        {
            //Check for special cases
            if(args[i]->type == IDENTIFIER)
            {
                nodeType = this->st->lookup(args[i]->value)->type;
            }
            else
            {
                //Temporary to show info
                nodeType = args[i]->type;
            }
            
            
            if(nodeType != method->parameters[i].var->type)
            {
                std::string errStr = args[i]->type + " not the same as " + method->parameters[i].var->type;
                this->eh->addError(errStr, node->lineno);
            }
        }
        else
        {
            std::cout<<args[i]->type<<" is the same as "<<method->parameters[i].var->type<<std::endl;
        }
    }
}

Class *SymanticAnalyzer::methodCallGetClass(Node *node)
{
    Class* ret = nullptr;
    //std::cout<<"node:"<<node->type<<" "<<node->value<<std::endl;
    Node* travRet = this->traverseTree(node);
    //std::cout<<"node:"<<travRet->type<<" "<<travRet->value<<std::endl;

    if(travRet->type == CLASS)
    {
        ret = (Class*)this->st->lookup(travRet->value);
    }
    else if(this->st->lookup(travRet->type)->type == CLASS)
    {
        ret = (Class*)this->st->lookup(travRet->type);
    }

    //Record* rec = this->st->lookup(node->type);
    //std::cout<<rec->type<<" "<<rec->id<<std::endl;

    return ret;
}
