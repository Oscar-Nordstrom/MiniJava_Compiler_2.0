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
        else if(node->type == EXPRESSION_X)
        {

        }
        else if(node->type == EXPRESSION_X2)
        {

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
