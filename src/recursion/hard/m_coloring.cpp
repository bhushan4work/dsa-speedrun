// statement- Given int M, undirected graph with N vertices (0 indexed), E edges. determine whether graph can be coloured with a max of M colors so that no 2 of
//            its adjacent vertices have same color. colouring a graph is giving each vertex a diff color. If possible then return true else return false


// (optimal) t.c- O(m ^ n)  s.c- O(n)
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) { // Check all adjacent nodes to see if they have the same color.
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    
    return true; // Safe to color the current node with 'col'.
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if (node == N) { // Base case: If all nodes are colored, return true.
        return true;
    }

    for (int i = 1; i <= m; i++) { // Try all available 'm' colors for the current node.
        if (isSafe(node, color, graph, N, i)) { // Check if it is safe to assign color 'i'.
            color[node] = i; // Assign the color.
            if (solve(node + 1, color, m, N, graph)) { // Recursively try to color the next node.
                return true;
            }

            color[node] = 0; // Backtrack: Remove the color if it doesn't lead to a solution.
        }
    }

    return false; // Return false if no color can be assigned.
}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = {0}; // Initialize the color array with 0 (uncolored).
    if (solve(0, color, m, N, graph)) { // Start coloring from node 0.
        return true;
    }

    return false;
}