//statement- Given 2D integer arr named triangle with n rows. Its 1st row has 1 element & each succeeding row has 1 more element in it than row above it.
//           Return min falling path sum from 1st row to last. Movement is allowed only to bottom or bottom-right cell from current cell


// (optimal) -memoization t.c- O(n * n)  s.c- O(n + n * n)
int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
    if (dp[i][j] != -1) { // If value already computed
        return dp[i][j];
    }

    if (i == n - 1) { // If at bottom row
        return triangle[i][j];
    }

    int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp); // Compute both downward and diagonal moves
    int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diag); // Store and return min path sum
}

int minimumPathSum(vector<vector<int>> &triangle) { // Function to start the process
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(0, 0, triangle, n, dp);
}



// (optimal) -tabulation t.c- O(n * n)  s.c- O(n * n)
int minimumPathSum(vector<vector<int>> &triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0)); // Create a 2D dp array to store intermediate results

    for (int j = 0; j < n; j++) { // Initialize the last row of dp with triangle values
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) { // Traverse from second-last row to the top
        for (int j = i; j >= 0; j--) {
            int down = triangle[i][j] + dp[i + 1][j]; // Calculate sum from down and diagonal paths
            int diag = triangle[i][j] + dp[i + 1][j + 1]; 

            dp[i][j] = min(down, diag); // Store the minimum of the two paths
        }
    }
    
    return dp[0][0]; // Return the minimum path sum from top
}