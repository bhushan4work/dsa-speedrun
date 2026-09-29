//statement- Find longest palindromic subseq length in given string. palindrome is seq that reads same both sides.
//           subseq is seq that appears in same relative order but not necessarily contiguous


// (optimal) -memoization t.c- O(n * n)  s.c- O(n + n * n)
int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;                         // no characters left

    if (dp[i][j] != -1) return dp[i][j];                  // already computed

    if (a[i] == b[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b, dp); // matching characters

    int notTakeA = lcs(i - 1, j, a, b, dp);       // skip character from a
    int notTakeB = lcs(i, j - 1, a, b, dp);       // skip character from b

    return dp[i][j] = max(notTakeA, notTakeB);       // take the better option
}

int longestPalindromeSubseq(string s) {
    string r = s;                                         // copy original string
    reverse(r.begin(), r.end());                          // reverse it

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));        // memo table

    return lcs(n - 1, n - 1, s, r, dp);                   // lcs(s, reverse(s))
}



// (optimal) -tabulation t.c- O(n * n)  s.c- O(n * n)
int longestPalindromeSubseq(string s) {
    string r = s;                                         // copy original string
    reverse(r.begin(), r.end());                          // reverse it

    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp table

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (s[i - 1] == r[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];         // matching characters
            }
            else {
                int notTakeS = dp[i - 1][j];        // skip character from s
                int notTakeR = dp[i][j - 1];        // skip character from r

                dp[i][j] = max(notTakeS, notTakeR);
            }
        }
    }

    return dp[n][n];                                     // lcs(s, reverse(s))
}