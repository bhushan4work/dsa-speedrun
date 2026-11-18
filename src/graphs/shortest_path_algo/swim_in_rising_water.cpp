//statement- given an n × n matrix grid where grid[i][j] is unique elevation of cell (i, j). Rain starts falling at time t = 0. At any later time t ≥ 0, every cell is covered by water to depth t.
//           u may move 4-directionally (up ⇧, down ⇩, left ⇦, right ⇨) betw adjacent cells instantaneously if elevations of both cells are ≤ t. (Think of t as “how high u’re willing to climb”:
//           by time t every elevation ≤ t is underwater and swimmable.) Starting from top-left cell (0, 0), return min time t at which u can reach bottom-right cell (n − 1, n − 1)


//(optimal) -dijkstras using pq t.c- O(n^2 * logn)  s.c- O(n^2)
int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(); // Get grid dimensions to check boundaries.
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; // Min-heap to always expand path with smallest max elevation.
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // 4-way directional moves (right, down, left, up).
    set<pair<int,int>> seen; // Set to track visited cells to avoid cycles.
    pq.push({grid[0][0], 0, 0}); // Push initial state {current_max_elevation, row, col}.
    while (!pq.empty()) { // Process until all reachable nodes are visited.
        auto [max_d, r, c] = pq.top(); // Get path with current min bottleneck.
        pq.pop(); // Remove it from queue.
        if (seen.count({r, c})) { // Skip if cell has already been processed.
            continue;
        }
        seen.insert({r, c}); // Mark current cell as visited.
        if (r == m - 1 && c == n - 1) { // If we reached bottom-right destination, return answer.
            return max_d;
        }
        for (auto [dr, dc] : directions) { // Explore all 4 adjacent neighboring cells.
            int nr = r + dr, nc = c + dc; // Calculate new row and column indices.
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen.count({nr, nc})) { // Ensure within grid bounds and not yet visited.
                int new_d = max(max_d, grid[nr][nc]); // new bottleneck is max of path so far and new cell's height.
                pq.push({new_d, nr, nc}); // Push valid neighbor into priority queue.
            }
        }
    }
    return -1; // Fallback if destination is somehow unreachable.
}



//(optimal) -bs with dfs t.c- O(n^2 * logn)  s.c- O(n^2)
int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(); // Get grid dimensions to check boundaries.
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // 4-way directional moves (right, down, left, up).
    auto dfs = [&](int r, int c, int mid, vector<vector<bool>>& seen, auto& dfs_ref) -> bool { // DFS to check if path exists for given max elevation.
        if (r == m - 1 && c == n - 1) { // If destination reached, path is valid.
            return true;
        }
        seen[r][c] = true; // Mark current cell as visited.
        for (auto [dr, dc] : directions) { // Explore all 4 adjacent neighbors.
            int nr = r + dr, nc = c + dc; // Calculate new row and column indices.
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc]) { // Check bounds and if unvisited.
                if (grid[nr][nc] <= mid) { // Only proceed if neighbor's elevation is within allowed maximum (mid).
                    if (dfs_ref(nr, nc, mid, seen, dfs_ref)) { // Recursively search from neighbor.
                        return true;
                    }
                }
            }
        }
        return false; // Return false if no valid path reaches destination.
    };
    auto possible = [&](int mid) { // Helper to setup DFS for a specific threshold.
        if (grid[0][0] > mid) { // If starting cell itself is strictly greater than mid, it's impossible.
            return false;
        }
        vector<vector<bool>> seen(m, vector<bool>(n, false)); // Create visited tracking grid.
        return dfs(0, 0, mid, seen, dfs); // Start DFS from top-left corner.
    };
    int lo = grid[0][0], hi = 0; // Initialize binary search range.
    for (auto& row : grid) { // Find maximum elevation in grid for upper bound.
        for (int val : row) {
            hi = max(hi, val);
        }
    }
    while (lo < hi) { // Binary search for min possible bottleneck time/elevation.
        int mid = lo + (hi - lo) / 2; // Calculate midpoint elevation.
        if (possible(mid)) { // If it's possible to reach end with this max elevation.
            hi = mid; // Try to find a smaller possible elevation.
        } else {
            lo = mid + 1; // Otherwise, we must increase our threshold.
        }
    }
    return lo; // 'lo' will be min required elevation.
}



//(optimal) -mst algo(union-find) t.c- O(n^2 * logn)  s.c- O(n^2)
int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(); // Get grid dimensions to calculate 1D coordinates.
    vector<tuple<int,int,int>> edges; // Store edges as {max_weight_of_two_nodes, node1, node2}.
    for (int i = 0; i < m; i++) { // Iterate through all cells to build graph edges.
        for (int j = 0; j < n; j++) {
            if (i > 0) { // Connect current cell to top cell.
                edges.push_back({max(grid[i][j], grid[i-1][j]), i*n+j, (i-1)*n+j});
            }
            if (j > 0) { // Connect current cell to left cell.
                edges.push_back({max(grid[i][j], grid[i][j-1]), i*n+j, i*n+j-1});
            }
        }
    }
    sort(edges.begin(), edges.end()); // Sort all edges by their weights in ascending order.
    vector<int> parent(m * n); // Array for Disjoint Set Union (DSU) to track connected components.
    iota(parent.begin(), parent.end(), 0); // Initialize each cell as its own parent.
    function<int(int)> find = [&](int x) { // Find function with path compression.
        if (parent[x] == x) { // If it is root of set.
            return x; 
        }
        return parent[x] = find(parent[x]); // Compress path for faster future queries.
    };
    auto unite = [&](int x, int y) { // Union function to connect two components.
        parent[find(x)] = find(y); // Make root of x point to root of y.
    };
    for (auto [cost, u, v] : edges) { // Process edges from lowest weight to highest.
        unite(u, v); // Connect two nodes of current edge.
        if (find(0) == find(m*n-1)) { // Check if start (0,0) and end (m-1,n-1) are now connected.
            return cost; // weight of this edge is min required bottleneck.
        }
    }
    return grid[0][0]; // Edge case fallback for a 1x1 grid.
}