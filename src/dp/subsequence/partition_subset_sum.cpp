//statement- Given an arr, return true if arr can be partitioned into 2 subsets such that sum of elements in both subsets is equal else return false


// (optimal) -memoization t.c- O(n * k)  s.c- O(n + n * k)
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) { // Base case: If target sum is 0, we found a valid partition
        return true;
    }

    if (ind == 0) { // Base case: If we have considered all elements and target is still not 0, return false
        return arr[0] == target;
    }

    if (dp[ind][target] != -1) { // If result for this state is already calculated, return it
        return dp[ind][target];
    }

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp); // Recursive cases 1. Exclude curr element
    bool taken = false; // 2. Include curr element if it doesn't exceed target

    if (arr[ind] <= target) {
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = notTaken || taken; // Store result in DP table and return
}

bool canPartition(int n, vector<int>& arr) { 
    int totSum = 0;

    for (int i = 0; i < n; i++) { // Calculate total sum of arr
        totSum += arr[i];
    }

    if (totSum % 2 == 1) { // If total sum is odd, it cannot be partitioned into two equal subsets
        return false;
    }

    int k = totSum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); // Create a DP table with dimensions n x k+1 and initialize with -1

    return subsetSumUtil(n - 1, k, arr, dp); // Call subsetSumUtil function to check if it's possible to partition
}



// (optimal) -tabulation t.c- O(n * k)  s.c- O(n * k)
bool canPartition(int n, vector<int>& arr) {
    int totalSum = 0; // Step 1: Calculate total sum

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0) { // Step 2: If total sum is odd, partition is impossible
        return false;
    }

    int targetSum = totalSum / 2; // Step 3: Determine target sum for each subset
    vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false)); // Step 4: Create DP table and initialize

    for (int i = 0; i < n; i++) { // Step 5: Base case: sum 0 is always possible
        dp[i][0] = true;
    }

    if (arr[0] <= targetSum) { // Step 6: Initialize first row
        dp[0][arr[0]] = true;
    }

    for (int index = 1; index < n; index++) { // Step 7: Fill DP table
        for (int target = 1; target <= targetSum; target++) {
            bool notTaken = dp[index - 1][target];
            bool taken = false;

            if (arr[index] <= target) {
                taken = dp[index - 1][target - arr[index]];
            }

            dp[index][target] = notTaken || taken;
        }
    }

    return dp[n - 1][targetSum]; // Step 8: Return result
}