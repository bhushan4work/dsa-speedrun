// statement- Given an undirected graph, return a vector of all nodes by traversing the graph using dfs


//(optimal) t.c- O(v + e)  s.c- O(v)
void dfs(int v, vector<int> adj[],
         vector<int> &visited,
         vector<int> &result) {

    visited[v] = 1;   // Mark current node as visited
    result.push_back(v);  // Store node in result

    // Traverse all neighbours
    for (int u : adj[v]){
        if (!visited[u]){
            dfs(u, adj, visited, result);
        }
    }
}