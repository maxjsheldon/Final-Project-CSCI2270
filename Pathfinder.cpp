#include "Pathfinder.h"
#include "Node.h"
#include "Grid.h"

#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

//gets priority queue to place node with smallest f or highest priority on top
struct CompareNodes{
    bool operator()(Node* first, Node* second) const {
        return first->f > second->f;
    }
};

//manhattan distance bc using only 4-way movement
int Pathfinder::heuristic(Node* current, Node* end){
  return abs(current->x - end->x) + abs(current->y - end->y);
}

vector<Node*> Pathfinder::getNeighbors(Grid& grid, Node* current){
    vector<Node*> neighbors;

    // Up
    Node* up = grid.getNode(current->x, current->y - 1);
    if (up != NULL) {
        neighbors.push_back(up);
    }

    // Down
    Node* down = grid.getNode(current->x, current->y + 1);
    if (down != NULL) {
        neighbors.push_back(down);
    }

    // Left
    Node* left = grid.getNode(current->x - 1, current->y);
    if (left != NULL) {
        neighbors.push_back(left);
    }

    // Right
    Node* right = grid.getNode(current->x + 1, current->y);
    if (right != NULL) {
        neighbors.push_back(right);
    }

    return neighbors;
}

vector<Node*> Pathfinder::findPath(Grid& grid, Node* start, Node* end){
    if(start == NULL || end == NULL){
        return {};
    }

    grid.resetSearch();

    //each "value" stores the f value on entry and the node, 
    //uses a vector as its memory (semi-automatically handled),
    //uses the CompareNodes for its prioritization
    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;

    start->g = 0;
    start->h = heuristic(start, end);
    start->f = start->g + start->h;

    openSet.push(start);

    while(!openSet.empty()){
        //get highest priority or smallest f
        Node* current = openSet.top();
        openSet.pop();

        if(current->visited == true){
            continue;
        }

        current->visited = true;

        if(current == end){
            return reconstructPath(end);
        }

        vector<Node*> neighbors = getNeighbors(grid, current);

        for(Node* n : neighbors){
            if(n->blocked == true){
                continue;
            }

            if(n->visited){
                continue;
            }

            int newG = current->g + 1;

            if(newG < n->g){
                n->g = newG;
                n->h = heuristic(n, end);
                n->f = n->g + n->h;

                n->previous = current;

                openSet.push(n);
            }
        }
    }


    return {};
}

vector<Node*> Pathfinder::reconstructPath(Node* end){
    vector<Node*> path;

    Node* current = end;

    while(current != NULL){
        path.push_back(current);
        current = current->previous;
    }

    reverse(path.begin(), path.end());

    return path;
}