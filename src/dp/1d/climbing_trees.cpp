//statement- Given no of stairs. Starting from 0th stair we need to climb to “Nth” stair. At a time we can climb either 1 or 2 steps. 
//           return total no of distinct ways to reach from 0th to Nth stair


// (optimal) -memoization t.c- O(n)  s.c- O(n)
int solve(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;       // base case

    if (dp[n] != -1) return dp[n];        // return already calculated answer

    dp[n] = solve(n - 1, dp) +            // take 1 step
            solve(n - 2, dp);              // take 2 steps

    return dp[n];                          // store and return answer
}
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);             // initialize dp with -1

    return solve(n, dp);                   // calculate number of ways
}


// (optimal) -tabulation t.c- O(n)  s.c- O(n)
int climbStairs(int n) {
    vector<int> dp(n + 1, 0);              // dp[i] = ways to reach ith stair

    dp[0] = 1;                             // 1 way to reach 0 stairs
    dp[1] = 1;                             // 1 way to reach 1 stair

    for (int i = 2; i <= n; i++) {         // calculate from 2 to n
        dp[i] = dp[i - 1] +                // come from previous stair
                dp[i - 2];                 // or jump from two stairs below
    }

    return dp[n];                          // return total number of ways
}