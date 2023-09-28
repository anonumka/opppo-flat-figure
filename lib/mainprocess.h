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
    COLOR_NOT_EXIST = 3,
    NOT_FOUND_COMMAND = 4,
    LIST_EMPTY = 5,
    FILE_NOT_FOUND = 6,
    BAD_REMOVE = 7,
    ERROR = 8
};

class MainProcess
{
public:
    MainProcess();
    ~MainProcess();
    int commandAdd(std::string command);
    int commandRem(std::string command);
    int run(std::string path_file);
    List *objs;
private:
    int commandRemFigure(std::string type_figure);
    int commandRemFigureParams(std::stringstream &ss, std::string type_figure);
    int commandRemColor(std::stringstream &ss);
};

#endif // MAIN_H
