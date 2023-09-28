#include "mainprocess.h"
#include <bits/stdc++.h>

using namespace std;

MainProcess::MainProcess() {
    objs = new List();;
}

MainProcess::~MainProcess() {
    objs = nullptr;
}

int MainProcess::commandAdd(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::stringstream ss(command);
    string type = "";
    ss >> type;
    if (type == "circle") {
        int x = 0, y = 0, r = 0;
        string tmp_color = "";

        vector<string>output;
        std::string value;
        while (ss >> value){
            output.push_back(value);
        }
        if (output.size() == 4) {
            std::istringstream (output[0]) >> x;
            std::istringstream (output[1]) >> y;
            std::istringstream (output[2]) >> r;
            tmp_color = output[3];
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }
        
        FlatGeometryFig* new_obj = new Circle(x, y, r, tmp_color);

        if (new_obj->getColor() == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
        }

        objs->addList(new_obj);
    }
    else if (type == "rectangle") {
        float x1 = 0, x2 = 0;
        string tmp_color = "";
        
        vector<string>output;
        std::string value;
        while (ss >> value){
            output.push_back(value);
        }
        if (output.size() == 3) {
            std::istringstream (output[0]) >> x1;
            std::istringstream (output[1]) >> x2;
            tmp_color = output[2];
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }

        FlatGeometryFig* new_obj = new Rectangle(x1, x2, tmp_color);
        if (new_obj->getColor() == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
        }

        objs->addList(new_obj);
    }
    else if (type == "triangle") {
        float x1 = 0, x2 = 0, x3 = 0;
        string tmp_color = "";
        
        vector<string>output;
        std::string value;
        while (ss >> value){
            output.push_back(value);
        }
        if (output.size() == 4) {
            std::istringstream (output[0]) >> x1;
            std::istringstream (output[1]) >> x2;
            std::istringstream (output[2]) >> x3;
            tmp_color = output[3];
        }
        else {
            return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
        }

        FlatGeometryFig* new_obj = new Triangle(x1, x2, x3, tmp_color);

        if (new_obj->getColor() == COLOR_FIGURE::ERROR) {
            return static_cast<int>(ERROR_TYPE::COLOR_NOT_EXIST);
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
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::stringstream ss(command);
    string type = "";
    ss >> type;

    if (type == "*") {
        objs->deleteList();
    }
    else if (type == "color") {
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
    }
    else if (type == "circle") {
        if (ss.rdbuf()->in_avail() == 0) {
            FlatGeometryFig *check;
            int tmp_size = objs->getSize();
            for (int i = 0; i < tmp_size; i) {
                check = objs->getElem(i);
                std::string type = typeid(*check).name();
                type.erase(0, 1);
                if (type == "Circle") {
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
            int x, y, r;
            Circle *check;
            vector<string>output;
            std::string value;
            while (ss >> value){
                output.push_back(value);
            }
            if (output.size() == 3) {
                std::istringstream (output[0]) >> x;
                std::istringstream (output[1]) >> y;
                std::istringstream (output[2]) >> r;
            }
            else {
                return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
            }

            int tmp_size = objs->getSize();
            for (int i = 0; i < tmp_size; ++i) {
                check = static_cast<Circle*>(objs->getElem(i));
                if (check->checkParamsCircle(x, y, r)) {
                    objs->deleteElem(i);

                    i = 0;
                    tmp_size = objs->getSize();
                }
            }
        }
    }
    else if (type == "rectangle") {
        if (ss.rdbuf()->in_avail() == 0) {
            FlatGeometryFig *check;
            int tmp_size = objs->getSize();
            for (int i = 0; i < tmp_size; i) {
                check = objs->getElem(i);
                std::string type = typeid(*check).name();
                type.erase(0, 1);
                if (type == "Rectangle") {
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
            float x1, x2;
            Rectangle *check;
            vector<string>output;
            std::string value;
            while (ss >> value){
                output.push_back(value);
            }
            if (output.size() == 2) {
                std::istringstream (output[0]) >> x1;
                std::istringstream (output[1]) >> x2;
            }
            else {
                return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
            }

            int tmp_size = objs->getSize();
            for (int i = 0; i < tmp_size; ++i) {
                check = static_cast<Rectangle*>(objs->getElem(i));
                if (check->checkParamsRectangle(x1, x2)) {
                    objs->deleteElem(i);

                    i = 0;
                    tmp_size = objs->getSize();
                }
            }
        }
    }
    else if (type == "triangle") {
        if (ss.rdbuf()->in_avail() == 0) {
            FlatGeometryFig *check;
            int tmp_size = objs->getSize();
            for (int i = 0; i < tmp_size; i) {
                check = objs->getElem(i);
                std::string type = typeid(*check).name();
                type.erase(0, 1);
                if (type == "Triangle") {
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
            float x1, x2, x3;
            Triangle *check;
            vector<string>output;
            std::string value;
            while (ss >> value){
                output.push_back(value);
            }
            if (output.size() == 3) {
                std::istringstream (output[0]) >> x1;
                std::istringstream (output[1]) >> x2;
                std::istringstream (output[2]) >> x3;
            }
            else {
                return static_cast<int>(ERROR_TYPE::NOT_ENOUGHT_DATA);
            }

            int tmp_size = objs->getSize();
            for (int i = 0; i < tmp_size; ++i) {
                check = static_cast<Triangle*>(objs->getElem(i));
                if (check->checkParamsTriangle(x1, x2, x3)) {
                    objs->deleteElem(i);

                    i = 0;
                    tmp_size = objs->getSize();
                }
            }
        }
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