//statement- given an arr, integer k. u may partition arr into 1 or more contiguous sub-arr, where each sub-arr has length in range 1 … k (inclusive). After u pick a partition,
//           replace every element in each sub-arr with max value found in that sub-arr. arr is modified in-place for purpose of computing total. Return largest possible
//           sum of entire arr after performing exactly 1 such partition-and-replace operation. test cases are guaranteed to have an ans that fits in a 32-bit signed integer


// (optimal) -memoization t.c- O(n * k) s.c- O(n + n)
int solve(int i, int k, vector<int>& arr, vector<int>& dp) {
    if (i == arr.size()) return 0;                         // all elements processed

    if (dp[i] != -1) return dp[i];                        // return cached result

    int len = 0, maxi = 0, ans = 0;                       // initialize variables
    for (int j = i; j < min((int)arr.size(), i + k); j++) {  // min() prevents accessing beyond the arr when fewer than k elements remain
        len++;                                            // current partition length
        maxi = max(maxi, arr[j]);                         // maximum in partition
        ans = max(ans, len * maxi + solve(j + 1, k, arr, dp)); // partition and recurse
    }

    return dp[i] = ans;                                   // store best answer
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> dp(arr.size(), -1);                       // memoization table
    return solve(0, k, arr, dp);                          // start from index 0
}



// (optimal) -tabulation t.c- O(n * k) s.c- O(n)
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();                                   // array size
    vector<int> dp(n + 1, 0);                             // dp[i] = best answer from i onward

    for (int i = n - 1; i >= 0; i--) {
        int len = 0, maxi = 0, ans = 0;                   // initialize variables

        for (int j = i; j < min(n, i + k); j++) {
            len++;                                        // current partition length
            maxi = max(maxi, arr[j]);                     // maximum in partition
            ans = max(ans, len * maxi + dp[j + 1]);       // partition and use next state
        }

        dp[i] = ans;                                      // store best answer
    }

    return dp[0];                                         // answer for entire array
}