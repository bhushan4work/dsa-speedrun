//statement- Given 2 strings, find shortest common superseq. shortest common superseq is shortest string that contains both as subseq.
//Note: problem may have multiple valid ans. Since return type is string, judge will output 1 if your returned str is valid scs else 0


// (optimal) -memoization t.c- O(n * m)  s.c- O(n + m + n * m)
int f(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
    if (i == a.size()) return b.size() - j;              // a is exhausted
    if (j == b.size()) return a.size() - i;              // b is exhausted

    if (dp[i][j] != -1) return dp[i][j];                 // already computed

    if (a[i] == b[j])
        return dp[i][j] = 1 + f(i + 1, j + 1, a, b, dp); // take common character once

    return dp[i][j] = 1 + min(f(i + 1, j, a, b, dp),     // take a[i]
                              f(i, j + 1, a, b, dp));    // take b[j]
}

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();                // lengths
    vector<vector<int>> dp(n, vector<int>(m, -1));       // memo table
    
    f(0, 0, str1, str2, dp);                             // fill needed states

    int i = 0, j = 0;                                    // start reconstruction
    string ans = "";                                     // final answer

    while (i < n && j < m) {
        if (str1[i] == str2[j]) {
            ans += str1[i];                              // common character
            i++;
            j++;
        }
        else if (f(i + 1, j, str1, str2, dp) <=
                 f(i, j + 1, str1, str2, dp)) {
            ans += str1[i];                              // take from str1
            i++;
        }
        else {
            ans += str2[j];                              // take from str2
            j++;
        }
    }

    while (i < n) ans += str1[i++];                      // remaining str1
    while (j < m) ans += str2[j++];                      // remaining str2

    return ans;                                          // shortest common supersequence
}



// (optimal) -tabulation t.c- O(n * m)  s.c- O(n + m + n * m)
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();                // lengths
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp table

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;                                    // only str1 remains

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;                                    // only str2 remains

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];         // common character once
            else
                dp[i][j] = 1 + min(dp[i - 1][j],        // take str1[i-1]
                                   dp[i][j - 1]);         // take str2[j-1]
        }
    }

    int i = n, j = m;                                    // start from end
    string ans = "";                                     // final answer

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            ans += str1[i - 1];                          // common character
            i--;
            j--;
        }
        else if (dp[i - 1][j] <= dp[i][j - 1]) {
            ans += str1[i - 1];                          // take from str1
            i--;
        }
        else {
            ans += str2[j - 1];                          // take from str2
            j--;
        }
    }

    while (i > 0) ans += str1[--i];                      // remaining str1
    while (j > 0) ans += str2[--j];                      // remaining str2

    reverse(ans.begin(), ans.end());                     // reverse reconstructed string

    return ans;                                          // answer
}