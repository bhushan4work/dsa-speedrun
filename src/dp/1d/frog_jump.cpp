//statement- Given no of stairs & frog, frog wants to climb from 0th stair to (N-1)th stair. At a time frog can climb either 1 or 2 steps. height[N] arr is given.
//           Whenever frog jumps from stair i to j, energy consumed in jump is abs(height[i]- height[j]), where abs() means absolute diff.
//           return min energy that can be used by frog to jump from stair 0 to N-1


// (optimal) -memoization t.c- O(n)  s.c- O(n)
int solve(int ind, const vector<int>& height, vector<int>& dp) {
    if (ind == 0) { // If at first stone, cost is 0
        return 0; 
    }

    if (dp[ind] != -1) { // Return memoized result if already computed
        return dp[ind]; 
    }

    int jumpTwo = INT_MAX; // Initialize jumpTwo with a large value
    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]); // Compute cost when jumping from prev stone
    if (ind > 1) { // Compute cost when jumping from two stones back (ind - 2) if possible
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }

    return dp[ind] = min(jumpOne, jumpTwo); // Memoize & return min of 2 choices
}

int frogJump(const vector<int>& height) { // Helper to handle edge cases & start recursion
    if (height.empty()) { // Handle empty input
        return 0; 
    }

    int n = (int)height.size(); // Prepare dp with -1 indicating uncomputed states
    vector<int> dp(n, -1);

    return solve(n - 1, height, dp); // Start from last index
}


// (optimal) -tabulation t.c- O(n)  s.c- O(n)
int frogJump(const vector<int>& height) {
    if (height.empty()) { // Handle empty input
        return 0;
    }

    int n = (int)height.size(); // Fetch size of the input
    vector<int> dp(n, INT_MAX); // Create dp array where dp[i] = min energy to reach i
    dp[0] = 0; // Base case: cost to stand on first stone is zero

    for (int ind = 1; ind < n; ind++) { // Iterate over stones from index 1 to n-1
        int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]); // Compute cost for a jump from ind-1
        int jumpTwo = INT_MAX; // Initialize jumpTwo with large value

        if (ind > 1) { // If possible, compute cost for a jump from ind-2
            jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
        }

        dp[ind] = min(jumpOne, jumpTwo); // Take min of 2 options
    }

    return dp[n - 1]; // Return min energy to reach last stone
}