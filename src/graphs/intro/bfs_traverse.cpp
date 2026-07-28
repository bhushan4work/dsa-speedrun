//statement- Given an undirected graph, return a vector of all nodes by traversing the graph using bfs


//(optimal) t.c- O(v + e)  s.c- O(v)
void bfs(int start, vector<int> adj[],
         vector<int> &visited,
         vector<int> &result) {

    queue<int> q;

    visited[start] = 1;      // Mark starting node as visited
    q.push(start);           // Insert starting node into queue

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        result.push_back(v); // Store current node in result

        // Traverse all neighbours
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = 1;   // Mark neighbour as visited
                q.push(u);        // Insert neighbour into queue
            }
        }
    }
}