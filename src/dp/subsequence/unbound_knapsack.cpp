//statement- Given 2 arr, val & wt, W which is max capacity of knapsack, determine max value achievable by selecting subset of items such that
//           total wt of selected items doesnt exceed W. goal is to maximize sum of values of selected items while keeping total wt within W


// (optimal) -memoization t.c- O(n * amt)  s.c- O(n + n * amt)
int solve(int index, int capacity, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {
    if (index == 0) { // first item can fill all usable capacity.
        int copies = capacity / weights[0];

        return copies * values[0];
    }

    if (dp[index][capacity] != -1) { // A saved state avoids repeated recursive work.
        return dp[index][capacity];
    }

    int notTake = solve(index - 1, capacity, weights, values, dp); // Skipping exposes only earlier item types.
    int take = -1000000000; // sentinel rejects an unavailable take choice.

    if (weights[index] <= capacity) { // A fitting item leaves a valid smaller capacity.
        int remainingValue = solve(index, capacity - weights[index], weights, values, dp); // same index permits another item copy.
        
        take = values[index] + remainingValue; // current copy adds value to remainder.
    }

    dp[index][capacity] = max(notTake, take); // Saving max prevents later recalculation.

    return dp[index][capacity];
}

int unboundedKnapsack(vector<int>& weights, vector<int>& values, int capacity) { // Returns max value within capacity.
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1)); // Negative markers identify uncalculated states.

    return solve(n - 1, capacity, weights, values, dp); // last index exposes every available item type.
}



// (optimal) -tabulation t.c- O(n * amt)  s.c- O(n * amt)
int unboundedKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0)); // Each cell stores one item-capacity answer.

    for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) { // first row uses unlimited first-item copies.
        int copies = currentCapacity / weights[0];

        dp[0][currentCapacity] = copies * values[0];
    }

    for (int index = 1; index < n; index++) { // Each later row introduces one more item type.
        for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) { // Ascending capacity enables same-row reuse.
            int notTake = dp[index - 1][currentCapacity]; // previous row represents skipping.
            int take = -1000000000; // sentinel rejects an unavailable take.

            if (weights[index] <= currentCapacity) { // A fitting item reads a smaller same-row state.
                int remainingValue = dp[index][currentCapacity - weights[index]];

                take = values[index] + remainingValue; // curr copy adds to remainder.
            }

            dp[index][currentCapacity] = max(notTake, take); // larger choice completes curr state.
        }
    }

    return dp[n - 1][capacity]; // final cell represents complete problem.
}