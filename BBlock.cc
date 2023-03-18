#include "BBlock.hh"

BBlock::BBlock(std::string name)
    :name(name), trueExit(nullptr), falseExit(nullptr), printed(false), visited(false)
{
}

BBlock::BBlock()
    :name(""), trueExit(nullptr), falseExit(nullptr), printed(false), visited(false)
{
}
