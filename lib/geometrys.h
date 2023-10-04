#ifndef GEOMETRYS_H
#define GEOMETRYS_H

#include <ctime>
#include <iostream>
#include <cstring>
#include <string>

enum class COLOR_FIGURE {
    RED = 0,
    ORANGE = 1,
    YELLOW = 2,
    GREEN = 3,
    AZURE = 4,
    BLUE = 5,
    PURPLE = 6,
    ERROR = 7
};

class FlatGeometryFig {
protected:
    std::string date_edit;
    COLOR_FIGURE color;
public:
    FlatGeometryFig() {}
    ~FlatGeometryFig() {}

    std::string convertToString(COLOR_FIGURE color);
    COLOR_FIGURE convertToEnum(std::string color);
    COLOR_FIGURE getColor() { return color; };

    std::string current_date() {
        time_t now = time(0);
        char* date_time = ctime(&now);
        std::string res(date_time);
        return res;
    }

    virtual void print() = 0;
};

class Circle : public FlatGeometryFig {
private:
    int x, y, r;
public:
    int init(std::string x, std::string y, std::string r, std::string color);

    void print() override {
        std::cout << "circle (" << x << ", " << y << ", " << r << "), color = " << convertToString(color)
             << ", last date edit = " << date_edit;
    }

    int checkParamsCircle(int x, int y, int r) {
        if (this->x == x && this->y == y && this->r == r) {
            return 1;
        }
        return 0;
    }
};

class Rectangle : public FlatGeometryFig {
private:
    float x1, x2;
public:
    int init(std::string x1, std::string x2, std::string color);

    void print() override {
        std::cout << "rectangle (" << x1 << ", " << x2 << "), color = " << convertToString(color)
             << ", last date edit = " << date_edit;
    }

    int checkParamsRectangle(float x1, float x2) {
        if (this->x1 == x1 && this->x2 == x2) {
            return 1;
        }
        return 0;
    }
};

class Triangle : public FlatGeometryFig {
private:
    float x1, x2, x3;
public:
    int init(std::string x1, std::string x2, std::string x3, std::string color);

    void print() override {
        std::cout << "triangle (" << x1 << ", " << x2 << ", " << x3 << "), color = " << convertToString(color)
             << ", last date edit = " << date_edit;
    }

    int checkParamsTriangle(float x1, float x2, float x3) {
        if (this->x1 == x1 && this->x2 == x2 && this->x3 == x3) {
            return 1;
        }
        return 0;
    }
};

#endif // LIST_H
