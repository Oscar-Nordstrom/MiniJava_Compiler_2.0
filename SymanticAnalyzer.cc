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
        else if(node->type == IF_STATEMENT)
        {
            Node* exp = this->traverseTree(node->children[0]);
            //Check if the return is of type bool
            if(exp->type != BOOLEAN)
            {
                //std::cout<<"exp: "<<exp->type<<" "<<exp->value<<std::endl;
                std::string errStr = "epxression not of type BOOLEAN";
                this->eh->addError(errStr, node->lineno);
            }
            //Traverse children
            this->traverseTree(node->children[1]);
        }
        else if(node->type == IF_ELSE_STATEMENT)
        {
            Node* exp = this->traverseTree(node->children[0]);
            //Check if the return is of type bool
            if(exp->type != BOOLEAN)
            {
                //std::cout<<"exp: "<<exp->type<<" "<<exp->value<<std::endl;
                std::string errStr = "epxression not of type BOOLEAN";
                this->eh->addError(errStr, node->lineno);
            }
            //Traverse children
            this->traverseTree(node->children[1]);
            this->traverseTree(node->children[2]);
        }
        else if(node->type == WHILE_STATEMENT)
        {
            Node* exp = this->traverseTree(node->children[0]);
            //Check if the return is of type bool
            if(exp->type != BOOLEAN)
            {
                //std::cout<<"exp: "<<exp->type<<" "<<exp->value<<std::endl;
                std::string errStr = "epxression not of type BOOLEAN";
                this->eh->addError(errStr, node->lineno);
            }
            //Traverse children
            this->traverseTree(node->children[1]);
        }
        else if(node->type == EQUAL_STATEMENT)
        {
            Node* identifier = this->traverseTree(node->children[0]);
            Node* exp = this->traverseTree(node->children[1]);
            //std::cout<<"1: "<<identifier->type<<" "<<identifier->value<<std::endl;
            //std::cout<<"2: "<<exp->type<<" "<<exp->value<<std::endl;
            if(identifier->type != exp->type)
            {
            
                if(exp->type == CLASS)
                {   
                    if(identifier->type != exp->value)
                    {
                        //std::cout<<"ERROR\n";
                        this->eh->addError("Equal statement wrong types", node->lineno);
                    }
                }
                else
                {
                    //std::cout<<"ERROR\n";
                    this->eh->addError("Equal statement wrong types", node->lineno);
                }
            }
        }
        else if(node->type == EQUAL_ARR_STATEMENT)
        {
            Node* identifier = this->traverseTree(node->children[0]);
            Node* index = this->traverseTree(node->children[1]);
            Node* exp = this->traverseTree(node->children[2]);

            if(identifier->type != INT_ARR)
            {
                this->eh->addError("Equal_array statement wrong type", node->lineno);
            }

            if(index->type != INT)
            {
                this->eh->addError("Equal_array statement wrong index type", node->lineno);
            }

            if(exp->type != INT)
            {
                this->eh->addError("Equal_array statement wrong expression type", node->lineno);
            }
        }
        else if(node->type == EXPRESSION_ARR)
        {
            Node* exp = this->traverseTree(node->children[0]);
            Node* index = this->traverseTree(node->children[1]);

            //std::cout<<"epx: "<<exp->type<<" "<<exp->value<<std::endl;
            //std::cout<<"index: "<<index->type<<" "<<index->value<<std::endl;

            if(exp->type != INT_ARR)
            {
                this->eh->addError("Expression not of type Int Array", node->lineno);
            }
            if(index->type != INT)
            {
                this->eh->addError("Expression index not of type Int", node->lineno);
            }

            this->nodeVec.push_back(new Node(INT, exp->value, node->lineno));
            return this->nodeVec.back();

        }
        else if(node->type == EXPRESSION_LEN)
        {
            Node* exp = this->traverseTree(node->children[0]);
            if(exp->type != INT_ARR)
            {
                this->eh->addError("Expression not of type Int Array", node->lineno);
            }
            this->nodeVec.push_back(new Node(INT, exp->value, node->lineno));
            return this->nodeVec.back();
        }
        else if(node->type == NEW_INT_ARR)
        {
            Node* index =this->traverseTree(node->children[0]);

            if(index->type != INT)
            {
                this->eh->addError("Expression index not of type Int", node->lineno);
            }
            this->nodeVec.push_back(new Node(INT_ARR, index->value, node->lineno));
            return this->nodeVec.back();
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
            Node* exp = this->traverseTree(node->children[0]);
            if(exp->type != BOOLEAN)
            {
                if(this->st->lookup(exp->value)->type != BOOLEAN)
                {
                    this->eh->addError("NotExpression not of type BOOLEAN", node->lineno);
                }
            }

            this->nodeVec.push_back(new Node(BOOLEAN, exp->value, node->lineno));
            return this->nodeVec.back();
        }
        else if(node->type == EXPRESSION_OP)
        {
            //traverse all children and save use the returns
            Node* exp1 = this->traverseTree(node->children[0]);
            Node* exp2 = this->traverseTree(node->children[1]);
            this->nodeVec.push_back(new Node("", EXPRESSION_OP, node->lineno));
            //std::cout<<"exp1: "<<exp1->type<<" "<<exp1->value<<std::endl;
            //std::cout<<"exp2: "<<exp2->type<<" "<<exp2->value<<std::endl;
            if(node->value == AND_EXPRESSION || node->value == OR_EXPRESSION)
            {
                if(exp1->type != BOOLEAN || exp2->type != BOOLEAN)
                {
                    this->eh->addError("Expression operator incorrect types", node->lineno);
                }
                this->nodeVec.at(this->nodeVec.size()-1)->type = BOOLEAN;
            }
            else if(node->value == LESS_THAN_EXPRESSION || node->value == MORE_THAN_EXPRESSION)
            {
                if(exp1->type != INT || exp2->type != INT)
                {
                    this->eh->addError("Expression operator incorrect types", node->lineno);
                }
                this->nodeVec.at(this->nodeVec.size()-1)->type = BOOLEAN;
            }
            else if(node->value == PLUS_EXPRESSION || node->value == MINUS_EXPRESSION)
            {
                if(exp1->type != INT || exp2->type != INT)
                {
                    this->eh->addError("Expression operator incorrect types", node->lineno);
                }
                this->nodeVec.at(this->nodeVec.size()-1)->type = INT;
            }
            else if(node->value == MULT_EXPRESSION || node->value == DIV_EXPRESSION)
            {
                if(exp1->type != INT || exp2->type != INT)
                {
                    this->eh->addError("Expression operator incorrect types", node->lineno);
                }
                this->nodeVec.at(this->nodeVec.size()-1)->type = INT;
            }
            else if(node->value == EQUAL_EXPRESSION)
            {
                if(exp1->type != exp2->type)
                {
                    this->eh->addError("Expression operator incorrect types", node->lineno);
                }
                this->nodeVec.at(this->nodeVec.size()-1)->type = BOOLEAN;
            }
            //std::cout<<"expression op returning: "<<this->nodeVec.back()->type<<" "<<this->nodeVec.back()->value<<std::endl;
            return this->nodeVec.back();
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
            this->nodeVec.push_back(new Node(CLASS, rec->type, node->lineno));
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
    std::string nodeID;
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
                Node* tempNode = this->traverseTree(args[i]);
                nodeType = tempNode->type;
                nodeID = tempNode->value;
            }
            
            if(nodeType == CLASS)
            {
                nodeType = nodeID;
            }


            if(nodeType != method->parameters[i].var->type)
            {
                
                std::string errStr = nodeType + " not the same as " + method->parameters[i].var->type;
                this->eh->addError(errStr, node->lineno);
            }
        }
    }
}

Class *SymanticAnalyzer::methodCallGetClass(Node *node)
{
    Class* ret = nullptr;
    //std::cout<<"node:"<<node->type<<" "<<node->value<<std::endl;
    Node* travRet = this->traverseTree(node);
    Record* rec = this->st->lookup(travRet->value);
    //std::cout<<"rec:"<<rec->type<<" "<<rec->id<<std::endl;

    if(rec->type == CLASS)
    {
        ret = (Class*)rec;
    }
    else
    {
        ret = this->st->program->lookupClass(rec->type);
        if(ret == nullptr)
        {
            ret = this->st->program->lookupClass(rec->id);
            if(ret == nullptr)
            {
                this->eh->addError("Method call not of type CLASS", node->lineno);
            }
        }
    }


    //Record* rec = this->st->lookup(node->type);
    //std::cout<<rec->type<<" "<<rec->id<<std::endl;

    return ret;
}
