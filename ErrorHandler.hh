#pragma once

#include <string>
#include <vector>
#include <iostream>

class Error
{
public:
    Error(std::string what = "EMPTY", int line = 1);
    void printError();
    std::string what;
    int line;
};


class ErrorHandler
{
public:
    ErrorHandler();
    void addError(std::string type, int line);
    bool hasErrors();
    void printErrors();
private:
    std::vector<Error> errors;
};