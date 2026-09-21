//statement- Given arr of n integers, diff, cnt no of ways to partition arr into 2 subsets S1 & S2 such that: 1) ∣S1−S2∣ = diff & S1 ≥ S2. Return result modulo 109 + 7.
//Note: partition means that union of S1 & S2 is original array, & no element is left out or used twice, every element of arr belongs to exactly one of the 2 subsets


// (optimal) -memoization t.c- O(n * k)  s.c- O(n + n * k)
int mod = 1000000007;

int solve(int index, int target, vector<int>& arr, vector<vector<int>>& dp) { // Counts target-sum subsets through one index.
    if (index == 0 && target == 0 && arr[0] == 0) { // A zero creates two distinct zero-sum choices.
        return 2;
    }

    if (index == 0 && (target == 0 || target == arr[0])) { // An empty choice or one matching value works.
        return 1;
    }

    if (index == 0) { // No valid selection reaches another first-index state.
        return 0;
    }

    if (dp[index][target] != -1) { // A cached count avoids repeated recursive tree.
        return dp[index][target];
    }

    int notTake = solve(index - 1, target, arr, dp); // Skipping preserves required remaining sum.
    int take = 0;
    if (arr[index] <= target) { // Taking is legal only within remaining target.
        take = solve(index - 1, target - arr[index], arr, dp); // Taking removes current value from target.
    }

    dp[index][target] = (notTake + take) % mod; // cache stores merged disjoint choices.
    return dp[index][target];
}

int countPartitions(vector<int>& arr, int difference) { // Counts partitions with requested sum difference.
    int n = arr.size();
    int totalSum = 0;
    for (int value : arr) { 
        totalSum += value; // complete sum connects both subset equations.
    }

    int remaining = totalSum - difference;
    if (remaining < 0 || remaining % 2 != 0) { // A negative or odd remainder cannot form S2.
        return 0;
    }

    int target = remaining / 2; // smaller subset sum becomes counting target.
    vector<vector<int>> dp(n, vector<int>(target + 1, -1)); // Negative cells mark uncalculated recursive states.

    return solve(n - 1, target, arr, dp); // Every index remains available at starting state.
}



// (optimal) -tabulation t.c- O(n * k)  s.c- O(n * k)
int mod = 1000000007;
int countPartitions(vector<int>& arr, int difference) { // Counts partitions with requested sum difference.
    int n = arr.size();
    int totalSum = 0;
    for (int value : arr) { // complete sum connects both subset equations.
        totalSum += value;
    }

    int remaining = totalSum - difference;
    if (remaining < 0 || remaining % 2 != 0) { // A negative or odd remainder cannot form S2.
        return 0;
    }

    int target = remaining / 2; // smaller subset sum becomes counting target.
    vector<vector<int>> dp(n, vector<int>(target + 1, 0)); // Each cell counts subsets for one index and sum.
    if (arr[0] == 0) { // A leading zero has take and skip zero-sum choices.
        dp[0][0] = 2;
    }
    else {
        dp[0][0] = 1;
    }

    if (arr[0] != 0 && arr[0] <= target) { // A non-zero first value creates one matching subset.
        dp[0][arr[0]] = 1;
    }

    for (int index = 1; index < n; index++) { // Every row uses only completed preceding row.
        for (int currentTarget = 0; currentTarget <= target; currentTarget++) {
            int notTake = dp[index - 1][currentTarget]; // Skipping keeps same target count.
            int take = 0;
            if (arr[index] <= currentTarget) { // Taking is legal only within current target.
                take = dp[index - 1][currentTarget - arr[index]]; // earlier row supplies reduced target.
            }

            dp[index][currentTarget] = (notTake + take) % mod; // Both disjoint choices build current state.
        }
    }

    return dp[n - 1][target]; // last row includes every array index.
}