//statement- Given 2 strings, find min no of insertions & deletions in string str1 required to transform str1 into str2.
//           Insertion & deletion of characters can take place at any position in string


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m + n * m)
int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return 0;                    // no characters left

    if (dp[i][j] != -1) return dp[i][j];               // already computed

    if (a[i - 1] == b[j - 1])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b, dp); // matching characters

    int notTakeA = lcs(i - 1, j, a, b, dp);             // skip character from a
    int notTakeB = lcs(i, j - 1, a, b, dp);             // skip character from b

    return dp[i][j] = max(notTakeA, notTakeB);          // take better option
}

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // memo table

    int lcsLen = lcs(n, m, word1, word2, dp);            // find lcs length
    int deletion = n - lcsLen;                           // characters deleted from word1
    int insertion = m - lcsLen;                          // characters deleted from word2 = insertions in word1
    int ans = deletion + insertion;                      // total deletions + insertions

    return ans;                                          // minimum operations
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp table

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];        // matching characters
            else {
                int notTakeA = dp[i - 1][j];            // skip character from word1
                int notTakeB = dp[i][j - 1];            // skip character from word2

                dp[i][j] = max(notTakeA, notTakeB);     // take better option
            }
        }
    }

    int lcsLen = dp[n][m];                               // find lcs length
    int deletion = n - lcsLen;                          // characters deleted from word1
    int insertion = m - lcsLen;                         // characters deleted from word2 = insertions in word1
    int ans = deletion + insertion;                     // total deletions + insertions

    return ans;                                         // minimum operations
}