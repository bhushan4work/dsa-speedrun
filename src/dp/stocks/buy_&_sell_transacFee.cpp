//statement- Given arr where arr[i] represents prices of stocks, fee represents transac fee for each trade. determine max profit such that u need to pay transac fee for each buy & sell transac.
//           transac Fee is applied when u sell a stock. u may complete as many transacs. u may not engage in multiple transacs simultaneously (i.e. u must sell before buying again).


// (optimal) -memoization t.c- O(n) s.c- O(n + n)
long long solve(int day, int canBuy, vector<int>& prices, int fee, vector<vector<long long>>& dp) { // Finds 1 state and caches best profit.
    int n = prices.size();
    if (day == n) { // No trading opportunity remains after last day.
        return 0;
    }

    if (dp[day][canBuy] != -1) { // A stored state avoids repeated trading paths.
        return dp[day][canBuy];
    }

    long long bestProfit;
    if (canBuy == 1) { // An empty hand allows a purchase or a skip.
        long long buy = -prices[day] + solve(day + 1, 0, prices, fee, dp); // Buying spends current stock price.
        long long skip = solve(day + 1, 1, prices, fee, dp); // Skipping preserves permission to buy.
        bestProfit = max(buy, skip); // stronger opening choice enters cache.
    }
    else {
        long long sell = prices[day] - fee + solve(day + 1, 1, prices, fee, dp); // Selling closes a trade & pays 1 fee.
        long long hold = solve(day + 1, 0, prices, fee, dp); // Holding preserves owned-share state.
        bestProfit = max(sell, hold); // stronger closing choice enters cache.
    }

    dp[day][canBuy] = bestProfit; // Caching preserves best result for reuse.

    return dp[day][canBuy];
}

long long maxProfit(vector<int>& prices, int fee) { // Finds max profit with cached states.
    int n = prices.size();
    vector<vector<long long>> dp(n, vector<long long>(2, -1)); // Minus 1 marks every uncalculated state.

    return solve(0, 1, prices, fee, dp); // Trading starts empty-handed on first day.
}



// (optimal) -tabulation t.c- O(n) s.c- O(n)
long long maxProfit(vector<int>& prices, int fee) { // Finds max profit with bottom-up states.
    int n = prices.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0)); // Row n represents period after all days.

    for (int day = n - 1; day >= 0; day--) { // Reverse order makes next-day states available.
        long long buy = -prices[day] + dp[day + 1][0]; // Buying or skipping starts from an empty hand.
        long long skip = dp[day + 1][1];
        dp[day][1] = max(buy, skip); // stronger empty-hand choice fills state.

        long long sell = prices[day] - fee + dp[day + 1][1]; // Selling after 1 fee closes transaction.
        long long hold = dp[day + 1][0];
        dp[day][0] = max(sell, hold); // stronger owned-share choice fills state.
    }

    return dp[0][1]; // first day starts with permission to buy.
}