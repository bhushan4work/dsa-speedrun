//statement- union by rank
// (optimal) t.c- O(4x) x = const
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);              // rank of each node
        parent.resize(n + 1);                // parent of each node

        for (int i = 0; i <= n; i++)
            parent[i] = i;                  // initially, every node is its own parent
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;                    // node is the ultimate parent

        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);             // ultimate parent of u
        int ulp_v = findUPar(v);             // ultimate parent of v

        if (ulp_u == ulp_v) return;         // already in the same component

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;           // attach smaller rank tree to larger
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;           // attach smaller rank tree to larger
        else {
            parent[ulp_v] = ulp_u;           // attach either tree to the other
            rank[ulp_u]++;                   // increase rank of the new parent
        }
    }
};



//statement- union by size
// (optimal) t.c- O(4x) x = const
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);              // rank of each node
        parent.resize(n + 1);                // parent of each node
        size.resize(n + 1);                  // size of each component

        for (int i = 0; i <= n; i++) {
            parent[i] = i;                  // initially, every node is its own parent
            size[i] = 1;                    // each component initially has size 1
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;                    // node is the ultimate parent

        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);             // ultimate parent of u
        int ulp_v = findUPar(v);             // ultimate parent of v

        if (ulp_u == ulp_v) return;         // already in the same component

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;           // attach smaller rank tree to larger
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;           // attach smaller rank tree to larger
        else {
            parent[ulp_v] = ulp_u;           // attach either tree to the other
            rank[ulp_u]++;                   // increase rank of the new parent
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);             // ultimate parent of u
        int ulp_v = findUPar(v);             // ultimate parent of v

        if (ulp_u == ulp_v) return;         // already in the same component

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;           // attach smaller component to larger
            size[ulp_v] += size[ulp_u];      // update size of the new component
        }
        else {
            parent[ulp_v] = ulp_u;           // attach smaller component to larger
            size[ulp_u] += size[ulp_v];      // update size of the new component
        }
    }
};