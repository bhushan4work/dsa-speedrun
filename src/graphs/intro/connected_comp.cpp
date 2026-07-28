// statement- Given undirected Graph consists of V vertices numbered from 0 to V-1 & E edges. The ith edge is represented by [ai,bi], denoting edge between vertex ai & bi.
//            We say 2 vertices u & v belong to same component if there is path from u to v or v to u. Find no of connected components in graph.
//            A connected comp is subgraph in which there exists path betw any 2 vertices, & no vertex of subgraph shares an edge with vertex outside of subgraph


//(optimal) t.c- O(v + e)  s.c- O(v + e)
int countComponents(int V, vector<vector<int>> &edges){
    // Create adjacency list from edge list
    vector<vector<int>> adj(V);
    for (auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> visited(V, 0);  // Vector to keep track of visited nodes
    int components = 0; // Variable to cnt no of connected components

    for (int i = 0; i < V; ++i){
        // If the node is not visited, it's a new component
        if (!visited[i]){
            components++;

            // Start BFS from this node
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            // Perform BFS traversal
            while (!q.empty()){
                int node = q.front();
                q.pop();

                // Visit all unvisited neighbors
                for (auto &nbr : adj[node]){
                    if (!visited[nbr]){
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }
    }

    return components; // Return the total number of connected components
}