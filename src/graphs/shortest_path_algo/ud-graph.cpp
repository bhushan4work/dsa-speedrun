//statement- Given Undirected Graph having unit wt, find shortest path from source to all other nodes. we have assumed source vertex to be ‘0’. 
//           If vertex is unreachable from source node, then return -1 for that vertex 


//(optimal) t.c- O(v + 2e)  s.c- O(v + 2e)
vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
    vector<int> adj[N];                              // create adjacency list

    for (auto it : edges) {                          // build undirected graph
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int dist[N];                                     // store shortest distances
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;                               // initialize as infinity

    dist[src] = 0;                                   // distance of source = 0
    queue<int> q;
    q.push(src);                                     // start BFS from source

    while (!q.empty()) {
        int node = q.front();                        // get current node
        q.pop();

        for (auto it : adj[node]) {                  // visit all neighbors
            if (dist[node] + 1 < dist[it]) {         // found a shorter path
                dist[it] = dist[node] + 1;           // update shortest distance
                q.push(it);                          // process neighbor later
            }
        }
    }

    vector<int> ans(N, -1);                          // -1 for unreachable nodes

    for (int i = 0; i < N; i++) {
        if (dist[i] != 1e9)                          // if node is reachable
            ans[i] = dist[i];                        // store its shortest distance
    }

    return ans;                                      // return shortest distances
}
