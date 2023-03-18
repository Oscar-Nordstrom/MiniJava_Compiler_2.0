#pragma once

#include <vector>
#include <string>

#include "ThreeAddressCode.hh"


class BBlock
{
public:
    BBlock(std::string name);
    BBlock();
    std::string name;
    std::vector<Tac*> tacs;
    BBlock* trueExit;
    BBlock* falseExit;
    bool printed;
    bool visited;
};
