//statement- robber planning to rob. Each house has certain amt of money, only constraint stopping you from robbing is that u cant rob 2 adjacent houses
//           Given integer arr nums representing amt of money of each house, return max amt of money u can rob tonight without alerting police


// (optimal) -memoization t.c- O(n)  s.c- O(n + n)
int solve(vector<int>& arr, int i, vector<int>& dp) {
    if (i < 0) { // If index is negative, no element to pick
        return 0;
    }

    if (i == 0) { // If at first element, return its value
        return arr[0];
    }

    if (dp[i] != -1) { // Return already computed value
        return dp[i];
    }

    int pick = arr[i] + solve(arr, i - 2, dp); // Include current and move 2 back
    int notPick = solve(arr, i - 1, dp); // Exclude current and move 1 back

    return dp[i] = max(pick, notPick); // Store and return max of both choices
}

int rob(vector<int>& arr) { // Main function to be called externally
    int n = arr.size();
    vector<int> dp(n, -1); // DP array initialized with -1

    return solve(arr, n - 1, dp); // Start solving from last index
}



// (optimal) -tabulation t.c- O(n)  s.c- O(n)
int rob(vector<int>& arr) {
    int n = arr.size(); // Get the size of array
    if (n == 1) { // If array has only one element, return it
        return arr[0];
    }

    vector<int> dp(n); // Initialize dp array of size n
    dp[0] = arr[0]; // Base case: only one element
    dp[1] = max(arr[0], arr[1]); // Base case: max of first or second element

    for (int i = 2; i < n; i++) { // Iterate from 3rd element onwards
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]); // Either take current and add dp[i-2] or skip current and take dp[i-1]
    }
    
    return dp[n - 1]; // Final result at last index
}