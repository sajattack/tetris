#include "Point.h"
#include <string>
#include <sstream>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int newX, int newY) {
    x = newX;
    y = newY;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::swapXY() {
    int temp = x;
    x = y;
    y = temp;
}

void Point::multiplyX(int factor) {
    x *= factor;
}

void Point::multiplyY(int factor) {
    y *= factor;
}

std::string Point::toString() const{
    std::stringstream str;
    str << "[" << x << ", " << y << "]";
    return str.str();
}
