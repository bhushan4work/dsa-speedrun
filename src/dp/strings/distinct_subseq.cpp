//statement- Given 2 strings, return no of distinct subseq of s that equals t. subseq is new string generated from original string with some or no chars deleted without changing relative order. 
//           eg: "ace" is subseq of "abcde" but "aec" isnt. count how many diff ways we can form t from s by deleting some or no chars from s. Return result modulo 109+7


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m + n * m)
long long solve(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
    if (j < 0) return 1;                                      // formed target
    if (i < 0) return 0;                                      // source exhausted

    if (dp[i][j] != -1) return dp[i][j];                      // already computed

    if (s[i] == t[j])
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp)      // take matching character
                         + solve(i - 1, j, s, t, dp);          // skip source character i.e from string s

    return dp[i][j] = solve(i - 1, j, s, t, dp);              // characters don't match
}

int numDistinct(string s, string t) {
    int n = s.size();                                         // source length
    int m = t.size();                                         // target length
    vector<vector<long long>> dp(n, vector<long long>(m, -1)); // memo table

    return solve(n - 1, m - 1, s, t, dp);                     // count distinct subsequences
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
int numDistinct(string s, string t) {
    int n = s.size();                                         // source length
    int m = t.size();                                         // target length
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0)); // dp table

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;                                        // empty target can always be formed

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // take or skip character
            else
                dp[i][j] = dp[i - 1][j];                    // skip source character
        }
    }

    return dp[n][m];                                         // total distinct subsequences
}