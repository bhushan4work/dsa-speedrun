//statement- Given arr of n integers, arr[i] is price of stock on an ith day, determine max profit achievable by completing at most 2 transactions in total.
//           Holding at most 1 share of stock at any time is allowed, meaning buying & selling stock twice is permitted, but stock must be sold before buying it again.
//           Buying & selling stock on same day is allowed.


// (optimal) -memoization t.c- O(n * 2 * 3) s.c- O(n * 2 * 3 + n)
int solve(int index, int canBuy, int remainingTransac, vector<int>& prices, vector<vector<vector<int>>>& dp) { // Returns a cached profit for one trading state.
    int n = prices.size();
    if (index == n || remainingTransac == 0) { // No earning action remains after either limit ends.
        return 0;
    }

    if (dp[index][canBuy][remainingTransac] != -1) { // A calculated state can be reused without branching.
        return dp[index][canBuy][remainingTransac];
    }

    if (canBuy == 1) { // An empty portfolio allows buying or waiting.
        int buy = -prices[index] + solve(index + 1, 0, remainingTransac, prices, dp); // Buying opens a position & spends today's price.
        int skip = solve(index + 1, 1, remainingTransac, prices, dp); // Waiting keeps full transaction limit available.
        dp[index][canBuy][remainingTransac] = max(buy, skip); // Cache storage prevents later recalculation.

        return dp[index][canBuy][remainingTransac];
    }

    int sell = prices[index] + solve(index + 1, 1, remainingTransac - 1, prices, dp); // Selling closes a position & completes one trade.
    int hold = solve(index + 1, 0, remainingTransac, prices, dp); // Holding preserves open position for a later price.
    dp[index][canBuy][remainingTransac] = max(sell, hold); // Cache storage prevents later recalculation.

    return dp[index][canBuy][remainingTransac];
}

int maxProfit(vector<int>& prices) { // Returns largest profit from at most two trades.
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); // Sentinel values mark every state as uncalculated.

    return solve(0, 1, 2, prices, dp); // Trading starts empty with both sales available.
}



// (optimal) -tabulation t.c- O(n * 2 * 3) s.c- O(n * 2 * 3)
int maxProfit(vector<int>& prices) { // Returns largest profit from at most two trades.
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); // extra row represents exhausted day range.

    for (int index = n - 1; index >= 0; index--) { // Backward order makes next-day answers available.
        for (int remainingTransac = 1; remainingTransac <= 2; remainingTransac++) { // Zero remaining trades stays at base value.
            int buy = -prices[index] + dp[index + 1][0][remainingTransac]; // Buying spends money before a later sale.
            int skip = dp[index + 1][1][remainingTransac]; // Waiting preserves an empty portfolio.
            dp[index][1][remainingTransac] = max(buy, skip); // best empty-portfolio transition is stored.

            int sell = prices[index] + dp[index + 1][1][remainingTransac - 1]; // Selling earns money & completes 1 trade.
            int hold = dp[index + 1][0][remainingTransac]; // Holding preserves open position.
            dp[index][0][remainingTransac] = max(sell, hold); // best held-stock transition is stored.
        }
    }
    return dp[0][1][2]; // full starting state contains final profit.
}