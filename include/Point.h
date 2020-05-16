#pragma once
#include <string>

class Point {
    friend class TestSuite;
public:
    Point();
    Point(int newX, int newY);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);
    void swapXY();
    void multiplyX(int factor);
    void multiplyY(int factor);
    std::string toString() const; // return a string of the form [x,y]
private:
    int x;
    int y;
};
