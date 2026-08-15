//statement- Given Directed Acyclic Graph of N vertices from 0 to N-1 & M edges & 2D Integer arr edges, where there is directed edge from vertex edge[i][0] to vertex edge[i][1] with dist of edge[i][2] for all i.
//           Find shortest path from source vertex to all vertices & if it is impossible to reach any vertex, then return -1 for that vertex. source vertex is assumed to be 0


//(optimal) -using toposort(dfs) -> relaxed the nodes t.c- O(n + m)  s.c- O(n + m)
void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st) { // topo sort first so we can process each node only after its prev nodes are processed
    vis[node] = 1;                                  // mark current node as visited

    for (auto it : adj[node]) {
        int v = it.first;                            // get neighboring node
        if (!vis[v])
            topoSort(v, adj, vis, st);               // visit unvisited neighbor
    } 

    st.push(node);                                   // add node after processing all neighbors
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    vector<pair<int,int>> adj[N];                    // adjacency list: {neighbor, weight}

    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});                   // store directed edge with its weight
    }

    int vis[N] = {0};                                // track visited nodes
    stack<int> st;                                   // stores nodes in topological order

    for (int i = 0; i < N; i++) {
        if (!vis[i])
            topoSort(i, adj, vis, st);               // create topological ordering using DFS
    }

    vector<int> dist(N, 1e9);                        // initialize all distances as infinity
    dist[0] = 0;                                     // source node is 0, so its distance is 0

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] == 1e9)
            continue;                                // skip nodes unreachable from the source

        for (auto it : adj[node]) {
            int v = it.first;                        // get neighboring node
            int wt = it.second;                      // get edge weight

            if (dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;           // relax edge if a shorter path is found
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9)
            dist[i] = -1;                            // mark unreachable nodes as -1
    }

    return dist;                                     // return shortest distances from source
}