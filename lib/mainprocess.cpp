#include "mainprocess.h"
#include <bits/stdc++.h>

using namespace std;

MainProcess::MainProcess() {
    objs = new List();;
}

MainProcess::~MainProcess() {
    objs = nullptr;
}

int MainProcess::commandRemFigure(std::string type_figure) {
    FlatGeometryFig *check;
    int tmp_size = objs->getSize();
    for (int i = 0; i < tmp_size; i) {
        check = objs->getElem(i);
        std::string type = typeid(*check).name();
        type.erase(0, 1);
        if (type == type_figure) {
            objs->deleteElem(i);
            i = 0;
            tmp_size = objs->getSize();
        }
        else {
            i++;
        }
    }
    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::commandRemFigureParams(std::stringstream &ss, std::string type_figure) {
    vector<string>output;
    std::string value;
    while (ss >> value){
        output.push_back(value);
    }
    int tmp_size = objs->getSize();

    if (type_figure == "circle") {
        int x, y, r;
        Circle *check;

        if (output.size() == 3) {
            std::istringstream (output[0]) >> x;
            std::istringstream (output[1]) >> y;
            std::istringstream (output[2]) >> r;
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }

        for (int i = 0; i < tmp_size; ++i) {
            check = static_cast<Circle*>(objs->getElem(i));
            if (check->checkParamsCircle(x, y, r)) {
                objs->deleteElem(i);

                i = 0;
                tmp_size = objs->getSize();
            }
        }
    }
    else if (type_figure == "rectangle") {
        float x1, x2;
        Rectangle *check;

        if (output.size() == 2) {
            std::istringstream (output[0]) >> x1;
            std::istringstream (output[1]) >> x2;
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }

        for (int i = 0; i < tmp_size; ++i) {
            check = static_cast<Rectangle*>(objs->getElem(i));
            if (check->checkParamsRectangle(x1, x2)) {
                objs->deleteElem(i);

                i = 0;
                tmp_size = objs->getSize();
            }
        }
    }
    else {
        float x1, x2, x3;
        Triangle *check;

        if (output.size() == 3) {
            std::istringstream (output[0]) >> x1;
            std::istringstream (output[1]) >> x2;
            std::istringstream (output[2]) >> x3;
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }

        for (int i = 0; i < tmp_size; ++i) {
            check = static_cast<Triangle*>(objs->getElem(i));
            if (check->checkParamsTriangle(x1, x2, x3)) {
                objs->deleteElem(i);

                i = 0;
                tmp_size = objs->getSize();
            }
        }
    }
    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::commandRemColor(std::stringstream &ss) {
    std::string del_color;
    ss >> del_color;

    // Проверка на существующий цвет
    FlatGeometryFig *check;
    if (check->convertToEnum(del_color) != COLOR_FIGURE::ERROR) {
        int tmp_size = objs->getSize();

        // Пока существуют элементы - удаляем
        for (int i = 0; i < tmp_size; i) {
            check = objs->getElem(i);
            if (check->getColor() == check->convertToEnum(del_color)) {
                objs->deleteElem(i);
                i = 0;
                tmp_size = objs->getSize();
            }
            else {
                i++;
            }
        }
    }
    else {
        return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
    }
    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::commandAdd(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::stringstream ss(command);
    string type = "";
    ss >> type;
    if (type == "circle") {
        vector<string>output;
        std::string value;
        while (ss >> value){
            output.push_back(value);
        }
        if (output.size() != 4) {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }
        
        FlatGeometryFig* new_obj = new Circle();
        if (new_obj->convertToEnum(output[3]) == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
        }

        if (!static_cast<Circle*>(new_obj)->init(output[0], output[1], output[2], output[3])) {
            objs->addList(new_obj);
        }
        else {
            return static_cast<int>(ERROR_TYPE::BAD_INPUT);
        }    
    }
    else if (type == "rectangle") {
        vector<string>output;
        std::string value;
        while (ss >> value){
            output.push_back(value);
        }
        if (output.size() != 3) {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }

        FlatGeometryFig* new_obj = new Rectangle();
        if (new_obj->convertToEnum(output[2]) == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
        }

        if (!static_cast<Rectangle*>(new_obj)->init(output[0], output[1], output[2])) {
            objs->addList(new_obj);
        }
        else {
            return static_cast<int>(ERROR_TYPE::BAD_INPUT);
        }
    }
    else if (type == "triangle") {
        vector<string>output;
        std::string value;
        while (ss >> value){
            output.push_back(value);
        }
        if (output.size() != 4) {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }
        
        FlatGeometryFig* new_obj = new Triangle();
        if (new_obj->convertToEnum(output[3]) == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
        }
        
        if (!static_cast<Triangle*>(new_obj)->init(output[0], output[1], output[2], output[3])) {
            objs->addList(new_obj);
        }
        else {
            return static_cast<int>(ERROR_TYPE::BAD_INPUT);
        }
    }
    else {
        return static_cast<int>(ERROR_TYPE::NOT_FOUND_OBJ);
    }
    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::commandRem(std::string command) {
    // *
    // color    ?
    // (figure) ?
    //          color   ?
    //          (?, ?, ?)
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::stringstream ss(command);
    string type_rem = "";
    ss >> type_rem;

    if (type_rem == "*") {
        objs->deleteList();
    }
    else if (type_rem == "color") {
        int code = commandRemColor(ss);
        if (code != static_cast<int>(ERROR_TYPE::OK))
            return code;
    }
    else if ((type_rem == "circle" || type_rem == "rectangle" || type_rem == "triangle") && (ss.rdbuf()->in_avail() == 0)) {
        type_rem[0] = toupper(type_rem[0]);
        commandRemFigure(type_rem);
    }
    else if (type_rem == "circle" || type_rem == "rectangle" || type_rem == "triangle") {
        int code = commandRemFigureParams(ss, type_rem);
        if (code != static_cast<int>(ERROR_TYPE::OK))
            return code;
    }
    else {
        return static_cast<int>(ERROR_TYPE::BAD_REMOVE);
    }

    return static_cast<int>(ERROR_TYPE::OK);
}

int MainProcess::run(std::string path_file)
{
    ifstream ist(path_file);

    if (!ist.is_open()) {
        cout << "File is not opened!\n";
        return static_cast<int>(ERROR_TYPE::FILE_NOT_FOUND);
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

    objs = nullptr;
    return static_cast<int>(ERROR_TYPE::OK);
}