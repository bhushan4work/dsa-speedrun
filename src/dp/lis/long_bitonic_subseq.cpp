//statement- Given arr of n integers, find length of longest bitonic seq. seq is considered bitonic if its strictly incre,
//           strictly decre, or strictly incre and then strictly decre. seq doesnt have to be contiguous


// (optimal) -memoization t.c- O(n * n) s.c- O(n * n + n)
int solve(int i, int prev, vector<int>& a, vector<vector<int>>& dp) {
    if (i == a.size()) return 0;                              // base case

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];        // cached result

    int notTake = solve(i + 1, prev, a, dp);                  // skip element
    int take = 0;                                             // initialize take

    if (prev == -1 || a[i] > a[prev])
        take = 1 + solve(i + 1, i, a, dp);                    // increasing subsequence

    return dp[i][prev + 1] = max(take, notTake);              // store result
}

int longestBitonicSequence(int n, vector<int>& a) {
    vector<int> inc(n, 1), dec(n, 1);                         // increasing and decreasing lengths

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                inc[i] = max(inc[i], inc[j] + 1);             // LIS ending at i
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j])
                dec[i] = max(dec[i], dec[j] + 1);             // LDS starting at i
        }
    }

    int ans = 0;                                              // final answer
    for (int i = 0; i < n; i++)
        ans = max(ans, inc[i] + dec[i] - 1);                  // avoid counting peak twice

    return ans;                                               // return longest bitonic length
}



// (optimal) -tabulation t.c- O(n * n) s.c- O(n)
int longestBitonicSequence(int n, vector<int>& a) {
    vector<int> inc(n, 1), dec(n, 1);                         // initialize lengths

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                inc[i] = max(inc[i], inc[j] + 1);             // LIS ending at i
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j])
                dec[i] = max(dec[i], dec[j] + 1);             // LDS starting at i
        }
    }

    int ans = 0;                                              // initialize answer
    for (int i = 0; i < n; i++)
        ans = max(ans, inc[i] + dec[i] - 1);                  // combine both sides

    return ans;                                               // return result
}