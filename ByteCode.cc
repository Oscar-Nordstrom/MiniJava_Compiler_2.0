#include "ByteCode.hh"

ByteCodeInstruction::ByteCodeInstruction()
{
}

void ByteCodeInstruction::setData(std::string data)
{
    this->data = data;
}

std::string ByteCodeInstruction::getData()
{
    return this->data;
}

ByteCodeMethod::ByteCodeMethod()
{
}

void ByteCodeMethod::setData(std::string data)
{
    this->data = data;
}

std::string ByteCodeMethod::getData()
{
    return this->data;
}

ByteCodeProgram::ByteCodeProgram()
{
}

void ByteCodeProgram::setData(std::string data)
{
    this->data = data;
}

std::string ByteCodeProgram::getData()
{
    return this->data;
}
