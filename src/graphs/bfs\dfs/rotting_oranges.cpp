//statement- given m x n grid where each cell can have one of 3 values: 0 represents empty, 1 represents fresh orange, 2 represents rotten orange
//           Every minute, any fresh orange that is 4-directionally adjacent to rotten orange becomes rotten.
//           Return min no of min that must elapse until no cell has fresh orange. If this is impossible, return -1


//(optimal) t.c- O(n * n * 4)  s.c- O(n * n)
int orangesRotting(vector<vector<int>>& grid) {    
    if (grid.empty()) return 0; // If the grid is empty, return 0 as no oranges exist
    
    // Get number of rows, columns in grid
    int m = grid.size();
    int n = grid[0].size();

    int days = 0; // Var to store no of minutes passed
    int tot = 0; // Var to store total no of oranges (fresh + rotten)
    int cnt = 0; // Var to cnt how many oranges became rotten during process

    queue<pair<int, int>> rotten; // Queue to store positions of currently rotten oranges

    // Traverse grid to cnt total oranges & push rotten ones to queue
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            
            if (grid[i][j] != 0){ // If cell is not empty (i.e has fresh or rotten orange)
                tot++; // Count it as valid orange
            }

            if (grid[i][j] == 2) { // If it's rotten orange, add its position to queue
                rotten.push({i, j});
            }
        }
    }

    // Arrays to explore 4 directions: right, left, down, up
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // BFS traversal until all possible fresh oranges are rotted
    while (!rotten.empty()) {
        int k = rotten.size(); // No of rotten oranges to process at this min
        cnt += k; // Add these many oranges to count of rotted oranges

        // Process all rotten oranges at this time step
        while (k--) {
            
            // Get front orange from queue
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            // Check all 4 directions
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i]; // New x-coordinate
                int ny = y + dy[i]; // New y-coordinate

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1){ // Skip invalid coord or already rotten/empty cells
                    continue;
                }

                grid[nx][ny] = 2; // Mark fresh orange as rotten

                rotten.push({nx, ny}); // Add its position to queue to process in next min
            }
        }

        // If new oranges were added to queue, increase time
        if (!rotten.empty()){
            days++;
        }
    }

    return tot == cnt ? days : -1; // If all oranges are rotted, return total min passed. Otherwise, some fresh oranges are left unreachable, return -1
}