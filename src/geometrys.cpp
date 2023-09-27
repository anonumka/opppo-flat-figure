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
