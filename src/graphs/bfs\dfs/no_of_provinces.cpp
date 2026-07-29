// statement- Given undirected graph with V vertices. 2 vertices u & v belong to single province if there is path from u-to-v or v-to-u. Find no of provinces.
//            The graph is given as an 'n x n' matrix adj where adj[i][j] = 1 if ith city & jth city are directly connected, & adj[i][j] = 0 otherwise


//(optimal) using dfs t.c- O(n * n)  s.c- O(n + n)
void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
    vis[node] = 1;                                  // Mark current node as visited

    for (int j = 0; j < isConnected.size(); j++) {  // Traverse all adjacent nodes
        if (isConnected[node][j] == 1 && !vis[j]) { // If connected and unvisited
            dfs(j, isConnected, vis);               // Visit the neighbour
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();                     // Number of cities
    vector<int> vis(n, 0);                          // Visited array
    int provinces = 0;                              // Count of connected components

    for (int i = 0; i < n; i++) {                   // Visit every city
        if (!vis[i]) {                              // New province found
            provinces++;                            // Increase province count
            dfs(i, isConnected, vis);               // Traverse the entire province
        }
    }

    return provinces;                               // Return total provinces
}


//(optimal) using bfs t.c- O(n * n)  s.c- O(n + n)
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();                     // Number of cities
    vector<int> vis(n, 0);                          // Visited array
    int provinces = 0;                              // Count of connected components

    for (int i = 0; i < n; i++) {                   // Check every city

        if (!vis[i]) {                              // New province found
            provinces++;                            // Increase province count

            queue<int> q;
            q.push(i);                              // Start BFS from current city
            vis[i] = 1;                             // Mark it visited

            while (!q.empty()) {

                int node = q.front();               // Get front node
                q.pop();                            // Remove it from queue

                for (int j = 0; j < n; j++) {       // Traverse all neighbours

                    if (isConnected[node][j] == 1 && !vis[j]) { // Connected & unvisited
                        vis[j] = 1;                 // Mark neighbour visited
                        q.push(j);                  // Add neighbour to queue
                    }
                }
            }
        }
    }

    return provinces;                               // Return total provinces
}