//statement- Given m * n matrix of ones & zeros, return how many square submatrices have all ones


// (optimal) -memoization t.c- O(n * m)  s.c- O(n * m + n + m)
int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    int n = matrix.size();
    int m = matrix[0].size();

    if (i >= n || j >= m) return 0;                         // outside matrix

    if (dp[i][j] != -1) return dp[i][j];                    // already computed

    if (matrix[i][j] == 0) return dp[i][j] = 0;            // no square possible

    int right = solve(i, j + 1, matrix, dp);               // squares to right
    int down = solve(i + 1, j, matrix, dp);                // squares below
    int diag = solve(i + 1, j + 1, matrix, dp);            // squares diagonally

    return dp[i][j] = 1 + min({right, down, diag});         // largest square from this cell
}

int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));          // memo table

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += solve(i, j, matrix, dp);                // count squares from each cell

    return ans;                                             // total square submatrices
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));   // dp table
    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == 1)
                dp[i][j] = 1 + min({dp[i + 1][j],           // down
                                    dp[i][j + 1],           // right
                                    dp[i + 1][j + 1]});     // diagonal

            ans += dp[i][j];                                // add all squares ending here
        }
    }

    return ans;                                             // total square submatrices
}