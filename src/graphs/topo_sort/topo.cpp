// statement- Given an undirected graph with V vertices & E edges, check whether it contains any cycle or not


//(optimal) using dfs t.c- O(v + e)  s.c- O(v + e)
void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;                                      // Mark the current node as visited

    for (auto it : adj[node]) {                         // Explore all neighbors of this node
        if (!vis[it]) {                                 // If the neighbor is not visited
            dfs(it, adj, vis, st);                      // Recursively perform DFS
        }
    }

    st.push(node);                                      // Push node after visiting all neighbors
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);                              // Create a visited array
    stack<int> st;                                      // Stack for finishing order

    for (int i = 0; i < V; i++) {                       // Perform DFS from each vertex

        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;                                    // Prepare the result array

    while (!st.empty()) {
        ans.push_back(st.top());                        // Add the top element to the result
        st.pop();                                       // Remove the top element
    }

    return ans;                                         // Return the topological ordering
}


    
//(optimal) using bfs\kahn's algo t.c- O(v + e)  s.c- O(v + e)
vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);                         // Create a vector to store the in-degree

    for (int i = 0; i < V; i++) {                       // Loop through all vertices
        for (auto it : adj[i]) {                        // Traverse all adjacent vertices
            indegree[it]++;                             // Increase in-degree of the connected vertex
        }
    }

    queue<int> q;                                       // Create a queue for vertices with in-degree zero
    for (int i = 0; i < V; i++) {                       // Loop through all vertices
        if (indegree[i] == 0) {                         // If in-degree is zero
            q.push(i);                                  // Add vertex to the queue
        }
    }

    vector<int> topo;                                   // Vector to store the topological order
    while (!q.empty()) {                                // Process until the queue is empty
        int node = q.front();                           // Get the front vertex
        q.pop();                                        // Remove the front vertex
        topo.push_back(node);                           // Add vertex to the topological order

        for (auto it : adj[node]) {                     // Traverse adjacent vertices
            indegree[it]--;                             // Reduce in-degree of adjacent vertex

            if (indegree[it] == 0) {                    // If in-degree becomes zero
                q.push(it);                             // Push vertex into the queue
            }
        }
    }

    return topo;                                        // Return the topological ordering
}