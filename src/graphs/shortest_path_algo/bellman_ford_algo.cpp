//statement- Given a weighted, directed & connected graph of V vertices & E edges, Find shortest dist of all vertices from src vertex S.
//           Note: If Graph contains -ve cycle then return an arr consisting of only -1


//(optimal) t.c- O(v * e)  s.c- O(v)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++) {

        for (auto it : edges) {
            int u = it[0]; //Starting point of the edge
            int v = it[1]; //Ending point of the edge
            int wt = it[2]; //Edge weight

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto it : edges) { // Nth relaxation to check negative cycle
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return { -1};
        }
    }
    return dist;
}