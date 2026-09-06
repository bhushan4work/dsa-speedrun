//statement- given n, m which means row & col of 2D matrix, arr of size k denoting no of operations. Matrix elements are 0 if its water or 1 if its land.
//           initially, matrix is all 0. arr has k operator(s) & each operator has 2 integers A[i][0], A[i][1] means that you can change cell from sea to island.
//           Return how many islands are there in matrix after each operation. return an arr of size k.
// Note: An island means grp of 1s such that they share a common side


// (optimal) -using disjoint set t.c- O(n * m)  s.c- O(n * m)
class DisjointSet {
    vector<int> rank, parent, size; public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0); parent.resize(n + 1); size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else { parent[ulp_v] = ulp_u; rank[ulp_u]++; }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) { parent[ulp_u] = ulp_v; size[ulp_v] += size[ulp_u]; }
        else { parent[ulp_v] = ulp_u; size[ulp_u] += size[ulp_v]; }
    }
};

bool isValid(int adjr, int adjc, int n, int m){  // Helper function to check if a cell is within bounds
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) { // Main function to process all operators and count number of islands
    DisjointSet ds(n * m); // Disjoint set to manage connected land cells
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    vector<int> ans;

    for(auto it : operators) {
        int row = it[0], col = it[1];
        if(vis[row][col] == 1) { 
            ans.push_back(cnt); 
            continue; // Skip if the cell is already land
        } 

        vis[row][col] = 1; cnt++; // Mark cell as land
        int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}; // Directions to check for adjacent cells (up, right, down, left)

        for(int ind = 0; ind < 4; ind++) {
            int adjr = row + dr[ind], adjc = col + dc[ind];

            if(isValid(adjr, adjc, n, m) && vis[adjr][adjc] == 1) {
                int nodeNo = row * m + col, adjNodeNo = adjr * m + adjc;

                if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) { 
                    cnt--; 
                    ds.unionBySize(nodeNo, adjNodeNo); 
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}