//statement- Given 2 strings s & t, determine min no of operations required to convert string s into string t.
//           goal is to transform start into target using fewest number of these operations.
//           operations you can use are: Insert char, Delete char, Replace char


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m + n * m)
int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
    if (i < 0) return j + 1;                         // insert remaining characters
    if (j < 0) return i + 1;                         // delete remaining characters

    if (dp[i][j] != -1) return dp[i][j];             // already calculated

    if (word1[i] == word2[j])
        return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp); // no operation needed

    int insert = solve(i, j - 1, word1, word2, dp);  // insert a character
    int remove = solve(i - 1, j, word1, word2, dp);   // delete a character
    int replace = solve(i - 1, j - 1, word1, word2, dp); // replace a character

    return dp[i][j] = 1 + min({insert, remove, replace}); // choose min operation
}

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));    // memo table

    return solve(n - 1, m - 1, word1, word2, dp);     // min edit distance
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp table

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;                                    // insert all characters

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;                                    // delete all characters

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];             // characters already match
            else
                dp[i][j] = 1 + min({dp[i][j - 1],       // insert
                                    dp[i - 1][j],       // delete
                                    dp[i - 1][j - 1]}); // replace
        }
    }

    return dp[n][m];                                      // min edit distance
}