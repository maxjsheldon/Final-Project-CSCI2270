#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Node.h"
#include "Grid.h"
#include <vector>

using namespace std;

class Pathfinder{
    public:
    int heuristic(Node* current, Node* end);
    vector<Node*> getNeighbors(Grid& grid, Node* current);
    vector<Node*> findPath(Grid& grid, Node* start, Node* end);
    vector<Node*> reconstructPath(Node* end);
};
#endif