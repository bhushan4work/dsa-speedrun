//statement- Given weighted, undirected, & connected graph of V vertices & E edges. task is to find sum of wt of edges of Min Spanning Tree


// (optimal) t.c- O(elogv)  s.c- O(v + e)
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap: {weight, node}
    vector<int> vis(V, 0);
    pq.push({0, 0}); // start from node 0 with weight 0
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue; // skip if node is already in MST

        vis[node] = 1; // add node to MST
        sum += wt; // add edge weight to MST total

        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edW = it[1];

            if (!vis[adjNode]) { // add unvisited adjacent nodes to min heap
                pq.push({edW, adjNode});
            }
        }
    }

    return sum; // return total weight of MST
}