//statement- Given string & pattern, implement pattern matching fxn that supports following special char:
//           '?' Matches any single char, '*' Matches any seq of char (including empty seq). pattern must match entire string


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m + n * m)
bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    if (i < 0 && j < 0) return true;   // both strings matched

    if (j < 0) return false;    // pattern string exhausted

    if (i < 0) {   // src string exhausted
        while (j >= 0) {  // remaining pattern string must be all * to get true, else false
            if (p[j] != '*') return false;
            j--;
        }
        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];                     // already calculated

    if (p[j] == s[i] || p[j] == '?')
        return dp[i][j] = solve(i - 1, j - 1, s, p, dp);     // exact match or ?

    if (p[j] == '*')
        return dp[i][j] = solve(i - 1, j, s, p, dp) ||       // * matches curr char
                          solve(i, j - 1, s, p, dp);          // * matches empty

    return dp[i][j] = false;                                 // no match
}

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));            // memo table

    return solve(n - 1, m - 1, s, p, dp);                    // start from last chars
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false)); // dp table
    dp[0][0] = true;                                             // empty string matches empty pattern

    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];                            // * can match empty string
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];                  // exact match or ?

            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];       // * matches one or empty

        }
    }

    return dp[n][m];                                           // final answer
}