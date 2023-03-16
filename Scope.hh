#pragma once

#include <vector>
#include <unordered_map>

#include "Records.hh"

class Scope
{
public:
    Scope();
    Scope(Scope* parentScope);
    Scope* NextChild();
    Record* lookup(std::string key);
    void resetScope();

    int next = 0;                                           //Next child to visit
    Scope* parentScope;                                     //Parent scope
    std::vector<Scope*> childrenScopes;                     //Children scopes
    std::unordered_map<std::string, Record*> records;       //map of all records
};