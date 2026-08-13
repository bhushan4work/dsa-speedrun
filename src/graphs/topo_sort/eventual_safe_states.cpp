// statement- directed graph of V vertices & E edges is given in form of an adj list. Each node of graph is labeled with distinct integer in range 0 to V - 1. node is terminal node if there are no outgoing edges. 
//            node is safe node if every possible path starting from that node leads to terminal node. return an arr containing all safe nodes of graph. ans should be sorted in ascending order.
//note : node is safe if it doesnt contribute to or connect into a cycle


//(optimal) using dfs t.c- O(v + e)  s.c- O(v + 3n)
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
    vis[node] = 1; // mark as visited
    pathVis[node] = 1; // mark in current dfs path
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfsCheck(it, adj, vis, pathVis, check)) return true; // cycle found
        }
        else if(pathVis[it]) return true; // back edge means cycle
    }
    pathVis[node] = 0; // remove from current path
    check[node] = 1; // node is safe
    return false; // no cycle found
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> safeNodes;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) dfsCheck(i, adj, vis, pathVis, check);
    }
    for(int i = 0; i < V; i++) {
        if(check[i]) safeNodes.push_back(i);
    }
    return safeNodes;
}



//(optimal) using bfs toposort t.c- O(v + e + nlogn)  s.c- O(v + e)
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> adjRev(V); // reverse adjacency list
    vector<int> indegree(V, 0); // after reversing edges, incoming edges represent original outgoing edges
    for(int i = 0; i < V; i++) {
        for(auto it : graph[i]) {
            adjRev[it].push_back(i); // reverse the edge
            indegree[i]++; // count outgoing edges of the current node
        }
    }
    queue<int> q; // stores terminal nodes
    vector<int> safeNodes;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i); // terminal nodes are safe
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node); // current node is safe
        for(auto it : adjRev[node]) {
            indegree[it]--; // remove the edge to the safe node
            if(indegree[it] == 0) q.push(it); // node becomes safe
        }
    }
    sort(safeNodes.begin(), safeNodes.end()); // sort in ascending order
    return safeNodes;
}