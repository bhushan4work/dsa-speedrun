//statement- Given 2 integers m & n, representing no of row & col of 2d arr. Return no of unique ways to go from matrix[0][0] to matrix[m-1][n-1].
//           Movement is allowed only in 2 directions from a cell: right & bottom


// (optimal) -memoization t.c- O(m * n)  s.c- O(m * n)
int func(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) { // Base case
        return 1;
    }

    if (i < 0 || j < 0) { // If out of bounds or blocked cell, there are no ways
        return 0;
    }

    if (dp[i][j] != -1) { // If already computed for this cell, return it
        return dp[i][j];
    }

    int up = func(i - 1, j, dp); // Calculate ways by moving up recursively
    int left = func(i, j - 1, dp); // Calculate ways by moving left recursively

    return dp[i][j] = up + left; // Store result in dp table and return it
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize memoization table (dp) 
    return func(m-1, n-1, dp); // Return total count (0 based indexing)
}



// (optimal) -tabulation t.c- O(m * n)  s.c- O(m * n)
int func(int m, int n, vector<vector<int>>& dp) {
    for (int i = 0; i < m; i++) { // Loop through grid using two nested loops
        for (int j = 0; j < n; j++) { 
            if (i == 0 && j == 0) { // Base condition
                dp[i][j] = 1;
                continue; // Skip rest of loop and continue with next iteration.
            }

            int up = 0; // Initialize variables to store number of ways from cell above (up) and left (left)
            int left = 0;

            if (i > 0) { // If we are not at first row (i > 0), update 'up' with value from cell above.
                up = dp[i - 1][j];
            }

            if (j > 0) { // If we are not at first column (j > 0), update 'left' with value from cell to left.
                left = dp[i][j - 1];
            }

            dp[i][j] = up + left; // Calculate number of ways to reach current cell by adding 'up' and 'left'.
        }
    }

    return dp[m - 1][n - 1]; // result is stored in bottom-right cell (m-1, n-1).
}

int uniquePaths(int m, int n) { 
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize a memoization table (dp) to store results of subproblems.
    return func(m, n, dp); // Return total count(0 based indexing)
}