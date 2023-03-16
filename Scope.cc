#include "Scope.hh"

Scope::Scope()
{
    this->parentScope = nullptr;
}

Scope::Scope(Scope *parentScope)
    :parentScope(parentScope)
{
}

Scope *Scope::NextChild()
{
    Scope* nextChild;
    //Create a new child scope
    if(this->next == this->childrenScopes.size())
    {
        nextChild = new Scope(this);
        this->childrenScopes.push_back(nextChild);
    }
    //Visit scope
    else
    {
        nextChild = this->childrenScopes[this->next];
    }
    this->next++;
    return nextChild;
}

Record *Scope::lookup(std::string key)
{
    if(this->records.find(key) != this->records.end())
    {
        return this->records[key];
    }
    else
    {
        if(this->parentScope == nullptr)
        {
            return nullptr;
        }
        else
        {
            return this->parentScope->lookup(key);
        }
    }
}

void Scope::resetScope()
{
    this->next = 0;
    for(auto& c: this->childrenScopes)
    {
        c->resetScope();
    }
}
