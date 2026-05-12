Your code is mostly correct and should compile successfully.
There are no major syntax errors, but a few improvements are needed for:

* cleaner BFS implementation
* proper resetting of visited nodes
* avoiding recursion risk in BFS
* better readability

# Corrected and Improved Code

```cpp
#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Graph{
public:

    map<int, list<int>> adjList;
    map<int, bool> visited;

    // Function to add edge
    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Undirected graph
    }

    // DFS Traversal
    void DFS(int node){

        // Mark node as visited
        visited[node] = true;

        // Print current node
        cout << node << " ";

        // Visit all neighbours
        for(int neighbour : adjList[node]){

            // If not visited
            if(!visited[neighbour]){
                DFS(neighbour);
            }
        }
    }

    // BFS Traversal
    void BFS(int start){

        queue<int> q;

        // Mark start node visited
        visited[start] = true;

        // Push start node
        q.push(start);

        while(!q.empty()){

            // Get front node
            int node = q.front();
            q.pop();

            // Print node
            cout << node << " ";

            // Traverse neighbours
            for(int neighbour : adjList[node]){

                // If not visited
                if(!visited[neighbour]){

                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    // Reset visited map
    void resetVisited(){
        visited.clear();
    }
};

int main(){

    Graph g;

    // Create graph
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,6);

    int ch;

    cout << "Enter 0 for DFS and 1 for BFS: ";
    cin >> ch;

    if(ch == 0){

        cout << "DFS Traversal: ";
        g.DFS(0);
    }
    else{

        g.resetVisited();

        cout << "BFS Traversal: ";
        g.BFS(0);
    }

    return 0;
}
```

---

# Output Example

## DFS

```text
Enter 0 for DFS and 1 for BFS: 0
DFS Traversal: 0 1 3 4 5 2 6
```

---

## BFS

```text
Enter 0 for DFS and 1 for BFS: 1
BFS Traversal: 0 1 2 3 6 4 5
```

---

# Explanation of Code

# 1. Header Files

```cpp
#include<iostream>
#include<list>
#include<map>
#include<queue>
```

Used for:

* input/output
* adjacency list
* visited map
* BFS queue

---

# 2. Graph Representation

```cpp
map<int, list<int>> adjList;
```

Stores graph as adjacency list.

Example:

```text
0 -> 1 2 3
1 -> 0 3
```

---

# 3. addEdge()

```cpp
void addEdge(int src, int dest)
```

Adds connection between two nodes.

Since graph is undirected:

```cpp
adjList[src].push_back(dest);
adjList[dest].push_back(src);
```

---

# 4. DFS (Depth First Search)

```cpp
void DFS(int node)
```

Algorithm:

1. Visit node
2. Mark visited
3. Recursively visit neighbours

Uses recursion and stack memory.

Traversal style:

```text
Go deep first
```

---

# 5. BFS (Breadth First Search)

```cpp
void BFS(int start)
```

Algorithm:

1. Push node into queue
2. Visit front node
3. Push neighbours
4. Repeat

Uses queue.

Traversal style:

```text
Level by level
```

---

# Difference Between DFS and BFS

| Feature        | DFS             | BFS                    |
| -------------- | --------------- | ---------------------- |
| Data Structure | Stack/Recursion | Queue                  |
| Traversal      | Depth-wise      | Level-wise             |
| Memory         | Less            | More                   |
| Shortest Path  | No              | Yes (unweighted graph) |

---

# Time Complexity

For both:

```text
O(V + E)
```

Where:

* V = vertices
* E = edges

---

# Viva Questions and Answers

# 1. What is a graph?

A graph is a non-linear data structure consisting of:

* vertices (nodes)
* edges (connections)

---

# 2. What is DFS?

DFS stands for Depth First Search.

It traverses deeply into a graph before backtracking.

---

# 3. What is BFS?

BFS stands for Breadth First Search.

It visits nodes level by level.

---

# 4. Which data structure is used in BFS?

Queue.

---

# 5. Which data structure is used in DFS?

Stack or recursion stack.

---

# 6. What is adjacency list?

A graph representation where each node stores its neighbours.

---

# 7. Why is visited array/map needed?

To avoid revisiting nodes and infinite loops.

---

# 8. Time complexity of BFS and DFS?

O(V+E)

---

# 9. Which traversal finds shortest path?

BFS in unweighted graphs.

---

# 10. Difference between tree and graph?

| Tree      | Graph               |
| --------- | ------------------- |
| No cycles | May contain cycles  |
| Connected | May be disconnected |
| n-1 edges | Any number of edges |

---

# 11. What is recursion?

A function calling itself.

---

# 12. What is queue?

FIFO data structure:

* First In First Out

---

# 13. What is map in C++?

Associative container storing key-value pairs.

---

# 14. Why use adjacency list instead of matrix?

Adjacency list saves memory for sparse graphs.

---

# 15. Applications of BFS and DFS

DFS:

* cycle detection
* topological sorting

BFS:

* shortest path
* web crawling
* social networks
