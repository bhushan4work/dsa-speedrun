//statement- Given an arr, return length of longest strictly increasing subseq. find length of longest subseq in which every element is greater than prev one


// (optimal) -memoization t.c- O(n * n) s.c- O(n + n)
int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
    if (i == nums.size()) return 0;                         // all elements processed

    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];     // return stored result

    int notTake = 0 + solve(i + 1, prev, nums, dp);            // skip current element
    int take = 0;                                           // initialize take

    if (prev == -1 || nums[i] > nums[prev])
        take = 1 + solve(i + 1, i, nums, dp);               // include current element

    return dp[i][prev + 1] = max(take, notTake);            // store maximum length
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));      // memo table

    return solve(0, -1, nums, dp);                          // start with no previous element
}



// (optimal) -tabulation t.c- O(n * n) s.c- O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));   // initialize dp table

    for (int i = n - 1; i >= 0; i--) {                     // process elements backwards
        for (int prev = i - 1; prev >= -1; prev--) {       // consider previous index
            int notTake = dp[i + 1][prev + 1];             // skip current element
            int take = 0;                                  // initialize take

            if (prev == -1 || nums[i] > nums[prev])
                take = 1 + dp[i + 1][i + 1];               // include current element

            dp[i][prev + 1] = max(take, notTake);           // store maximum length
        }
    }

    return dp[0][0];                                       // start at index 0, prev = -1
}