#include "mainprocess.h"

using namespace std;

MainProcess::MainProcess() {
    objs = nullptr;
}

int MainProcess::commandAdd(std::string command) {
    std::stringstream ss(command);
    string type = "";
    ss >> type;
    if (type == "circle") {
        int x = 0, y = 0, r = 0;
        string tmp_color = "";
        ss >> x >> y >> r >> tmp_color;
        if (x == 0 || y == 0 || r == 0 || tmp_color == "") {
            cout << "error input file: not enough data";
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }
        FlatGeometryFig* new_obj = new Circle(x, y, r, tmp_color);

        if (new_obj->getColor() == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::BAD_COLOR);
        }

        objs->addList(new_obj);

    }
    else if (type == "rectangle") {
        float x1 = 0, x2 = 0;
        string tmp_color = "";
        ss >> x1 >> x2 >> tmp_color;
        if (x1 == 0 || x2 == 0 || tmp_color == "") {
            cout << "error input file: not enough data";
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }
        FlatGeometryFig* new_obj = new Rectangle(x1, x2, tmp_color);

        if (new_obj->getColor() == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::BAD_COLOR);
        }

        objs->addList(new_obj);
    }
    else if (type == "triangle") {
        float x1 = 0, x2 = 0, x3 = 0;
        string tmp_color = "";
        ss >> x1 >> x2 >> x3 >> tmp_color;
        if (x1 == 0 || x2 == 0 || x3 == 0 || tmp_color == "") {
            cout << "error input file: not enough data";
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }
        FlatGeometryFig* new_obj = new Triangle(x1, x2, x3, tmp_color);

        if (new_obj->getColor() == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::BAD_COLOR);
        }

        objs->addList(new_obj);
    }
    else {
        // cout << "error input file: not found object";
        return static_cast<int>(ERROR_TYPE::NOT_FOUND_OBJ);
    }
    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::commandRem(std::string command) {
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
        if (check->convertToEnum(command) != COLOR_FIGURE::ERROR) {
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
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_FOUND);
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

    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::run()
{
    objs = new List;
    ifstream ist("input.txt");

    if (!ist.is_open()) {
        cout << "File is not opened!\n";
        return -1;
    }

    string command;
    ist >> command;

    while (!ist.eof()) {
        if (command == "add") {
            string cur_line = "";
            std::getline(ist, cur_line);
            commandAdd(cur_line);
        }
        else if (command == "rem") {
            string cur_line = "";
            std::getline(ist, cur_line);
            commandRem(cur_line);
        }
        else if (command == "print") {
            objs->printList();
            cout << "---------\n";
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_FOUND_COMMAND);
        }

        ist >> command;
    }

    return static_cast<int>(ERROR_TYPE::OK);
}