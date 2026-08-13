#ifndef GRID_H
#define GRID_H

#include "Node.h"
#include <vector>

using namespace std;

class Grid {
private:
    //size
    int x;
    int y;

    //start
    int startX;
    int startY;

    //end
    int endX;
    int endY;

    //each item in this list has a vector,
    //each is the column with then how far up you go being the second
    vector<vector<Node>> grid;
public:
    Grid(int _x, int _y);

    Node* getNode(int _x, int _y);

    void setBlocked(int _x, int _y);
    void setVisited(int x, int y);

    void setStart(int _x, int _y);
    void setEnd(int _x, int _y);

    void printGrid();

    void setObstacles();

    bool isEmpty(int _x, int _y);

    int getWidth() const;
    int getHeight() const;

    Node* getStart();
    Node* getEnd();

    bool inBounds(int nodeX, int nodeY) const;

    void resetSearch();

    void markPath(const vector<Node*>& path);
};

#endif