# Final-Project-CSCI2270
A* Search Algorithm with Terminal Visual

Overview

My project implements the A* Pathfinding algorithm and visualizes it in the terminal. It generates a 2D grid with random starting and ending positions with obstacles randomly placed as well. It then utilizes the A* algorithm to find the shortest distance from the start to the end.   You are able to determine the size of the grid and the visualization displays the original grid and another with the path found and all explored positions. 

Data Structures Used

In this project, I used three different structures for various purposes. The first one was a 2D vector that stores nodes to represent the grid. This 2D vector made it easy since, once set up, I was able to access the grid with grid[y][x] just giving the coordinates. The nodes each store information relating to the search with coordinates, states, costs for A*, and pointer to the previous node. The second data structure I used was a priority queue that determined the next neighbor to check. It was able to do this with the baseline structure of the A*, giving highest priority to the node with the lowest f cost, or taking the most efficient path it can see. The third structure I used was a path vector. This one was used upon recreating the path found by following the previous pointer from the end and gives you all the nodes you need for directions.

A* Pathfinding

A* works by storing three values within every node. The g value is the known distance from the starting node and is always calculable. The h value, or heuristic, is the distance from the end and, for efficiency, usually estimated. The f value is both these values combined or the total "cost". Because I have limited the movement to only four directions, I was able to use a heuristic calculation called the Manhattan distance which is |current x - end x| + |current y - end y|. With A*, it will always select the node with the smallest f then look through its neighbors until a better path is discovered and then that complete will be recorded through the previous node pointer that goes from end to start if you iterate directly. 

Visualization

For the visualization, I decided to use the terminal. While not graphically impressive, the terminal can visualize a grid cleanly with using different characters to represent different types. With the 2D vector, getting the grid to print is simple. with just two nested loops that check the state of the node before placing a character. It is especially simple since, once the inner loop is complete, you are done with the line and only requires and endl before going to the next line. This system allowed me to easily change the size based upon whatever the user inputs. I show two grids every time you run. The first is the original positioning of the obstacles, start, and end and the second is the same grid but with the shortest path highlighted and all the nodes that the algorithm visited.

Compilation and Running

This project should be fully compilable with any C++17 compiler you choose, but I also included the pathfinder Unix file since I am on a Mac. For me to run it, I use:

```
g++ main.cpp Grid.cpp Pathfinder.cpp -o Pathfinder
```

Then

```
./Pathfinder
```

- By Max Sheldon
