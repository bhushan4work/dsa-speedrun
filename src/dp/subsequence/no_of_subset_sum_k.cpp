//statement- Given an arr of n integers, an integer K, cnt no of subsets of given arr that have sum equal to K


// (optimal) -memoization t.c- O(n * k)  s.c- O(n * k)
int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
    if (target == 0) { // Base case: if target is 0, we found a valid subset
        return 1;
    }

    if (index == 0) { // Base case: if we are at index 0, check if nums[0] equals target
        return (nums[0] == target ? 1 : 0);
    }

    if (dp[index][target] != -1) { // If already computed, return from dp
        return dp[index][target];
    }

    int notTake = solve(index - 1, target, nums, dp); // Case 1: Exclude current element
    int take = 0; // Case 2: Include current element (if it is not greater than target)

    if (nums[index] <= target) {
        take = solve(index - 1, target - nums[index], nums, dp);
    }

    return dp[index][target] = take + notTake; // Store result in dp and return
}

int countSubsets(vector<int>& nums, int target) {
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1)); // Initialize dp table with -1 (uncomputed states)

    return solve(nums.size() - 1, target, nums, dp);
}



// (optimal) -tabulation t.c- O(n * k)  s.c- O(n * k)
int countSubsets(vector<int>& arr, int K) {
    int n = arr.size(); // Get no of elements
    vector<vector<int>> dp(n, vector<int>(K + 1, 0)); // Create dp table with dimensions n x (K+1)
    dp[0][0] = 1; // Base case: one subset (empty set) makes sum 0

    if (arr[0] <= K) { // If first element is <= K, mark dp[0][arr[0]] as 1
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) { // Fill table
        for (int target = 0; target <= K; target++) {
            int notTake = dp[i - 1][target]; // Exclude current element
            int take = 0; // Include current element if possible

            if (arr[i] <= target) {
                take = dp[i - 1][target - arr[i]];
            }

            dp[i][target] = notTake + take; // Total ways
        }
    }

    return dp[n - 1][K]; // Final answer
}