#include "Gameboard.h"
#include "Point.h"
#include <iostream>
#include <iomanip>

Gameboard::Gameboard() {
    empty();
}

int Gameboard::getContent(Point pt) const {
    return grid[pt.getX()][pt.getY()];
}

int Gameboard::getContent(int x, int y) const {
    return grid[x][y];
}

void Gameboard::setContent(Point pt, int content) {
    grid[pt.getX()][pt.getY()] = content;
}

void Gameboard::setContent(int x, int y, int content) {
    grid[x][y] = content;
}

void Gameboard::setContent(std::vector<Point> locs, int content) {
    for(Point pt: locs) {
        grid[pt.getX()][pt.getY()] = content;
    }
}

bool Gameboard::areLocsEmpty(std::vector<Point> locs) const {
    for(Point pt: locs) {
        if (pt.getX() < MAX_X && MAX_X >= 0  
                && pt.getY() < MAX_Y && pt.getY() >= 0) {
            if(grid[pt.getX()][pt.getY()] != EMPTY_BLOCK) {
                return false;
            }
        }
    }
    return true;
}

int Gameboard::removeCompletedRows() {
    std::vector<int> rowIndices = getCompletedRowIndices();
    removeRows(rowIndices);
    return rowIndices.size();
}

void Gameboard::empty() {
    for (int y=0; y<MAX_Y; y++) {
        fillRow(y, EMPTY_BLOCK);
    }
}

Point Gameboard::getSpawnLoc() const {
    return spawnLoc;
}

void Gameboard::printToConsole() const {
    std::cout << std::setw(2);
    for (int y=0; y<MAX_Y; y++) {
        for(int x=0; x<MAX_X; x++) {
            std::cout << std::setw(2) << getContent(x,y);
        }
        std::cout << std::endl;
    }
}

bool Gameboard::isRowCompleted(int rowIndex) const {
    for(int x=0; x<MAX_X; x++) {
        if(grid[x][rowIndex] == EMPTY_BLOCK) {
            return false;
        }
    }
    return true;
}

std::vector<int> Gameboard::getCompletedRowIndices() const {
    std::vector<int> completedRowIndices = {};
    for (int y=0; y<MAX_Y; y++) {
        if (isRowCompleted(y)) {
            completedRowIndices.push_back(y);
        }
    }
    return completedRowIndices;
}

void Gameboard::removeRow(int rowIndex) {
    for (int y=rowIndex; y>0; y--) {
        copyRowIntoRow(y-1, y);
    }
    fillRow(0, EMPTY_BLOCK);
}

void Gameboard::removeRows(std::vector<int> rowIndices) {
    for (int i: rowIndices) {
        removeRow(i);
    }
}

void Gameboard::fillRow(int rowIndex, int content) {
    for (int x=0; x<MAX_X; x++) {
        grid[x][rowIndex] = content;
    }
}

void Gameboard::copyRowIntoRow(int sourceRowIndex, int targetRowIndex) {
    for (int x=0; x<MAX_X; x++) {
        grid[x][targetRowIndex] = grid[x][sourceRowIndex];
    }
}
