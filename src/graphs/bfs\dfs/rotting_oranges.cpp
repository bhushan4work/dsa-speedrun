//statement- given m x n grid where each cell can have one of 3 values: 0 represents empty, 1 represents fresh orange, 2 represents rotten orange
//           Every minute, any fresh orange that is 4-directionally adjacent to rotten orange becomes rotten.
//           Return min no of min that must elapse until no cell has fresh orange. If this is impossible, return -1


//(optimal) - used bfs here as we need min-time thru level traverse t.c- O(n * n * 4)  s.c- O(n * n)
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();                          // Number of rows
    int n = grid[0].size();                       // Number of columns

    queue<pair<int, int>> q;                      // Stores rotten oranges
    int fresh = 0;                                // Count of fresh oranges
    int minutes = 0;                              // Minutes passed

    // Traverse the grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 2)
                q.push({i, j});                   // Add rotten orange to queue

            else if (grid[i][j] == 1)
                fresh++;                          // Count fresh oranges
        }
    }

    // No fresh oranges present
    if (fresh == 0) return 0;

    int dx[4] = {-1, 1, 0, 0};                    // Row directions
    int dy[4] = {0, 0, -1, 1};                    // Column directions

    // Multi-source BFS
    while (!q.empty()) {

        int size = q.size();                      // Rotten oranges for current minute

        while (size--) {

            int x = q.front().first;              // Current row
            int y = q.front().second;             // Current column
            q.pop();

            // Visit all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];               // New row
                int ny = y + dy[i];               // New column

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) {// Skip invalid or non-fresh cells
                    continue;
                }

                grid[nx][ny] = 2;                 // Rot the fresh orange
                fresh--;                          // One less fresh orange
                q.push({nx, ny});                 // Process it in next minute
            }
        }

        if (!q.empty()) minutes++; // Increase time only if new oranges will be processed
    }

    return (fresh == 0) ? minutes : -1;           // Return answer
}