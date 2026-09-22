//statement- Given 2 integer arr, val, wt, each of size n, which represent values, wt of n items respectively, integer W representing max capacity of knapsack, 
//           determine max value achievable by selecting a subset of items such that total wt of selected items does not exceed knapsack capacity W.
//           Each item can either be picked in its entirety or not picked at all (0-1 property). do max sum of values of selected items while keeping total wt within knapsack's capacity


// (optimal) -memoization t.c- O(n * w)  s.c- O(n + n * w)
int solve(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if (i == 0) {                                      // only first item remains
        if (wt[0] <= W)
            return val[0];                             // take it if it fits
        return 0;                                      // otherwise skip it
    }

    if (dp[i][W] != -1)
        return dp[i][W];                               // return already calculated ams

    int notTake = solve(i - 1, W, val, wt, dp);        // don't take current item
    int take = 0;

    if (wt[i] <= W)
        take = val[i] + solve(i - 1, W - wt[i], val, wt, dp); // take curr item

    return dp[i][W] = max(take, notTake);              // store & return maximum value
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // initialize memo table

    return solve(n - 1, W, val, wt, dp);                // solve using all items
}



// (optimal) -tabulation t.c- O(n * w)  s.c- O(n * w)
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));      // dp[i][w] = max value using items 0...i

    for (int w = wt[0]; w <= W; w++) {
        dp[0][w] = val[0];                                 // item 0 can be taken if it fits
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = dp[i - 1][w];                    // exclude curr item
            int take = 0;

            if (wt[i] <= w) {
                take = val[i] + dp[i - 1][w - wt[i]];      // include curr item
            }

            dp[i][w] = max(take, notTake);                 // choose the better option
        }
    }

    return dp[n - 1][W];                                   // answer for capacity W
}