//statement- Given 2 strings, find length of their longest common subseq. subseq is seq that appears in same relative order but
//           not necessarily contiguous & common subseq of 2 strings is subseq that is common to both strings


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m +  n * m)
int helper(int i, int j, string& a, string& b, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0;                    // no characters left

    if (dp[i][j] != -1) return dp[i][j];             // already calculated

    if (a[i] == b[j])
        return dp[i][j] = 1 + helper(i - 1, j - 1, a, b, dp); // matching characters

    int notTakeA = helper(i - 1, j, a, b, dp);       // skip character from a
    int notTakeB = helper(i, j - 1, a, b, dp);       // skip character from b

    return dp[i][j] = max(notTakeA, notTakeB);       // take the better option
}

int longestCommonSubsequence(string a, string b) {
    int n = a.size();                                // length of first string
    int m = b.size();                                // length of second string
    vector<vector<int>> dp(n, vector<int>(m, -1));   // dp[i][j]

    return helper(n - 1, m - 1, a, b, dp);            // start from last characters
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
int longestCommonSubsequence(string a, string b) {
    int n = a.size();                                // length of first string
    int m = b.size();                                // length of second string
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // shifted index: dp[i][j] represents first i & first j chars, so size is n+1 x m+1

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1])                      // dp uses shifted index, so actual string index is i-1 and j-1
                dp[i][j] = 1 + dp[i - 1][j - 1];    // take both matching characters

            else {
                int notTakeA = dp[i - 1][j];        // skip character from a
                int notTakeB = dp[i][j - 1];        // skip character from b

                dp[i][j] = max(notTakeA, notTakeB); // take the better option
            }
        }
    }

    return dp[n][m];                                 // LCS length
}