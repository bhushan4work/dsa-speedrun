//statement- Given stick of length n. stick is labelled 0 to n. arr cuts[i] denotes position we perform a cut. Perform cuts in any order, we can change order of cuts.
//           cost of 1 cut is length of stick to be cut, total cost is sum of costs of all cuts. When stick is cut, it will be split into 2 smaller sticks
//           (i.e. sum of their lengths is length of stick before cut). Return min total cost of cuts.


// (optimal) -memoization t.c- O(n ^ 3) s.c- O(n ^ 2 + n)
int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if (i > j) return 0;                                      // no cuts left

    if (dp[i][j] != -1) return dp[i][j];                       // cached result

    int ans = INT_MAX;

    for (int k = i; k <= j; k++) {
        int cost = cuts[j + 1] - cuts[i - 1]                  // current stick length
                 + solve(i, k - 1, cuts, dp)                  // left segment
                 + solve(k + 1, j, cuts, dp);                 // right segment
        ans = min(ans, cost);                                  // minimum cost
    }

    return dp[i][j] = ans;                                    // store result
}

int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);                                         // add right boundary
    cuts.insert(cuts.begin(), 0);                              // add left boundary
    sort(cuts.begin(), cuts.end());                            // sort cut positions

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));    // memo table
    return solve(1, c, cuts, dp);                             // solve all cuts
}



// (optimal) -tabulation t.c- O(n ^ 3) s.c- O(n ^ 2)
int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);                                         // add right boundary
    cuts.insert(cuts.begin(), 0);                              // add left boundary
    sort(cuts.begin(), cuts.end());                            // sort cut positions

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));     // initialize dp table

    for (int i = c; i >= 1; i--) {                             // process from right to left
        for (int j = 1; j <= c; j++) {                         // consider cut ranges
            if (i > j) continue;                               // empty range costs zero

            int ans = INT_MAX;

            for (int k = i; k <= j; k++) {                     // try each first cut
                int cost = cuts[j + 1] - cuts[i - 1]           // current stick length
                         + dp[i][k - 1]                        // left segment
                         + dp[k + 1][j];                       // right segment
                ans = min(ans, cost);                           // minimum cost
            }

            dp[i][j] = ans;                                    // store minimum cost
        }
    }

    return dp[1][c];                                            // answer for all cuts
}