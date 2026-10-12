//statement- Given chain of matrices A1, A2,...An, figure out most efficient way to multiply these matrices. determine where to place parentheses to minimize no of multiplications.
//           Given an arr. Dimension of matrix Ai ( 0 < i < n ) is nums[i - 1] x nums[i].Find min no of multiplications needed to multiply the chain.


// (optimal) -memoization t.c- O(n ^ 3) s.c- O(n ^ 2 + n)
int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;                         // single matrix needs no multiplication

    if (dp[i][j] != -1) return dp[i][j];          // return stored answer

    int ans = INT_MAX;                            // minimum multiplication cost

    for (int k = i; k < j; k++) {                // try every partition
        int cost = arr[i - 1] * arr[k] * arr[j]   // cost of multiplying both results
                 + solve(i, k, arr, dp)           // left partition cost
                 + solve(k + 1, j, arr, dp);      // right partition cost

        ans = min(ans, cost);                     // keep minimum cost
    }

    return dp[i][j] = ans;                        // store and return answer
}

int matrixMultiplication(vector<int>& arr) {
    int n = arr.size() - 1;                       // number of matrices
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // memo table

    return solve(1, n, arr, dp);                  // solve for all matrices
}



// (optimal) -tabulation t.c- O(n ^ 3) s.c- O(n ^ 2)
int matrixMultiplication(vector<int>& arr) {
    int n = arr.size() - 1;                       // number of matrices
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // dp table

    for (int i = n; i >= 1; i--) {               // start from last matrix
        for (int j = i + 1; j <= n; j++) {       // consider larger chains
            int ans = INT_MAX;                    // minimum multiplication cost

            for (int k = i; k < j; k++) {        // try every partition
                int cost = arr[i - 1] * arr[k] * arr[j] // multiplication cost
                         + dp[i][k]              // left partition cost
                         + dp[k + 1][j];         // right partition cost

                ans = min(ans, cost);             // keep minimum cost
            }

            dp[i][j] = ans;                       // store minimum cost
        }
    }

    return dp[1][n];                              // answer for full chain
}