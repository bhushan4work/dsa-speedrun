// Disjoint Set Union (DSU) - Union by Rank
// t.c : O(alpha(n)) amortized per operation, approximately O(1)
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  // Rank of each node
        parent.resize(n + 1);   // Parent of each node

        for (int i = 0; i <= n; i++) {
            parent[i] = i;      // Initially, every node is its own parent
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;  // Node is the ultimate parent

        return parent[node] = findUPar(parent[node]); // Path compression: directly connect node to ultimate parent
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Ultimate parent of u
        int ulp_v = findUPar(v);  // Ultimate parent of v

        if (ulp_u == ulp_v)
            return;  // Already belong to the same component

        // Attach the tree with smaller rank to the tree with larger rank
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u; // Both have the same rank, so attach either tree to the other
            rank[ulp_u]++;  // Rank increases because the tree height increases
        }
    }
};



// Disjoint Set Union (DSU) - Union by Size
// t.c : O(alpha(n)) amortized per operation, approximately O(1)
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Initially, every node is its own parent
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;  // Node is the ultimate parent

        return parent[node] = findUPar(parent[node]);  // Path compression: directly connect node to ultimate parent
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);  // Ultimate parent of u
        int ulp_v = findUPar(v);  // Ultimate parent of v

        if (ulp_u == ulp_v)
            return;  // Already belong to the same component

        // Attach the smaller component to the larger component
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Update size of the new component
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Update size of the new component
        }
    }
};