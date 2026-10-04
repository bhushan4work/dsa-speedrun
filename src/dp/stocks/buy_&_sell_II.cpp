//statement- Given arr of n integers, arr[i] is price of stock o ith day. Determine max profit achievable by buying & selling stock any no of times.
//           Holding at most 1 share of stock at any given time is allowed, meaning buying & selling stock can be done any no of times, 
//           but stock must be sold before buying it again. Buying & selling stock on same day is permitted.


// (optimal) -memoization t.c- O(n) s.c- O(n + n)
int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
    if (i == prices.size()) return 0;                    // no days left

    if (dp[i][buy] != -1) return dp[i][buy];             // already calculated

    if (buy) {
        int take = -prices[i] + solve(i + 1, 0, prices, dp); // buy today 
        int skip = solve(i + 1, 1, prices, dp);              // skip buying
        return dp[i][buy] = max(take, skip);                 // best choice
    }

    int sell = prices[i] + solve(i + 1, 1, prices, dp); // sell today
    int skip = solve(i + 1, 0, prices, dp);             // skip selling

    return dp[i][buy] = max(sell, skip);                 // best choice
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();                               // number of days
    vector<vector<int>> dp(n, vector<int>(2, -1));      // memo table

    return solve(0, 1, prices, dp);                      // start with buying allowed
}



// (optimal) -tabulation t.c- O(n) s.c- O(n)
int maxProfit(vector<int>& prices) {
    int n = prices.size();                               // number of days
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));   // dp[i][buy]

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                int take = -prices[i] + dp[i + 1][0];   // buy today
                int skip = dp[i + 1][1];                // skip buying
                dp[i][buy] = max(take, skip);            // best choice
            }
            else {
                int sell = prices[i] + dp[i + 1][1];    // sell today
                int skip = dp[i + 1][0];                // skip selling
                dp[i][buy] = max(sell, skip);            // best choice
            }
        }
    }

    return dp[0][1];                                     // start with buying allowed
}