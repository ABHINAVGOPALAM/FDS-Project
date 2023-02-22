
# FUNCTIONS USED IN THE CODE


**create_board():**

 ##   creates the board as a graph by representing it as an adjacency list or adjacency matrix
 
   * it takes the struct node pointer array(board) as arguments   
   * craete a for loop from cell 1  to to the last cell
   * create another for loop inside the main for loop for adding the adjacent elements to the each vertex 
   * create a new node dynamically for each element and link it to the previous node in linkedlist
   * the board is created in the form of graph represented as adjacency list

**snakes():**

   * updates the already created board by adding  the snakes in the graph representation
   *  it takes the arguments head of the snake as start to the tail of the snake as end
   *  replaces the starting vertex of snake with ending vertex of snake wherever it occurs by using afor loop
   *  it replaces the  starting node of snake by making it as null

**ladders():**
    
   * updates the already created board by adding  the snakes in the graph representation
   *  it takes the arguments satrt of the ladder to the end destination of the ladder
   *  replaces the ending vertex of ladder with starting vertex of ladder wherever it occurs
   *  it replaces the  ending node of ladder by making it as null
    
**display_graph():**

   * displays the board in the form of graph represenation either in adjacency matrix or adjacency list
   * it atkes the arguments as borad 
   * by taking the for loop it prints the every vertex with all of its adjacent vertices
   
   
**bfs():**
    
    implements the breadth first search algorithm on the board and returns the minimum number of dice rolls required to reach the last square
    
**path():**

    gives the shortest path for reaching the last cell of the board
 
**enqueue():**

    inserts an element into the queue used while performing bfs 

**dequeue():**

    deletes and returns an element from the queue used while performing bfs 


# BFS

## implements the breadth first search algorithm on the board and returns the minimum number of dice rolls required to reach the last square

* Declare a queue and insert the starting vertex.

* Initialize a visited array and mark the starting vertex as visited.

* Follow the below process till the queue becomes empty:
   - Remove the first vertex of the queue.
   - Mark that vertex as visited
   - Insert all the unvisited neighbors of the vertex into the queue.


# CREATE GRAPH

## creates the board as a graph by representing it as an adjacency list or adjacency matrix

* for adjacency list 
   - initialize an array of self referencial structure and make every entry link to NULL
   - iterate through the list and add adjacent vertices for each vertex
   - adjacent vertices are the next 6 vertices on the board for any given vertex
* for adjacency matrix 
   - initialize a 2-dimensional array
   - iterate through the array and set the values 1 for the vertices adjacent to each vertex
   - adjacent vertices are the next 6 vertices on the board for any given vertex
  

# SNAKE AND LADDER FUNCTION

## updates the already created board by adding  the snakes and ladders in the graph representation
    
* iterates through the list backwards 6 nodes 
    - from the starting of a snake or
    - from the end of a ladder
* replace :
  - starting vertex of snake with ending vertex of snake wherever it occurs
  - ending vertex of ladder with starting vertex of ladder wherever it occurs
* remove the adjacent vertices of :
   - starting node of snake
   - ending node of ladder 

# DISPLAY GRAPH

## displays the board in the form of graph represenation either in adjacency matrix or adjacency list

* for adjacency list 
   - initialize a temporary variable and iterate through the entire list and display all the vertices and adjacent vertices
   - vertex : adjacent vertex -> adjecent vertex ->..... 
* for adjacency matrix 
   - display the 2-dimensional array in the form of a 0,1 matrix 


