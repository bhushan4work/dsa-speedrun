//statement- frog wants to climb staircase with n steps. Given integer arr heights, integer k. To jump from ith step to jth step, frog requires abs(heights[i] - heights[j]) energy. 
//           frog can jump from ith step to any step in range [i + 1, i + k], provided it exists. Return min amt of energy required by frog to go from 0th step to (n-1)th step.


// (optimal) -memoization t.c- O(n * k)  s.c- O(n + n)
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    if (ind == 0) { // Base case: starting point has zero cost
        return 0;
    }

    if (dp[ind] != -1) { // Return already computed result
        return dp[ind];
    }

    int mmSteps = INT_MAX; // Initialize minimum steps as large value
    for (int j = 1; j <= k; j++) { // Try all possible jumps from 1 to k

        if (ind - j >= 0) { // Ensure jump does not go out of bounds
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]); // Cost of taking the jump
            mmSteps = min(jump, mmSteps); // Store the minimum cost
        }
    }
    return dp[ind] = mmSteps; // Save the result in dp array
}

int solve(int n, vector<int>& height, int k) { // Function to get minimum cost to reach end
    vector<int> dp(n, -1); // DP array initialized to -1

    return solveUtil(n - 1, height, dp, k); // Start recursion from last index
}



// (optimal) -tabulation t.c- O(n * k)  s.c- O(n + n)
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0; // Base case: cost to reach the first stone is 0

    for (int i = 1; i < n; i++) { // Iterate over each stone
        int mmSteps = INT_MAX; // Initialize the minimum cost for this stone as large value

        for (int j = 1; j <= k; j++) { // Try all possible jump lengths from 1 to k
            if (i - j >= 0) { // Ensure jump doesn't go out of bounds
                int jump = dp[i - j] + abs(height[i] - height[i - j]); // Cost of jumping from (i - j) to i
                mmSteps = min(mmSteps, jump); // Keep track of the minimum cost
            }
        }

        dp[i] = mmSteps; // Store the computed minimum cost for this stone
    }

    return dp[n - 1]; // The last element of dp stores the answer
}

int solve(int n, vector<int>& height, int k) { // Main function to solve the problem
    vector<int> dp(n, -1); // Initialize DP array with -1

    return solveUtil(n, height, dp, k); // Fill DP array iteratively
}
