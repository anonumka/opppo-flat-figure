#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <sstream>

#include "list.h"

using namespace std;

void commandAdd(std::string command, List *objs) {
    std::stringstream ss(command);
    string type = "";
    ss >> type;
    if (type == "circle") {
        int x = 0, y = 0, r = 0;
        string tmp_color = "";
        ss >> x >> y >> r >> tmp_color;
        if (x == 0 || y == 0 || r == 0 || tmp_color == "") {
            cout << "error input file: not enough data";
            return;
        }

        FlatGeometryFig* new_obj = new Circle(x, y, r, tmp_color);
        objs->addList(new_obj);
    }
    else if (type == "rectangle") {
        float x1 = 0, x2 = 0;
        string tmp_color = "";
        ss >> x1 >> x2 >> tmp_color;
        if (x1 == 0 || x2 == 0 || tmp_color == "") {
            cout << "error input file: not enough data";
            return;
        }

        FlatGeometryFig* new_obj = new Rectangle(x1, x2, tmp_color);
        objs->addList(new_obj);
    }
    else if (type == "triangle") {
        float x1 = 0, x2 = 0, x3 = 0;
        string tmp_color = "";
        ss >> x1 >> x2 >> x3 >> tmp_color;
        if (x1 == 0 || x2 == 0 || x3 == 0 || tmp_color == "") {
            cout << "error input file: not enough data";
            return;
        }

        FlatGeometryFig* new_obj = new Triangle(x1, x2, x3, tmp_color);
        objs->addList(new_obj);
    }
    else {
        cout << "error input file: not found object";
        return;
    }
    return;
}

void commandRem(std::string command, List *objs) {
    // *
    // color    ?
    // (figure) color   ?
    //          (?, ?, ?)
    std::stringstream ss(command);
    string type = "";
    ss >> type;

    if (command == "*") {
        objs->deleteList();
    }
    else if (command == "color") {
        ss >> command;
        FlatGeometryFig *check;
        if (check->convertToEnum(command) != color_figure::ERROR) {
            int tmp_size = objs->getSize();

            for (int i = 0; i < tmp_size; ++i) {
                check = objs->getElem(i);
                if (check->getColor() == check->convertToEnum(command)) {
                    objs->deleteElem(i);

                    i = 0;
                    tmp_size = objs->getSize();
                }
            }
        }
        else {
            return;
        }
    }
    else if (command == "circle") {
        FlatGeometryFig *check;
        int x, y, r;
        ss >> x >> y >> r;

        int tmp_size = objs->getSize();
        for (int i = 0; i < tmp_size; ++i) {
            check = objs->getElem(i);
            if (check->checkParamsCircle(x, y, r)) {
                objs->deleteElem(i);

                i = 0;
                tmp_size = objs->getSize();
            }
        }
    }
    else if (command == "rectangle") {
        FlatGeometryFig *check;
        float x1, x2;
        ss >> x1 >> x2;

        int tmp_size = objs->getSize();
        for (int i = 0; i < tmp_size; ++i) {
            check = objs->getElem(i);
            if (check->checkParamsRectangle(x1, x2)) {
                objs->deleteElem(i);

                i = 0;
                tmp_size = objs->getSize();
            }
        }
    }
    else if (command == "triangle") {
        FlatGeometryFig *check;
        float x1, x2, x3;
        ss >> x1 >> x2 >> x3;

        int tmp_size = objs->getSize();
        for (int i = 0; i < tmp_size; ++i) {
            check = objs->getElem(i);
            if (check->checkParamsTriangle(x1, x2, x3)) {
                objs->deleteElem(i);

                i = 0;
                tmp_size = objs->getSize();
            }
        }
    }

    return;
}

int main()
{
    List objs;
    ifstream ist("input.txt");

    if (!ist.is_open()) {
        cout << "File is not opened!\n";
        return -1;
    }

    string command;
    ist >> command;

    while (!ist.eof()) {
        if (command == "add") {
            std::getline(ist, command);
            commandAdd(command, &objs);
        }
        else if (command == "rem") {
            std::getline(ist, command);
            commandRem(command, &objs);
        }
        else if (command == "print") {
            objs.printList();
            cout << "---------\n";
        }
        else {
            cout << "Command not found.";
        }

        ist >> command;
    }

    return 0;
}
