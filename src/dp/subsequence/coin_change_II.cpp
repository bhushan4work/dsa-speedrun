//statement- Given arr coins of n integers representing coin denominations. find no of distinct combinations that sum up to specified amt of money. 
//           If not able to achieve exact amt with any combination of coins, return 0. Single coin can be used multiple times. Return ans with modulo 109+7


// (optimal) -memoization t.c- O(n * amt)  s.c- O(n + n * amt)
long long solve(int i, int tar, vector<int>& coins, vector<vector<long long>>& dp) {
    if (i == 0) {                                      // only coin[0] is available
        return tar % coins[0] == 0;                    // valid if target is divisible by coin[0]
    }

    if (dp[i][tar] != -1) return dp[i][tar];           // return already computed state

    long long nottake = solve(i - 1, tar, coins, dp);  // don't take current coin
    long long take = 0;                                // initialize take ways

    if (coins[i] <= tar)                               // take only if coin fits
        take = solve(i, tar - coins[i], coins, dp);    // stay at i because coins can be reused

    return dp[i][tar] = take + nottake;                // total ways
}

long long change(int amount, vector<int>& coins) {
    int n = coins.size();                              // number of coins
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1)); // memo table

    return solve(n - 1, amount, coins, dp);             // solve from last coin
}



// (optimal) -tabulation t.c- O(n * amt)  s.c- O(n * amt)
long long change(int amount, vector<int>& coins) {
    int n = coins.size();          // no of coins
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));  // dp[i][tar]

    for (int tar = 0; tar <= amount; tar++) {          // initialize using only coin[0]
        if (tar % coins[0] == 0)                        // target must be divisible by coin[0]
            dp[0][tar] = 1;                            // exactly one way to form the target
    }

    for (int i = 1; i < n; i++) {                      // process remaining coins
        for (int tar = 0; tar <= amount; tar++) {      // process every target
            long long nottake = dp[i - 1][tar];        // don't take current coin
            long long take = 0;                        // initialize take ways

            if (coins[i] <= tar)                       // take only if coin fits
                take = dp[i][tar - coins[i]];         // stay on same row because coin is reusable

            dp[i][tar] = take + nottake;              // total ways
        }
    }

    return dp[n - 1][amount];                          // answer for all coins and target
}