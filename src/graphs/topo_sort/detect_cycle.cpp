// statement- Given a Directed Graph with V vertices & E edges, check whether it contains any cycle or not using BFS

//(optimal) using bfs\kahn's algo t.c- O(v + e)  s.c- O(v + e)
bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);   // Store in-degrees of all nodes
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;    // Queue for nodes with 0 in-degree
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int count = 0;   // Count visited nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // Reduce in-degree of neighbors
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count != V; // If count != V, cycle exists
}