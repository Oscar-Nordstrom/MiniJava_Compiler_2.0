#include "ErrorHandler.hh"


Error::Error(std::string what, int line)
    :what(what), line(line)
{
}

void Error::printError()
{
    printf("Error[%i]: %s\n", this->line, this->what.c_str());
}

ErrorHandler::ErrorHandler()
{
}

void ErrorHandler::addError(std::string type, int line)
{
    this->errors.push_back(Error(type, line));
}

bool ErrorHandler::hasErrors()
{
    if(this->errors.size() > 0)
    {
        //std::cout<<this->errors.size()<<std::endl;
        return true;
    }
    return false;
}

void ErrorHandler::printErrors()
{
    std::cout<<"--------------------------------------------------Errors--------------------------------------------------"<<std::endl;
    std::cout<<"StartOfErrors:\n";
    for(auto& e: this->errors)
    {
        e.printError();
    }
    std::cout<<"EndOfErrors\n";
    std::cout<<"-----------------------------------------------------------------------------------------------------------"<<std::endl;
}
