//statement- Given Directed Graph with V vertices (Numbered from 0 to V-1) & E edges, Find no of strongly connected components in graph


// (optimal) t.c- O(v + e)  s.c- O(v + e)
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node); // Push the node into stack after visiting all neighbors
}

void dfs3(int node, vector<int> &vis, vector<int> adjT[]) { // Step 2: Perform DFS on transposed graph
    vis[node] = 1;
    for (auto it : adjT[node]) {
        if (!vis[it]) {
            dfs3(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[]) { // Function to find number of strongly connected components
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) { // Step 1: Do DFS to fill stack by finishing times
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> adjT[V]; // Step 2: Build the transpose graph
    for (int i = 0; i < V; i++) {
        vis[i] = 0; // reset visited
        for (auto it : adj[i]) {
            adjT[it].push_back(i); // reverse edge
        }
    }
    
    int scc = 0; // Step 3: Process stack to count SCCs
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            dfs3(node, vis, adjT);
        }
    }
    return scc;
}