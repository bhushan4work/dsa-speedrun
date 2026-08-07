// statement- Given m x n 2D binary grid which represents map of '1's (land) and '0's (water), return no of islands. An island is surrounded by water & is formed by connecting adj lands horizontally or vertically.
//            You may assume all four edges of grid are all surrounded by water


//(optimal) using dfs t.c- O(n * m)  s.c- O(n * m + n * m)
void dfs(int row, int col,
         vector<vector<char>>& grid,
         vector<vector<int>>& vis) {

    vis[row][col] = 1;                                    // Mark current cell as visited

    int drow[] = {-1, 0, 1, 0};                           // Row directions: Up, Right, Down, Left
    int dcol[] = {0, 1, 0, -1};                           // Column directions: Up, Right, Down, Left

    for (int i = 0; i < 4; i++) {                         // Explore all four directions

        int nrow = row + drow[i];                         // Compute next row
        int ncol = col + dcol[i];                         // Compute next column

        if (nrow >= 0 && nrow < grid.size() &&            // Check row boundary
            ncol >= 0 && ncol < grid[0].size() &&         // Check column boundary
            !vis[nrow][ncol] &&                           // Visit only unvisited cells
            grid[nrow][ncol] == '1') {                    // Continue only on land

            dfs(nrow, ncol, grid, vis);                   // DFS on adjacent land
        }
    }
}

int numIslands(vector<vector<char>>& grid) {

    int n = grid.size();                                  // Number of rows
    int m = grid[0].size();                               // Number of columns

    vector<vector<int>> vis(n, vector<int>(m, 0));        // Visited matrix
    int islands = 0;                                      // Stores total number of islands

    for (int i = 0; i < n; i++) {                         // Traverse every row
        for (int j = 0; j < m; j++) {                     // Traverse every column

            if (grid[i][j] == '1' && !vis[i][j]) {        // Found an unvisited island
                islands++;                                // Count this island
                dfs(i, j, grid, vis);                     // Visit all connected land
            }
        }
    }

    return islands;                                       // Return total number of islands
}