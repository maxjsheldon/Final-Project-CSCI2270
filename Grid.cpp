#include "Grid.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

int randomBetween(int min, int max) {
    return min + rand() % (max - min + 1);
}

Grid::Grid(int _x, int _y){
    //bounds handling using stdexcept
    if (_x <= 0 || _y <= 0 || (_x == 1 && _y == 1)) {    
        throw invalid_argument("Grid must contain at least two cells");
    }

    x = _x;
    y = _y;

    //make grid with vector that contains vectors,
    //retrieval is grid[y][x]
    //size goes from 0-4, fyi

    //random start and end
    startX = randomBetween(0,x-1);
    startY = randomBetween(0,y-1);

    endX = randomBetween(0,x-1);
    endY = randomBetween(0,y-1);

    //if the same start and end
    while(startX == endX && startY == endY){
        endX = randomBetween(0,x-1);
        endY = randomBetween(0,y-1);
    }

    //GRID CREATION
    //set grid y value
    grid.resize(y);

    //set grid x value
    for (int i = 0; i < y; i++) {
        grid[i].resize(x);
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
        grid[i][j].x = j;
        grid[i][j].y = i;
    }
}

    setStart(startX,startY);
    setEnd(endX,endY);

    setObstacles();
}

Node* Grid::getNode(int nodeX, int nodeY){
    if (!inBounds(nodeX, nodeY)) {
            return NULL;
        }

    return &grid[nodeY][nodeX];
}

void Grid::setBlocked(int nodeX, int nodeY){
    if (inBounds(nodeX, nodeY)) {
       grid[nodeY][nodeX].blocked = true;
    }
}

//same
void Grid::setVisited(int nodeX, int nodeY){
    if (inBounds(nodeX, nodeY)) {
        grid[nodeY][nodeX].visited = true;
    }
}

void Grid::setStart(int nodeX, int nodeY){
    if (inBounds(nodeX, nodeY)) {
        grid[nodeY][nodeX].start = true;
    }
}

void Grid::setEnd(int nodeX, int nodeY){
    if (inBounds(nodeX, nodeY)) {
        grid[nodeY][nodeX].end = true;
    }
}

void Grid::printGrid(){
    cout << "x = " << x << ", y = " << y << endl;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(grid[i][j].start){
                cout << "S ";
            } 
            else if(grid[i][j].end){
                cout << "E ";
            } 
            else if (grid[i][j].blocked) {
                cout << "# ";
            } 
            else if (grid[i][j].path){
                cout << "* ";
            }
            else if (grid[i][j].visited){
                cout << "o ";
            } 
            else {
                cout << ". ";
            }
        }
        //end line once gone through all x values
        cout << endl;
    }
}

void Grid::setObstacles(){
    float minPercent = .1;
    float maxPercent = .4;

    int amount = randomBetween(minPercent * (x * y),maxPercent * (x * y));
    //cout << amount << endl;

    int tempX;
    int tempY;

    for(int i = 0; i < amount; i++){
        tempX = randomBetween(0,x-1);
        tempY = randomBetween(0,y-1);

        while(isEmpty(tempX,tempY) == false){
            tempX = randomBetween(0,x-1);
            tempY = randomBetween(0,y-1);
        }

        setBlocked(tempX, tempY);
    }
}

bool Grid::isEmpty(int x, int y){
    Node* node = getNode(x,y);

    if(node == nullptr || node->blocked == true || node->end == true || node->start == true){
        return false;
    }

    return true;
}

int Grid::getWidth() const {
    return x;
}

int Grid::getHeight() const {
    return y;
}

Node* Grid::getStart() {
    return getNode(startX, startY);
}

Node* Grid::getEnd() {
    return getNode(endX, endY);
}

bool Grid::inBounds(int nodeX, int nodeY) const {
    return nodeX >= 0 && nodeX < x && nodeY >= 0 && nodeY < y;
}

void Grid::resetSearch() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            Node& node = grid[i][j];

            node.visited = false;
            node.path = false;
            node.g = INT_MAX;
            node.h = 0;
            node.f = INT_MAX;
            node.previous = nullptr;
        }
    }
}

void Grid::markPath(const vector<Node*>& path){
    for(Node* node : path) {
        if (!node->start && !node->end){
            node->path = true;
        }
    }
}