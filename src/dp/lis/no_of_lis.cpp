//statement- Given an arr, find no of Longest Increasing Subsequences in arr


// (optimal) -memoization t.c- O(n * n) s.c- O(n + n)
int solve(int i, vector<int>& nums, vector<int>& len, vector<int>& cnt) {
    if (len[i] != -1) return len[i];                     // already computed

    len[i] = 1;                                          // subsequence containing nums[i]
    cnt[i] = 1;                                          // one way to form it

    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {                         // increasing pair
            solve(j, nums, len, cnt);                    // compute previous state

            if (len[j] + 1 > len[i]) {
                len[i] = len[j] + 1;                     // found longer subsequence
                cnt[i] = cnt[j];                         // inherit its count
            } else if (len[j] + 1 == len[i]) {
                cnt[i] += cnt[j];                        // another way to reach same length
            }
        }
    }

    return len[i];                                        // longest length ending at i
}

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> len(n, -1), cnt(n, 0);                   // lengths and counts

    for (int i = 0; i < n; i++)
        solve(i, nums, len, cnt);                        // compute each ending state

    int longest = *max_element(len.begin(), len.end());  // global LIS length
    int ans = 0;

    for (int i = 0; i < n; i++)
        if (len[i] == longest) ans += cnt[i];            // sum counts of longest subsequences

    return ans;
}



// (optimal) -tabulation t.c- O(n * n) s.c- O(n)
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);                     // lengths and counts

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {                     // increasing pair
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;                   // update longest length
                    cnt[i] = cnt[j];                     // inherit count
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];                    // add another valid way
                }
            }
        }
    }

    int longest = *max_element(dp.begin(), dp.end());    // global LIS length
    int ans = 0;

    for (int i = 0; i < n; i++)
        if (dp[i] == longest) ans += cnt[i];             // sum counts for maximum length

    return ans;
}