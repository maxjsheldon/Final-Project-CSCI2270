#include "Grid.h"
#include "Node.h"
#include "Pathfinder.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

void GridControl() {
    int width;
    int height;

    cout << "A* Search Visualizer by Max Sheldon" << endl;

    cout << "Enter grid width: ";
    cin >> width;

    cout << "Enter grid height: ";
    cin >> height;

    try {
        Grid grid(width, height);
        Pathfinder search;

        cout << "\nInitial grid:\n";
        grid.printGrid();

        vector<Node*> path = search.findPath(grid, grid.getStart(), grid.getEnd());

        cout << endl;

        if (path.empty()) {
            cout << "No path found." << endl;
        }
        else {
            grid.markPath(path);

            cout << "Completed search:\n";
            grid.printGrid();

            cout << "Path length: " << path.size() - 1 << endl;

            cout << endl;

            cout << "  Key:" << endl;
            cout << "S : Start" << endl;
            cout << "E : End" << endl;
            cout << ". : Unsearched" << endl;
            cout << "# : Obstacle" << endl;
            cout << "o : Searched" << endl;
            cout << "* : Path" << endl;
        }
    }
    catch (const invalid_argument& error) {
        cout << "INVALID: " << error.what() << endl;
    }
}

int main() {
    srand(time(0));

    GridControl();

    return 0;
}


