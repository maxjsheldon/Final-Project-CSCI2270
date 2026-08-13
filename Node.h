#ifndef NODE_H
#define NODE_H

#include <climits>

struct Node {
    //position
    int x = 0;
    int y = 0;

    //state
    bool blocked = false;
    bool visited = false;
    bool start = false;
    bool end = false;
    bool path = false;

    //A*
    int g = INT_MAX;
    int h = 0;
    int f = INT_MAX;

    Node* previous = nullptr;
};

#endif