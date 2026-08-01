// statement- Given an undirected graph with V vertices & E edges, check whether it contains any cycle or not

//(optimal) using bfs t.c- O(n + 2e + n)  s.c- O(n + n)
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;                                      // Mark source node as visited
    queue<pair<int, int>> q;                           // Queue stores {current node, parent node}
    q.push({src, -1});                                 // Push source node with no parent
    
    while (!q.empty()) {                               // Continue BFS until queue becomes empty
        
        int node = q.front().first;                    // Current node
        int parent = q.front().second;                 // Parent of current node
        q.pop();                                       // Remove current node from queue
        
        for (auto adjacentNode : adj[node]) {          // Traverse all adjacent nodes
            
            if (!vis[adjacentNode]) {                  // If neighbour is not visited
                vis[adjacentNode] = 1;                 // Mark neighbour as visited
                q.push({adjacentNode, node});          // Push neighbour with current node as its parent
            }
            
            else if (adjacentNode != parent) {         // Visited neighbour that is not parent
                return true;                           // Cycle detected
            }
        }
    }
    return false;                                      // No cycle found in this component
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};                                  // Initialize all vertices as unvisited
    
    for (int i = 0; i < V; i++) {                      // Check every connected component
        if (!vis[i]) {                                 // Start BFS only from unvisited nodes
            if (detect(i, adj, vis))                   // If a cycle is found
            return true;
        }
    }
    
    return false;                                      // No cycle exists in graph
}



//(optimal) using dfs t.c- O(n + 2e + n)  s.c- O(n + n)
bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;                                // Mark current node as visited

    for (int neighbor : adj[node]) {                  // Traverse all adjacent nodes
        if (!visited[neighbor]) {                     // If neighbour is not visited
            if (dfs(neighbor, node, adj, visited))    // Recur for neighbour
                return true;                          // Cycle found in DFS
        }

        else if (neighbor != parent) {                // Visited neighbour that is not the parent
            return true;                              // Cycle detected
        }
    }
    return false;                                     // No cycle found from this DFS path
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);                        // Mark all vertices as unvisited

    for (int i = 0; i < V; i++) {                     // Traverse all connected components
        if (!visited[i]) {                            // Start DFS from every unvisited node
            if (dfs(i, -1, adj, visited))             // If a cycle is found
                return true;
        }
    }

    return false;                                     // No cycle exists in the graph
}