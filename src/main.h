#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "list.h"

enum class ERROR_TYPE {
    OK = 0,
    NOT_ENOUGHT_DATA = 1,
    YELLOW = 2,
    GREEN = 3,
    AZURE = 4,
    BLUE = 5,
    PURPLE = 6,
    ERROR = 7
};

class MainProcess
{
public:
    int commandAdd(std::string command, List *objs);
    int commandRem(std::string command, List *objs);
    int run();

private:

};

#endif // MAIN_H
