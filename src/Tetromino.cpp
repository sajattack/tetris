#include "Tetromino.h"
#include "Point.h"
#include <cmath>
#include <iostream>

Tetromino::Tetromino() {
    setShape(TetShape::SHAPE_O);
}

TetColor Tetromino::getColor() const {
    return color;
}

TetShape Tetromino::getShape() {
    return shape;
}

void Tetromino::setShape(TetShape shape) {
    switch(shape) {
        case SHAPE_O:
            blockLocs = {
                Point(0,1), 
                Point(1,1), 
                Point(0,0), 
                Point(1,0)
            };
            color = TetColor::YELLOW;
            break;
        case SHAPE_I:
            blockLocs = {
                Point(0,0), 
                Point(0,1), 
                Point(0,2), 
                Point(0,-1)
            };
            color = TetColor::BLUE_LIGHT;
            break;
        case SHAPE_S:
            blockLocs = {
                Point(0,1), 
                Point(-1,1), 
                Point(0,0), 
                Point(1,0)
            };
            color = TetColor::RED;
            break;
        case SHAPE_Z:
            blockLocs = {
                Point(0,0), 
                Point(0,1), 
                Point(-1,0), 
                Point(1,1)
            };
            color = TetColor::GREEN;
            break;
        case SHAPE_L:
            blockLocs = {
                Point(0,1), 
                Point(0,0), 
                Point(0,-1),
                Point(-1,-1)
            };
            color = TetColor::ORANGE;
            break;
        case SHAPE_J:
            blockLocs = {
                Point(0,1), 
                Point(0,0), 
                Point(0,-1),
                Point(1,-1)
            };
            color = TetColor::BLUE_DARK;
            break;
        case SHAPE_T:
            blockLocs = {
                Point(1,0), 
                Point(0,0), 
                Point(-1,0),
                Point(0,-1),
            };
            color = TetColor::PURPLE;
            break;
    }
    this->shape = shape;
}

void Tetromino::rotateCW() {
    for (auto &point: blockLocs) {
        point.swapXY();
        point.multiplyY(-1);
    }
}

void Tetromino::printToConsole() {
    for (int y = 3; y >= -3; y--) {
        for (int x = -3; x <= 3; x++) {
            bool isPoint = false;
            for (auto &point: blockLocs) {
                if (point.getX() == x && point.getY() == y) {
                    isPoint = true;
                    std::cout << "x";
                }
            }
            if (!isPoint) {
                std::cout << "."; 
            }
        }
        std::cout << std::endl;
    }
}

TetShape Tetromino::getRandomShape() {
    return static_cast<TetShape>(
        rand() % static_cast<int>(TetShape::TetShapeCount)
    );
}
