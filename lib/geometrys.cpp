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

Circle::Circle(int x, int y, int r, std::string color) : FlatGeometryFig () {
    this->x = x;
    this->y = y;
    this->r = r;
    this->color = this->convertToEnum(color);
    this->date_edit = current_date();
}

Rectangle::Rectangle(float x1, float x2, std::string color) : FlatGeometryFig () {
    this->x1 = x1;
    this->x2 = x2;
    this->color = this->convertToEnum(color);
    this->date_edit = current_date();
}

Rectangle::Rectangle(float x1, float x2, std::string color) : FlatGeometryFig () {
    this->x1 = x1;
    this->x2 = x2;
    this->color = this->convertToEnum(color);
    this->date_edit = current_date();
}