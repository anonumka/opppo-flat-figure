#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "../lib/list.h"

enum class ERROR_TYPE {
    OK = 0,
    NOT_ENOUGHT_DATA = 1,
    NOT_FOUND_OBJ = 2,
    COLOR_NOT_FOUND = 3,
    NOT_FOUND_COMMAND = 4,
    LIST_EMPTY = 5,
    BAD_COLOR = 6,
    ERROR = 7
};

class MainProcess
{
public:
    MainProcess();
    int commandAdd(std::string command);
    int commandRem(std::string command);
    int run();

private:
    List *objs;
};

#endif // MAIN_H
