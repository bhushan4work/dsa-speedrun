//statement- given 2D matrix grid of size r * c, where each cell contains either 0 or 1. Find no of distinct islands where grp of connected
//           1s (horizontally or vertically) forms an island. 2 islands are considered to be same if & only if 1 island is equal to another (not rotated or reflected)


// (brute) t.c- O(r * c)  s.c- O(r * c)
void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>>& grid, vector<string>& shape) { // Function to collect one island signature using DFS.
    int rows = grid.size();
    int cols = grid[0].size();
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) { // Stop for invalid cells and water cells.
        return;
    }
    grid[row][col] = 0; // Mark current land cell as visited.
    shape.push_back(to_string(row - baseRow) + ":" + to_string(col - baseCol)); // Store relative position from island start to ensure uniqueness.
    dfs(row - 1, col, baseRow, baseCol, grid, shape); // Visit all four neighboring cells.
    dfs(row + 1, col, baseRow, baseCol, grid, shape);
    dfs(row, col - 1, baseRow, baseCol, grid, shape);
    dfs(row, col + 1, baseRow, baseCol, grid, shape);
}
int countDistinctIslands(vector<vector<int>>& grid) { // Function to count distinct islands using DFS.
    int rows = grid.size();
    int cols = grid[0].size();
    set<string> uniqueShapes; // Set keeps only the unique island signatures.
    for (int row = 0; row < rows; row++) { // Scan every cell using nested loops.
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 1) { // Trigger DFS only for unvisited land.
                vector<string> shape;
                dfs(row, col, row, col, grid, shape);
                string signature = ""; // Build a comparable string signature for the current island.
                for (string& point : shape) {
                    signature += point + "|";
                }
                uniqueShapes.insert(signature); // Store only unique signatures.
            }
        }
    }
    return uniqueShapes.size(); // Return count of unique shapes.
}



// (optimal) t.c- O(r * c)  s.c- O(r * c)
int countDistinctIslands(vector<vector<int>>& grid) { // Function to count distinct islands using BFS.
    int rows = grid.size();
    int cols = grid[0].size();
    set<string> uniqueShapes; // Set to store unique island signatures.
    vector<int> deltaRow = {-1, 1, 0, 0};
    vector<int> deltaCol = {0, 0, -1, 1};
    for (int row = 0; row < rows; row++) { // Scan every cell using nested loops.
        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 0) { // Skip water or already visited cells.
                continue;
            }
            vector<string> shape;
            queue<pair<int, int>> q;
            grid[row][col] = 0; // Mark starting cell as visited.
            q.push({row, col});
            while (!q.empty()) { // Process one complete island.
                auto cell = q.front();
                q.pop();
                int currentRow = cell.first;
                int currentCol = cell.second;
                shape.push_back(to_string(currentRow - row) + ":" + to_string(currentCol - col)); // Store relative position from island start.
                for (int dir = 0; dir < 4; dir++) { // Visit all four neighboring cells.
                    int nextRow = currentRow + deltaRow[dir];
                    int nextCol = currentCol + deltaCol[dir];
                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols && grid[nextRow][nextCol] == 1) { // Check boundaries and if it is land.
                        grid[nextRow][nextCol] = 0; // Mark neighbor as visited.
                        q.push({nextRow, nextCol});
                    }
                }
            }
            string signature = ""; // Build a comparable string signature.
            for (string& point : shape) {
                signature += point + "|";
            }
            uniqueShapes.insert(signature); // Store only unique signatures.
        }
    }
    return uniqueShapes.size(); // Return count of unique shapes.
}