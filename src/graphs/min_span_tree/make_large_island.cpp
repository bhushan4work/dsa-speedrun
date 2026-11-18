//statement- Given n x n binary matrix grid, it is allowed to change at most one 0 to 1. A group of connected 1s forms an island, where two 1s are connected if they share one of their sides.
//           Return size of largest island in grid after applying this operation


// (brute) t.c- O(n ^ 4)  s.c- O(n ^ 2)
int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) { // Count island area using DFS.
    int n = grid.size();
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 0 || visited[row][col] == 1) { // Stop for out-of-bounds, water, or visited cells.
        return 0;
    }
    visited[row][col] = 1; // Mark current cell as visited.
    int area = 1; // Start with area 1 for current cell.
    area += dfs(row - 1, col, grid, visited); // Explore top neighbor.
    area += dfs(row + 1, col, grid, visited); // Explore bottom neighbor.
    area += dfs(row, col - 1, grid, visited); // Explore left neighbor.
    area += dfs(row, col + 1, grid, visited); // Explore right neighbor.
    return area; // Return total connected area.
}
int largestCurrentIsland(vector<vector<int>>& grid) { // Compute largest island in current grid state.
    int n = grid.size();
    int best = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0)); // Track visited cells to prevent infinite loops.
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 1 && visited[row][col] == 0) { // Trigger DFS on unvisited land.
                best = max(best, dfs(row, col, grid, visited)); // Update maximum island size found.
            }
        }
    }
    return best;
}
int largestIsland(vector<vector<int>>& grid) { // Find max island area after flipping at most one 0 to 1.
    int n = grid.size();
    int answer = largestCurrentIsland(grid); // Base check without any flips.
    bool hasZero = false;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 0) { // Test each 0 individually.
                hasZero = true;
                grid[row][col] = 1; // Temporarily flip to land.
                answer = max(answer, largestCurrentIsland(grid)); // Check new largest island.
                grid[row][col] = 0; // Backtrack to original state.
            }
        }
    }
    if (!hasZero) { // If there were no 0s, whole grid is one island.
        return n * n;
    }
    return answer;
}



// (better) t.c- O(n ^ 2)  s.c- O(n ^ 2)
int dfs(int row, int col, vector<vector<int>>& grid, int islandId) { // Function to label one island and return area.
    int n = grid.size();
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != 1) { // Stop for invalid cells and non-land cells.
        return 0;
    }
    grid[row][col] = islandId; // Replace land with a unique island id to mark it as visited.
    int area = 1; // Count current cell and all connected land cells.
    area += dfs(row - 1, col, grid, islandId);
    area += dfs(row + 1, col, grid, islandId);
    area += dfs(row, col - 1, grid, islandId);
    area += dfs(row, col + 1, grid, islandId);
    return area;
}
int largestIsland(vector<vector<int>>& grid) { // Function to find largest island using component labels.
    int n = grid.size();
    unordered_map<int, int> areaById; // Maps island ID to its total area.
    int islandId = 2; // Start IDs from 2 to differentiate from 0 (water) and 1 (unvisited land).
    int answer = 0;
    bool hasZero = false;
    vector<int> deltaRow = {-1, 1, 0, 0};
    vector<int> deltaCol = {0, 0, -1, 1};
    for (int row = 0; row < n; row++) { // Label every existing island with a unique id.
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 1) {
                int area = dfs(row, col, grid, islandId);
                areaById[islandId] = area; // Store computed area for current island ID.
                answer = max(answer, area);
                islandId++; // Increment ID for next disjoint island.
            }
        }
    }
    for (int row = 0; row < n; row++) { // Try every zero and merge unique neighboring islands.
        for (int col = 0; col < n; col++) {
            if (grid[row][col] != 0) {
                continue;
            }
            hasZero = true;
            unordered_set<int> seen; // Use a set to avoid counting same adjacent island multiple times.
            int mergedArea = 1; // Start with area 1 for flipped zero itself.
            for (int dir = 0; dir < 4; dir++) { // Check all 4 adjacent directions.
                int nextRow = row + deltaRow[dir];
                int nextCol = col + deltaCol[dir];
                if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < n && grid[nextRow][nextCol] > 1) {
                    seen.insert(grid[nextRow][nextCol]); // Add valid adjacent island IDs to set.
                }
            }
            for (int id : seen) {
                mergedArea += areaById[id]; // Accumulate areas of all unique neighboring islands.
            }
            answer = max(answer, mergedArea); // Track max possible area after flipping this zero.
        }
    }
    if (!hasZero) { // Return full grid area when no zero exists.
        return n * n;
    }
    return answer; // Return maximum possible island area.
}



// (optimal) -using dsu with a set ds t.c- O(n ^ 2)  s.c- O(n ^ 2)
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) { // Find representative with path compression.
        return node;
    }
    parent[node] = findParent(parent[node], parent); // Path compression step.
    return parent[node];
}
void unite(int first, int second, vector<int>& parent, vector<int>& size) { // Merge two land components.
    int parentFirst = findParent(first, parent);
    int parentSecond = findParent(second, parent);
    if (parentFirst == parentSecond) { // Already in same component.
        return;
    }
    if (size[parentFirst] < size[parentSecond]) { // Union by size to keep tree flat.
        swap(parentFirst, parentSecond);
    }
    parent[parentSecond] = parentFirst;
    size[parentFirst] += size[parentSecond]; // Update size of new root.
}
int largestIsland(vector<vector<int>>& grid) { // Find largest island using DSU.
    int n = grid.size();
    int total = n * n;
    vector<int> parent(total);
    vector<int> size(total, 1);
    vector<int> deltaRow = {-1, 1, 0, 0};
    vector<int> deltaCol = {0, 0, -1, 1};
    bool hasZero = false;
    for (int node = 0; node < total; node++) { // Initialize each cell as a separate component.
        parent[node] = node;
    }
    for (int row = 0; row < n; row++) { // Merge adjacent land cells.
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 0) {
                hasZero = true;
                continue;
            }
            int current = row * n + col;
            for (int dir = 0; dir < 4; dir++) {
                int nextRow = row + deltaRow[dir];
                int nextCol = col + deltaCol[dir];
                if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < n && grid[nextRow][nextCol] == 1) { // Check bounds and if neighbor is land.
                    unite(current, nextRow * n + nextCol, parent, size);
                }
            }
        }
    }
    if (!hasZero) { // Return full grid size if no water exists to flip.
        return total;
    }
    int answer = 1;
    for (int row = 0; row < n; row++) { // Try every zero and combine neighboring DSU components.
        for (int col = 0; col < n; col++) {
            if (grid[row][col] != 0) {
                continue;
            }
            unordered_set<int> seen;
            int mergedArea = 1; // Base area of flipped cell itself.
            for (int dir = 0; dir < 4; dir++) {
                int nextRow = row + deltaRow[dir];
                int nextCol = col + deltaCol[dir];
                if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < n && grid[nextRow][nextCol] == 1) {
                    seen.insert(findParent(nextRow * n + nextCol, parent)); // Store unique parent roots of adjacent lands.
                }
            }
            for (int root : seen) { // Sum up sizes of adjacent distinct island components.
                mergedArea += size[root];
            }
            answer = max(answer, mergedArea);
        }
    }
    return answer;
}