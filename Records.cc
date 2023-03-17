#include "Records.hh"

Record::Record(std::string id, std::string type)
    :id(id), type(type)
{
}

void Record::printRecord()
{
    std::cout<<"Type: "<< this->type<<" ID: "<<this->id<<std::endl;
}


Variable::Variable(std::string id, std::string type)
    :Record(id, type)
{
}


Method::Method(std::string id, std::string type)
    :Record(id, type)
{
}

bool Method::addVaraible(Variable *variable)
{
    if(this->canAddVar(variable))
    {
        this->variables.push_back({variable->id, variable});
        return true;
    }
    else
    {
        return false;
    }
}

bool Method::addParameter(Variable *parameter)
{
    if(this->canAddParam(parameter))
    {
        this->parameters.push_back({parameter->id, parameter});
        return true;
    }
    else
    {
        return false;
    }
}

Variable *Method::lookupVar(std::string id)
{
    for(auto& v: this->variables)
    {
        if(v.id == id)
        {
            return v.var;
        }
    }
    return nullptr;
}

Variable *Method::lookupParam(std::string id)
{
    for(auto& p: this->parameters)
    {
        if(p.id == id)
        {
            return p.var;
        }
    }
    return nullptr;
}

bool Method::canAddVar(Variable *variable)
{
    for(auto& v: this->variables)
    {
        if(v.id == variable->id)
        {
            return false;
        }
    }
    return true;
}

bool Method::canAddParam(Variable *parameter)
{
    for(auto& p: this->parameters)
    {
        if(p.id == parameter->id)
        {
            return false;
        }
    }
    return true;
}

Class::Class(std::string id, std::string type)
    :Record(id, type)
{
}

bool Class::addVaraible(Variable *variable)
{
    if(this->canAddVar(variable))
    {
        this->variables.push_back({variable->id, variable});
        return true;
    }
    else
    {
        return false;
    }
}

bool Class::addMethod(Method *method)
{
    if(this->canAddMethod(method))
    {
        this->methods.push_back({method->id, method});
        return true;
    }
    else
    {
        return false;
    }
}

Variable *Class::lookupVar(std::string id)
{
    for(auto& v: this->variables)
    {
        if(v.id == id)
        {
            return v.var;
        }
    }
    return nullptr;
}

Method *Class::lookupMethod(std::string id)
{
    for(auto& m: this->methods)
    {
        if(m.id == id)
        {
            return m.meth;
        }
    }
    return nullptr;
}

bool Class::canAddVar(Variable *variable)
{
    for(auto& v: this->variables)
    {
        if(v.id == variable->id)
        {
            return false;
        }
    }
    return true;
}

bool Class::canAddMethod(Method *method)
{
    for(auto& m: this->methods)
    {
        if(m.id == method->id)
        {
            return false;
        }
    }
    return true;
}

Program::Program(std::string id, std::string type)
    :Record(id, type)
{
}

bool Program::addClass(Class *cls)
{
    if(this->canAddClass(cls))
    {
        this->classes.push_back({cls->id, cls});
        return true;
    }
    else
    {
        return true;
    }
}

Class *Program::lookupClass(std::string id)
{
    for(auto& c: this->classes)
    {
        if(c.id == id)
        {
            return c.cls;
        }
    }
    return nullptr;
}

bool Program::canAddClass(Class *cls)
{
    for(auto& c: this->classes)
    {
        if(c.id == cls->id)
        {
            return false;
        }
    }
    return true;
}
