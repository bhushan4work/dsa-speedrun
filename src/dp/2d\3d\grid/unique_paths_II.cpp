//statement-  Given m * n 2d arr where each cell is 0 or 1. Return no of unique ways to go from matrix[0][0] to matrix[m-1][n-1].
//            cell is blocked if its value is 1, & no path is possible through that cell. Movement is allowed in only 2 directions from cell - right & bottom


// (optimal) -memoization t.c- O(m * n)  s.c- O(m * n)
int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
    
    if (i < 0 || j < 0 || matrix[i][j] == 1) { // Base cases
        return 0;
    }
    else if (i == 0 && j == 0) {
        return 1;
    }


    if (dp[i][j] != -1) { // If result is already computed, return it
        return dp[i][j];
    }

    int up = func(i - 1, j, matrix, dp); // Calculate no of ways by moving up recursively.
    int left = func(i, j - 1, matrix, dp); // Calculate no of ways by moving left recursively.

    return dp[i][j] = up + left; // Return total ways
}

int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize DP table to memoize results
    
    return func(m-1, n-1, matrix, dp); // Return total number of paths
}



// (optimal) -tabulation t.c- O(m * n)  s.c- O(m * n)
int func(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) { // Base condition: If there's an obstacle, no paths can pass through
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) { // If at starting point, there is one path to it
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0) { // Check if we can move up (if not at top edge of maze)
                up = dp[i - 1][j];
            }

            if (j > 0) { // Check if we can move left (if not at left edge of maze)
                left = dp[i][j - 1];
            }

            dp[i][j] = up + left; // Total paths to reach (i, j) is sum of paths from above and left
        }
    }

    return dp[m - 1][n - 1]; // final result is stored here, representing destination
}

int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m = matrix.size();   
    int n = matrix[0].size(); 

    vector<vector<int>> dp(m, vector<int>(n, 0)); // Initialize DP table to memoize results

    return func(m, n, matrix, dp); // Return total no of paths
}