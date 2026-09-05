//statement- Merge accounts that share common emails & return each user’s name followed by their sorted, unique emails


// (optimal) -using disjoint set t.c- O( (n+e)+(e4⍺)+(nloge) )  s.c- O(n + n + 2n)
class DisjointSet {
    vector<int> rank, parent, size; public:
    DisjointSet(int n) { // Constructor to initialize DSU
        rank.resize(n + 1, 0); parent.resize(n + 1); size.resize(n + 1);
        for(int i = 0; i <= n; i++) { parent[i] = i; size[i] = 1; } // Initialize every node
    } 
    
    int findUPar(int node) { // Function to find ultimate parent with path compression
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) { // Function to perform union by rank
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else { parent[ulp_v] = ulp_u; rank[ulp_u]++; }
    }

    void unionBySize(int u, int v) { // Function to perform union by size
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) { parent[ulp_u] = ulp_v; size[ulp_v] += size[ulp_u]; }
        else { parent[ulp_v] = ulp_u; size[ulp_u] += size[ulp_v]; }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& details) { // Function to merge accounts with common emails
    int n = details.size(); // Number of accounts
    DisjointSet ds(n); // Create Disjoint Set
    unordered_map<string, int> mapMailNode; // Map to store email -> account index

    for(int i = 0; i < n; i++) { // Step 1: Union accounts having common emails
        for(int j = 1; j < details[i].size(); j++) {
            string mail = details[i][j];

            if(mapMailNode.find(mail) == mapMailNode.end()) mapMailNode[mail] = i;
            else ds.unionBySize(i, mapMailNode[mail]);
        }
    }

    vector<vector<string>> mergedMail(n); // Step 2: Group emails under ultimate parent

    for(auto it : mapMailNode) mergedMail[ds.findUPar(it.second)].push_back(it.first);

    vector<vector<string>> ans; // Step 3: Prepare final merged result
    for(int i = 0; i < n; i++) {
        if(mergedMail[i].empty()) continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());

        vector<string> temp;
        temp.push_back(details[i][0]);

        for(auto& mail : mergedMail[i]) temp.push_back(mail);
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end()); // Sort final answer
    return ans;
}