
# FUNCTIONS USED IN THE CODE


**create_board():**

    creates the board as a graph by representing it as an adjacency list or adjacency matrix

**snakes():**

    updates the already created board by adding  the snakes in the graph representation

**ladders():**
    
    updates the already created board by adding  the snakes in the graph representation
    
**display_graph():**

    displays the board in the form of graph represenation either in adjacency matrix or adjacency list
   
**bfs():**
    
    implements the breadth first search algorithm on the board and returns the minimum number of dice rolls required to reach the last square
    
**path():**

    gives the shortest path for reaching the last cell of the board
 
**enqueue():**

    inserts an element into the queue used while performing bfs 

**dequeue():**

    deletes and returns an element from the queue used while performing bfs 


# BFS

* Declare a queue and insert the starting vertex.

* Initialize a visited array and mark the starting vertex as visited.

* Follow the below process till the queue becomes empty:
   - Remove the first vertex of the queue.
   - Mark that vertex as visited
   - Insert all the unvisited neighbors of the vertex into the queue.


# CREATE GRAPH

* for adjacency list 
   - initialize an array of self referencial structure and make every entry link to NULL
   - iterate through the list and add adjacent vertices for each vertex
   - adjacent vertices are the next 6 vertices on the board for any given vertex
* for adjacency matrix 
   - initialize a 2-dimensional array
   - iterate through the array and set the values 1 for the vertices adjacent to each vertex
   - adjacent vertices are the next 6 vertices on the board for any given vertex
  

# SNAKE AND LADDER FUNCTION











# DISPLAY GRAPH

* for adjacency list 
   -
* for adjacency matrix 
   - 


