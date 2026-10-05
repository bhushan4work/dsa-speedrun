//statement- Given arr of n integers, arr[i] is price of stock on an ith day, determine max profit achievable by completing at most k transactions in total.
//           Holding at most 1 share of stock at any given time is allowed, meaning buying & selling stock k times is permitted, but stock must be sold before buying it again.
//           Buying & selling stock on same day is allowed


// (optimal) -memoization t.c- O(n * 2 * 3 * (k+1)) s.c- O(n * 2 * 3 * (k+1) + n)
int solve(int day, int canBuy, int remainingTransac, vector<int>& prices, vector<vector<vector<int>>>& dp) { // Finds and stores best profit from one state.
    int n = prices.size();
    if (day == n || remainingTransac == 0) { // No completed sale remains beyond either limit.
        return 0;
    }

    if (dp[day][canBuy][remainingTransac] != -1) { // A stored state avoids repeated branch exploration.
        return dp[day][canBuy][remainingTransac];
    }

    if (canBuy == 1) { // A free state can buy or wait.
        int buyProfit = -prices[day] + solve(day + 1, 0, remainingTransac, prices, dp); // Buying keeps sale capacity unchanged.
        int skipProfit = solve(day + 1, 1, remainingTransac, prices, dp); // Skipping preserves free state.
        dp[day][canBuy][remainingTransac] = max(buyProfit, skipProfit); // Cache best free-state branch for reuse.

        return dp[day][canBuy][remainingTransac];
    }

    int sellProfit = prices[day] + solve(day + 1, 1, remainingTransac - 1, prices, dp); // Selling closes one complete transaction.
    int holdProfit = solve(day + 1, 0, remainingTransac, prices, dp); // Holding preserves current stock and capacity.
    dp[day][canBuy][remainingTransac] = max(sellProfit, holdProfit); // Cache best holding-state branch for reuse.

    return dp[day][canBuy][remainingTransac];
}

int maxProfit(int k, vector<int>& prices) { // Finds maximum profit with at most k transactions.
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1))); // A negative entry marks an uncalculated state.

    return solve(0, 1, k, prices, dp); // Trading starts free to buy with full capacity.
}



// (optimal) -tabulation t.c- O(n * 2 * 3 * (k+1)) s.c- O(n * 2 * 3 * (k+1))
int maxProfit(int k, vector<int>& prices) { // Finds maximum profit with bottom-up states.
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0))); // Zero values cover both stopping conditions.
    for (int day = n - 1; day >= 0; day--) { // Reverse order prepares every required next-day state.
        for (int remainingTransac = 1; remainingTransac <= k; remainingTransac++) { // Positive counts allow a complete sale.
            int buyProfit = -prices[day] + dp[day + 1][0][remainingTransac]; // Buying compares an entry with a skipped day.
            int skipProfit = dp[day + 1][1][remainingTransac];
            dp[day][1][remainingTransac] = max(buyProfit, skipProfit);

            int sellProfit = prices[day] + dp[day + 1][1][remainingTransac - 1]; // Selling closes one complete transaction.
            int holdProfit = dp[day + 1][0][remainingTransac];
            dp[day][0][remainingTransac] = max(sellProfit, holdProfit);
        }
    }

    return dp[0][1][k]; // starting state contains complete answer.
}