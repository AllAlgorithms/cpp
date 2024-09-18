// C/C++ M-colouring Problem using Backtracking
//
// The All ▲lgorithms Project

// https://github.com/allalgorithms/cpp
//
// Contributed by: Prayag Thakur
// Github: @PrAyAg9

// Problem Statement:
// Given an undirected graph and a number M, determine if the graph can be colored using at most M different colors such that no two adjacent vertices have the same color.

#include <iostream>
#include <vector>
using namespace std;

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &color, int c) {
    // Check for each adjacent vertex
    for (int i = 0; i < graph.size(); i++) {
        // If the vertex is adjacent and has the same color, return false
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// A recursive utility function to solve the M-coloring problem
bool solveMColoring(int v, const vector<vector<int>> &graph, vector<int> &color, int m) {
    // Base case: If all vertices are assigned a color, return true
    if (v == graph.size()) {
        return true;
    }

    // Try assigning each color from 1 to m
    for (int c = 1; c <= m; c++) {
        // Check if assigning color c to vertex v is safe
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign the color

            // Recursively assign colors to the rest of the vertices
            if (solveMColoring(v + 1, graph, color, m)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }
    return false; // If no color can be assigned, return false
}

// Function to solve the M-coloring problem
bool graphColoring(const vector<vector<int>> &graph, int m) {
    int V = graph.size();
    vector<int> color(V, 0); // Initialize all vertices with no color (0)

    // Call the solveMColoring function starting from the first vertex
    if (!solveMColoring(0, graph, color, m)) {
        cout << "Solution does not exist." << endl;
        return false;
    }

    // Print the solution
    cout << "Solution exists: Following are the assigned colors" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }
    return true;
}

int main() {
    // Example: A graph represented as an adjacency matrix
    // (1 means an edge between two vertices, 0 means no edge)
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    
    int m = 3; // Number of colors

    // Solve the M-Coloring problem
    graphColoring(graph, m);

    return 0;
}
