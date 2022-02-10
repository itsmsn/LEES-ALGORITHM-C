# LEES-ALGORITHM-C++
Write a C++ program that solves the maze problem. It will use a 2-D dynamic array grid (as a maze). The
dimensions of array will be taken as input from the user. Following figures shows layout of maze. You will
implement the graphical user interface with highlighted blocked cells and also the final path found at end.
Here are some guide lines for the solution.
a. First step for the rat is to enter in maze (you can ask the user to provide source and destination cells).
b. Orange and green squares in figure are squares in which the rat can move.
c. Blue squares are hurdles and rat cannot move there. You can use any marking colors or values (0, 1,
2) for your game.
d. Move order is just in four directions: Right, Down, Left, Up
e. At the end the path from destination till entry cell should be marked and printed in 2-D maze matrix.
f. Placement of Hurdles should be random it should change with each instance of new game.
</br>
Queue Based Solution: Lee’s Algorithm
In this solution a queue of reachable squares is used. The queue has initially position of source cell empty,
and the source square/cell has a distance value of 0.
Dequeue the cell position and examine unreached, unblocked squares adjacent to this cell. Mark them
with the distance (this is 1 more than the distance value of the dequeued cell). Add position of these marked
cells in the queue. Then a cell is removed from the queue and made the new examine cell. This process is
repeated until the end pin is reached or the queue becomes empty. If destination cell is reached trace back
the path till source by visiting labeled cells with value -1 of current cell.
