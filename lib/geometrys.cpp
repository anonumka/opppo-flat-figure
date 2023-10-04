#include "geometrys.h"

COLOR_FIGURE FlatGeometryFig::convertToEnum(std::string color) {
    if (color == "red") {
        return COLOR_FIGURE::RED;
    }
    else if (color == "orange") {
        return COLOR_FIGURE::ORANGE;
    }
    else if (color == "yellow") {
        return COLOR_FIGURE::YELLOW;
    }
    else if (color == "green") {
        return COLOR_FIGURE::GREEN;
    }
    else if (color == "azure") {
        return COLOR_FIGURE::AZURE;
    }
    else if (color == "blue") {
        return COLOR_FIGURE::BLUE;
    }
    else if (color == "purple"){
        return COLOR_FIGURE::PURPLE;
    }
    return COLOR_FIGURE::ERROR;
}

std::string FlatGeometryFig::convertToString(COLOR_FIGURE color) {
    if (color == COLOR_FIGURE::RED) {
        return "red";
    }
    else if (color == COLOR_FIGURE::ORANGE) {
        return "orange";
    }
    else if (color == COLOR_FIGURE::YELLOW) {
        return "yellow";
    }
    else if (color == COLOR_FIGURE::GREEN) {
        return "green";
    }
    else if (color == COLOR_FIGURE::AZURE) {
        return "azure";
    }
    else if (color == COLOR_FIGURE::BLUE) {
        return "blue";
    }
    else if (color == COLOR_FIGURE::PURPLE){
        return "purple";
    }

    return "error";
}

int Circle::init(std::string x, std::string y, std::string r, std::string color) {
    int new_x = 0, new_y = 0, new_r = 0;
    try {
        new_x = std::stoi(x);
        new_y = std::stoi(y);
        new_r = std::stoi(r);
    }
    catch(std::exception& e) {
        std::cout << "Error converting" << '\n';
        return 1;
    }
    
    this->x = new_x;
    this->y = new_y;
    this->r = new_r;
    this->color = this->convertToEnum(color);
    this->date_edit = current_date();
    return 0;
}

int Rectangle::init(std::string x1, std::string x2, std::string color) {
    int new_x1 = 0, new_x2 = 0;
    try {
        new_x1 = std::stof(x1);
        new_x2 = std::stof(x2);
    }
    catch(std::exception& e) {
        std::cout << "Error converting" << '\n';
        return 1;
    }

    this->x1 = new_x1;
    this->x2 = new_x2;
    this->color = this->convertToEnum(color);
    this->date_edit = current_date();
    return 0;
}

int Triangle::init(std::string x1, std::string x2, std::string x3, std::string color) {
    int new_x1 = 0, new_x2 = 0, new_x3 = 0;
    try {
        new_x1 = std::stof(x1);
        new_x2 = std::stof(x2);
        new_x3 = std::stof(x3);
    }
    catch(std::exception& e) {
        std::cout << "Error converting" << '\n';
        return 1;
    }

    this->x1 = new_x1;
    this->x2 = new_x2;
    this->x3 = new_x3;
    this->color = this->convertToEnum(color);
    this->date_edit = current_date();
    return 0;
}