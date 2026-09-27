//statement- Given rod & arr price[] where price[i] denotes val of piece of rod of length i inches (1-based indexing).
//           Determine max value obtainable by cutting up rod & selling pieces. Make any no of cuts, or none at all, & sell resulting pieces


// (optimal) -memoization t.c- O(n * n)  s.c- O(n + n * n)
int helper(int i, int n, vector<int>& price, vector<vector<int>>& dp) {
    if (i == 0) return n * price[0];                 // only length 1 pieces remain

    if (dp[i][n] != -1) return dp[i][n];             // already calculated

    int notTake = helper(i - 1, n, price, dp);       // don't take curr piece
    int take = INT_MIN;                              // initialize take
    int rodLen = i + 1;                              // current piece length
    if (rodLen <= n)
        take = price[i] + helper(i, n - rodLen, price, dp); // take again

    return dp[i][n] = max(take, notTake);             // store max profit
}

int rodCutting(vector<int>& price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // dp[i][len]

    return helper(n - 1, n, price, dp);                // start from last piece
}



// (optimal) -tabulation t.c- O(n * n)  s.c- O(n * n)
int rodCutting(vector<int>& price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0)); // dp[i][len]

    for (int len = 0; len <= n; len++)
        dp[0][len] = len * price[0];                  // only length 1 pieces

    for (int i = 1; i < n; i++) {
        int rodLen = i + 1;                           // current piece length

        for (int len = 0; len <= n; len++) {
            int notTake = dp[i - 1][len];             // don't take current piece
            int take = INT_MIN;                       // initialize take
            if (rodLen <= len)
                take = price[i] + dp[i][len - rodLen]; // take again

            dp[i][len] = max(take, notTake);          // store max profit
        }
    }

    return dp[n - 1][n];                              // ans
}