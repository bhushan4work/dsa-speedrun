//statement- n stones at some integer coordinate points on 2D plane. Each coordinate point may have at most 1 stone. remove some stones. stone can be removed if it shares either same row or same col as another stone that has not been removed.
//           Given arr of stones of length n where stones[i] = [xi, yi] represents location of ith stone, return max possible no of stones that you can remove


// (optimal) -using disjoint set t.c- O(n + ⍺(n))  s.c- O(n)
class DSU { public:
    unordered_map<int, int> parent;

    int find(int x) { // Find ultimate parent
        if(parent.find(x) == parent.end()) parent[x] = x; // Self-parent if new

        if(x != parent[x]) parent[x] = find(parent[x]); // Path compression

        return parent[x];
    }

    void unite(int x, int y) { // Connect two nodes
        parent[find(x)] = find(y);
    }
};

int removeStones(vector<vector<int>>& stones) {
    DSU dsu;
    for(auto& stone : stones) dsu.unite(stone[0], stone[1] + 10001); // Connect row and col (offset col by 10001)

    unordered_set<int> components;
    for(auto& stone : stones) components.insert(dsu.find(stone[0])); // Count unique components

    return stones.size() - components.size(); // Max removed = total stones - components
}