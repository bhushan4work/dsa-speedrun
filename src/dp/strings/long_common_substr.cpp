//statement- Given 2 strings, find length of their longest common substr. substr is contiguous seq of chars within a string


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m + n * m)
int lcsMemo(int i, int j, string &a, string &b, vector<vector<int>> &dp, int &ans) {
    if (i == 0 || j == 0) return 0; // no characters left in either string

    if (dp[i][j] != -1) return dp[i][j]; // return already computed value

    if (a[i - 1] == b[j - 1]) { // characters match
        dp[i][j] = 1 + lcsMemo(i - 1, j - 1, a, b, dp, ans); // extend current common substring
        ans = max(ans, dp[i][j]); // update global maximum
    } else {
        dp[i][j] = 0; // substring must end here when characters differ
        lcsMemo(i - 1, j, a, b, dp, ans); // check remaining characters of a
        lcsMemo(i, j - 1, a, b, dp, ans); // check remaining characters of b
    }

    return dp[i][j]; // return current result
}

int longestCommonSubstring(string &a, string &b) {
    int n = a.size(), m = b.size(); // get lengths of both strings
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // initialize memo table
    int ans = 0; // store maximum substring length

    lcsMemo(n, m, a, b, dp, ans); // start recursive computation

    return ans; // return longest common substring length
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n * m)
int longestCommonSubstring(string &a, string &b) { // main function
    int n = a.size(), m = b.size(); // get lengths of both strings
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // initialize dp table
    int ans = 0; // store maximum substring length

    for (int i = 1; i <= n; i++) { // traverse first string
        for (int j = 1; j <= m; j++) { // traverse second string

            if (a[i - 1] == b[j - 1]) { // characters match
                dp[i][j] = 1 + dp[i - 1][j - 1]; // extend previous common substring
                ans = max(ans, dp[i][j]); // update maximum length
            }
            else {
                dp[i][j] = 0; // substring breaks when characters differ
            }
        }
    }

    return ans; // return longest common substring length
}