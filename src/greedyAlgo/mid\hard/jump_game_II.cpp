//statement- arr represents max no of steps you can jump forward from that element, return min no of steps required to reach end


//(brute) -using recursion t.c- O(2 ^ n)  s.c- O(n) 
int solve(int i, vector<int>& nums) {
    int n = nums.size();

    if (i >= n - 1) return 0; // Base case: already at or beyond last index → no more jumps needed

    int ans = INT_MAX;
    for (int j = 1; j <= nums[i]; j++) {
        if (i + j < n) { // Ensure we stay within bounds
            ans = min(ans, 1 + solve(i + j, nums)); // Take 1 jump + result of subproblem
        }
    }
    return ans;
}

int jump(vector<int>& nums) {
    return solve(0, nums);
}


//(better) -using dp\memoization t.c- O(n ^ 2)  s.c- O(2n)  
int solve(int i, vector<int>& nums, vector<int>& dp) {
    int n = nums.size();

    if (i >= n - 1) return 0; // Base case: reached or crossed last index

    if (dp[i] != -1) return dp[i]; // If already computed, return stored result

    int ans = INT_MAX;
    for (int j = 1; j <= nums[i]; j++) {
        if (i + j < n) {
            ans = min(ans, 1 + solve(i + j, nums, dp));
        }
    }
    return dp[i] = ans; // Store result before returning
}

int jump(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, -1); // dp[i] = minimum jumps needed from index i → end

    return solve(0, nums, dp);
}


//(optimal) -greedy t.c- O(n)  s.c- O(1)
int jump(vector<int>& nums) {
    int n = nums.size();

    int jumps = 0;      // number of jumps taken
    int end = 0;        // end of current jump range
    int farthest = 0;   // farthest index reachable so far

    // We don't need to process last index
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]); // Update the farthest we can reach from curr position

        if (i == end) { // If we reached the end of current jump range
            jumps++; // We must take a jump
            end = farthest; // Extend the range to farthest reachable
        }
    }
    return jumps;
}