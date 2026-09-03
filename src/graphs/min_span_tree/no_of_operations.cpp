//statement- given graph with n vertices & m edges. remove 1 edge from anywhere & add that edge betn any 2 vertices in 2 operation.
//           Find min no of operations that will be required to make graph connected. If its not possible to make graph connected, return -1


// (optimal) -using disjoint set t.c- O(n + m * ⍺(n))  s.c- O(n)
class DSU { 
    public:
    vector<int> parent, rank;
    DSU(int n) { // Initialize DSU
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i; // Self-parent initially
    }

    int find(int x) { // Path compression
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) { // Union by rank
        int px = find(x), py = find(y);
        if(px == py) return; // Already connected
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else { parent[py] = px; rank[px]++; }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n - 1) return -1; // Need at least n-1 edges to connect n nodes

    DSU dsu(n);

    for(auto& edge : connections) dsu.unite(edge[0], edge[1]); // Build components

    unordered_set<int> components;
    for(int i = 0; i < n; i++) components.insert(dsu.find(i)); // Count unique roots

    return components.size() - 1; // Min edges needed is components - 1
}