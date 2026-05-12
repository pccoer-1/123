#include <iostream>
using namespace std;

int graph[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int color[4];
int m = 3; // Number of colors

// Check whether color can be used
bool isSafe(int node, int c)
{
    for (int i = 0; i < 4; i++)
    {
        if (graph[node][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool graphColoring(int node)
{
    if (node == 4)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(node, c))
        {
            color[node] = c;

            if (graphColoring(node + 1))
                return true;

            color[node] = 0; // Backtrack
        }
    }

    return false;
}

int main()
{
    if (graphColoring(0))
    {
        cout << "Solution Found:\n";

        for (int i = 0; i < 4; i++)
            cout << "Node " << i << " -> Color " << color[i] << endl;
    }
    else
    {
        cout << "No Solution";
    }

    return 0;
}