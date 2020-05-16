#include "GridTetromino.h"

GridTetromino::GridTetromino() {
    gridLoc = Point(0,0);
}

Point GridTetromino::getGridLoc() const {
    return gridLoc;
}

void GridTetromino::setGridLoc(int x, int y) {
    gridLoc.setXY(x, y);
}

void GridTetromino::setGridLoc(const Point& pt) {
    gridLoc.setXY(pt.getX(), pt.getY());
}

void GridTetromino::move(int xOffset, int yOffset) {
    gridLoc.setXY(gridLoc.getX() + xOffset, gridLoc.getY() + yOffset);
}

std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
    std::vector<Point> mapped = std::vector<Point>();
    for (Point blockLoc: blockLocs) {
        int x = blockLoc.getX();
        int y = blockLoc.getY();
        x += gridLoc.getX();
        y += gridLoc.getY();
        mapped.push_back(Point(x, y));
    }
    return mapped; 
}
