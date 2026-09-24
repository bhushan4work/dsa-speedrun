//statement- Given arr of diff coins & target amt. Return fewest no of coins that are needed to make up that amt. 
//           If that amt of money cant be made up by any combination of coins, return -1. There are infinite no of coins of each type


// (optimal) -memoization t.c- O(n * amt)  s.c- O(n + n * amt)
int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (i == 0) {
        if (amount % coins[0] == 0) return amount / coins[0];  // take coins[0] only
        return 1e9;                                            // impossible
    }

    if (dp[i][amount] != -1) return dp[i][amount];             // already calculated
    int nt = f(i - 1, amount, coins, dp);                       // not take current coin
    int t = 1e9;                                                // take current coin
    if (coins[i] <= amount)
        t = 1 + f(i, amount - coins[i], coins, dp);             // take and stay at i

    return dp[i][amount] = min(t, nt);                         // minimum coins
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));    // memo table
    int ans = f(n - 1, amount, coins, dp);                      // solve from last coin

    return ans >= 1e9 ? -1 : ans;                               // -1 if impossible
}



// (optimal) -tabulation t.c- O(n * amt)  s.c- O(n * amt)
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));   // dp[i][a] = min coins
    for (int a = 0; a <= amount; a++) {                        // base case for coin 0
        if (a % coins[0] == 0)
            dp[0][a] = a / coins[0];                            // use only coins[0]
    }

    for (int i = 1; i < n; i++) {
        for (int a = 0; a <= amount; a++) {
            int nt = dp[i - 1][a];                              // not take current coin
            int t = 1e9;                                       // take current coin
            if (coins[i] <= a)
                t = 1 + dp[i][a - coins[i]];                   // take and stay at i

            dp[i][a] = min(t, nt);                              // choose minimum
        }
    }

    return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];  // answer
}