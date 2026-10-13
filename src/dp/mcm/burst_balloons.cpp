//statement- Given n balloons, indexed 0 to n - 1, each balloon is painted with number on it represented by an arr. Burst all balloons.
//           If ith balloon is burst, coins obtained are arr[i - 1] * arr[i] * arr[i + 1]. If i - 1 or i + 1 goes out of bounds of arr, 
//           treat it as if there is balloon with 1 painted on it. Return max coins that can be collected by bursting balloons wisely


// (optimal) -memoization t.c- O(n ^ 3) s.c- O(n ^ 2 + n)
int solve(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
    if (i > j) return 0;                                      // no balloons left

    if (dp[i][j] != -1) return dp[i][j];                      // already computed

    int ans = 0;

    for (int k = i; k <= j; k++) {
        int coins = a[i - 1] * a[k] * a[j + 1]               // coins from bursting k
                    + solve(i, k - 1, a, dp)                  // left balloons
                    + solve(k + 1, j, a, dp);                 // right balloons

        ans = max(ans, coins);                                // maximize coins
    }

    return dp[i][j] = ans;                                    // store result
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();

    vector<int> a(n + 2, 1);                                  // add boundary balloons
    for (int i = 0; i < n; i++) a[i + 1] = nums[i];           // copy original balloons

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));    // memo table

    return solve(1, n, a, dp);                                // solve full range
}



// (optimal) -tabulation t.c- O(n ^ 3) s.c- O(n ^ 2)
int maxCoins(vector<int>& nums) {
    int n = nums.size();

    vector<int> a(n + 2, 1);                                  // add boundary balloons
    for (int i = 0; i < n; i++) a[i + 1] = nums[i];           // copy original balloons

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));     // dp table

    for (int i = n; i >= 1; i--) {                            // start from right
        for (int j = i; j <= n; j++) {                        // expand interval
            int ans = 0;

            for (int k = i; k <= j; k++) {                    // choose last balloon
                int coins = a[i - 1] * a[k] * a[j + 1]       // coins from bursting k
                            + dp[i][k - 1]                    // left interval
                            + dp[k + 1][j];                   // right interval

                ans = max(ans, coins);                        // maximize coins
            }

            dp[i][j] = ans;                                   // store best result
        }
    }

    return dp[1][n];                                          // answer for full range
}