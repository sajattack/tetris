#pragma once
#include <vector>
#include "Point.h"

enum TetColor {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE_LIGHT,
    BLUE_DARK,
    PURPLE,
    TetColorCount,
};

enum TetShape {
    SHAPE_S,
    SHAPE_Z,
    SHAPE_L,
    SHAPE_J,
    SHAPE_O,
    SHAPE_I,
    SHAPE_T,
    TetShapeCount,
};

class Tetromino {
    friend class TestSuite;
private: 
    TetColor color;
    TetShape shape;
protected:
    std::vector<Point> blockLocs;
public:
    Tetromino();
    TetColor getColor() const;
    TetShape getShape();
    void setShape(TetShape shape);
    void rotateCW();
    void printToConsole();
    static TetShape getRandomShape();
};
