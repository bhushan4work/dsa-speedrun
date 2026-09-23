//statement- Given arr of n integer, target, build an expression using integers where each it can be prefixed with either '+' or '-' sign.
//           achieve target sum by evaluating all possible combinations of these signs. Determine no of ways to achieve target sum, return your ans with modulo 109+7


// (optimal) -memoization t.c- O(n * t)  s.c- O(n + n * t)
int dp[21][2001];

int f(int i, int sum, int n, vector<int>& nums) {
    if (i == n)
        return sum == 0; // valid subset only after using all elements

    if (dp[i][sum] != -1)
        return dp[i][sum]; // state already calculated

    int nottake = f(i + 1, sum, n, nums); // don't take nums[i]
    int take = 0;
    if (nums[i] <= sum)
        take = f(i + 1, sum - nums[i], n, nums); // take nums[i]

    return dp[i][sum] = take + nottake; // total ways
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++)
        total += nums[i]; // total sum

    if (target > total || target < -total)
        return 0; // target impossible

    if ((total + target) % 2 != 0)
        return 0; // required sum must be integer

    int need = (total + target) / 2; // required subset sum
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= need; j++)
            dp[i][j] = -1; // initialize dp

    return f(0, need, n, nums);
}



// (optimal) -tabulation t.c- O(n * t)  s.c- O(t)
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++)
        total += nums[i]; // total sum

    if (target > total || target < -total)
        return 0; // target impossible

    if ((total + target) % 2 != 0)
        return 0; // required sum must be integer

    int need = (total + target) / 2; // required subset sum
    vector<int> dp(need + 1, 0);
    dp[0] = 1; // empty subset forms sum 0
    for (int i = 0; i < n; i++) {
        for (int j = need; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]]; // take + not take
        }
    }

    return dp[need]; // number of valid subsets
}