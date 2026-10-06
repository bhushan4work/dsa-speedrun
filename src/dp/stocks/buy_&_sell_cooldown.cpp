//statement- given arr prices. complete any no of transac subject to these rules: After u sell a share, u cant buy on very next day (i.e. 1day cooldown).
//           u may not hold more than 1 share at a time, i.e u must sell before u buy again. Return max profit u can achieve.


// (optimal) -memoization t.c- O(n) s.c- O(n + n)
int solve(int index, int canBuy, vector<int>& prices, vector<vector<int>>& dp) { // Returns a cached profit for 1 trading state.
    int n = prices.size();
    if (index >= n) { // No trading day remains after array ends.
        return 0;
    }

    if (dp[index][canBuy] != -1) { // A calculated state can be reused without branching.
        return dp[index][canBuy];
    }

    if (canBuy == 1) { // An empty portfolio allows buying or waiting.
        int buy = -prices[index] + solve(index + 1, 0, prices, dp); // Buying spends today's price and opens a position.
        int skip = solve(index + 1, 1, prices, dp); // Waiting preserves an empty portfolio.
        dp[index][canBuy] = max(buy, skip); // Cache storage prevents later recalculation.

        return dp[index][canBuy];
    }

    int sell = prices[index] + solve(index + 2, 1, prices, dp); // Selling earns money and forces 1 rest day.
    int hold = solve(index + 1, 0, prices, dp); // Holding keeps stock for a later sale.
    dp[index][canBuy] = max(sell, hold); // Cache storage prevents later recalculation.

    return dp[index][canBuy];
}

int maxProfit(vector<int>& prices) { // Returns largest profit with cached states.
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1)); // Sentinel values mark every state as uncalculated.

    return solve(0, 1, prices, dp); // Trading starts empty on first day.
}



// (optimal) -tabulation t.c- O(n) s.c- O(n)
int maxProfit(vector<int>& prices) { // Returns largest profit with bottom-up states.
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // Extra rows support both future-day transitions.

    for (int index = n - 1; index >= 0; index--) { // Backward order keeps future ans ready.
        int buy = -prices[index] + dp[index + 1][0]; // Buying spends money before a later sale.
        int skip = dp[index + 1][1]; // Waiting preserves an empty portfolio.
        dp[index][1] = max(buy, skip); // best empty-portfolio state is stored.

        int sell = prices[index] + dp[index + 2][1]; // Selling earns money and skips one buying day.
        int hold = dp[index + 1][0]; // Holding preserves open position.
        dp[index][0] = max(sell, hold); // best held-stock state is stored.
    }

    return dp[0][1]; // empty starting state contains ans.
}