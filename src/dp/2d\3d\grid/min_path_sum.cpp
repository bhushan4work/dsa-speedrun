//statement- Given m x n grid filled with non-negative no, find path from top-left to bottom-right, which minimizes sum of all no along its path.
//Note: You can only move either down or right at any point in time


// (optimal) -memoization t.c- O(m * n)  s.c- O(m * n)
int minPath(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) { // If we are at (0,0), return that cell's value
        return grid[0][0];
    }

    if (i < 0 || j < 0) { // If out of bounds, return large number
        return 1e9;
    }

    if (dp[i][j] != -1) { // If already computed, return from dp
        return dp[i][j];
    }

    int up = grid[i][j] + minPath(i - 1, j, grid, dp); // Compute path by going up
    int left = grid[i][j] + minPath(i, j - 1, grid, dp); // Compute path by going left

    return dp[i][j] = min(up, left); // Store minimum in dp and return
}

int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1)); // Create dp table initialized with -1

    return minPath(n - 1, m - 1, grid, dp); // Start from bottom-right corner
}



// (optimal) -tabulation t.c- O(m * n)  s.c- O(m * n)
int minPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Create DP table
    
    for (int i = 0; i < n; i++) { // Fill table
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) { // First cell initialization
                dp[i][j] = matrix[i][j];
            }
            else {
                int up = matrix[i][j]; // Calculate from top
                if (i > 0) {
                    up += dp[i - 1][j];
                }
                else {
                    up += 1e9;
                }

                int left = matrix[i][j]; // Calculate from left
                if (j > 0) {
                    left += dp[i][j - 1];
                }
                else {
                    left += 1e9;
                }

                dp[i][j] = min(up, left); // Take minimum
            }
        }
    }

    return dp[n - 1][m - 1]; // Return result
}