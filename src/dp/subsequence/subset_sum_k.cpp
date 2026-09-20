//statement- given arr with n +ve integers. find if there is subset in arr with sum = K. If there is, return true else return false.
//note: subset/subseq is contiguous or non-contiguous part of arr, where elements appear in same order as original arr


// (optimal) -memoization t.c- O(n * k)  s.c- O(n + n * k)
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) { // Base case: target achieved
        return true;
    }

    if (ind == 0) { // Base case: at first index, check if it equals target
        return arr[0] == target;
    }

    if (dp[ind][target] != -1) { // Check memoization table
        return dp[ind][target];
    }

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp); // Choice 1: do not take current element
    bool taken = false; // Choice 2: take current element if possible

    if (arr[ind] <= target) {
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = notTaken || taken; // Store result in DP table
}

bool subsetSumToK(int n, int k, vector<int>& arr) { 
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);
}



// (optimal) -tabulation t.c- O(n * k)  s.c- O(n * k)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false)); // Initialize a 2D DP arr with dimensions (n x k+1) to store subproblem results

    for (int i = 0; i < n; i++) { // Base case: If target sum is 0, we can always achieve it by taking no elements
        dp[i][0] = true;
    }

    if (arr[0] <= k) { // Base case: If first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++) { // Fill DP arr iteratively
        for (int target = 1; target <= k; target++) {

            bool notTaken = dp[ind - 1][target]; // If we don't take current element, result is same as previous row
            bool taken = false; // If we take current element, subtract its value from target and check previous row

            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = notTaken || taken; // Store result in DP arr for current subproblem
        }
    }

    return dp[n - 1][k]; // final result is stored in dp[n-1][k]
}