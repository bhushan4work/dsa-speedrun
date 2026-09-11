//statement- thief needs to rob. houses are arranged in circular manner. 1st & last house are adjacent to each other. security system in street is such that if adjacent houses are robbed, police will get notified.
//           Given arr of integers which represents money at each house, return max amt of money that thief can rob without alerting police


// (optimal) - memoization t.c- O(n)  s.c- O(n + n)
int solve(vector<int>& arr, int i, int end, vector<int>& dp) {
    if (i > end) { // No house left to rob
        return 0;
    }

    if (i == end) { // Only one house is left
        return arr[i];
    }

    if (dp[i] != -1) { // Return already computed value
        return dp[i];
    }

    int pick = arr[i] + solve(arr, i + 2, end, dp); // Rob current house
    int notPick = solve(arr, i + 1, end, dp); // Skip current house

    return dp[i] = max(pick, notPick); // Store and return maximum
}

int rob(vector<int>& arr) {
    int n = arr.size();

    if (n == 1) { // Only one house
        return arr[0];
    }

    vector<int> dp1(n, -1); // For houses 0 to n-2
    vector<int> dp2(n, -1); // For houses 1 to n-1

    int case1 = solve(arr, 0, n - 2, dp1); // Exclude last house
    int case2 = solve(arr, 1, n - 1, dp2); // Exclude first house

    return max(case1, case2); // Take the better case
}



// (optimal) - tabulation t.c- O(n)  s.c- O(n)
int rob(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array

    if (n == 1) { // If only one house exists
        return arr[0]; // Rob the only house
    }

    vector<int> dp1(n, 0); // DP for houses 0 to n-2 (exclude last)
    dp1[0] = arr[0]; // Base case: rob first house
    dp1[1] = max(arr[0], arr[1]); // Base case: rob either first or second

    for (int i = 2; i < n - 1; i++) { // Process houses from index 2 to n-2
        dp1[i] = max(arr[i] + dp1[i - 2], dp1[i - 1]); // Pick current or skip current
    }

    vector<int> dp2(n, 0); // DP for houses 1 to n-1 (exclude first)
    dp2[1] = arr[1]; // Base case: rob second house
    dp2[2] = max(arr[1], arr[2]); // Base case: rob either second or third

    for (int i = 3; i < n; i++) { // Process houses from index 3 to n-1
        dp2[i] = max(arr[i] + dp2[i - 2], dp2[i - 1]); // Pick current or skip current
    }

    return max(dp1[n - 2], dp2[n - 1]); // Return maximum from both cases
}