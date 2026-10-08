//statement- Given an arr, find largest subset such that every pair (a, b) of elements in subset satisfies a % b == 0 or b % a == 0.
//           Return subset in any order. If there are multiple solutions, return any one of them.
//Note: As there can be multiple correct answers, compiler returns 1 if ans is valid, else 0.


// (optimal) -memoization t.c- O(n * n) s.c- O(n + n)
int f(int i, vector<int>& nums, vector<int>& dp) {
    if (dp[i] != -1) return dp[i];                         // already calculated

    dp[i] = 1;                                             // single element subset

    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] % nums[i] == 0)                       // divisible pair
            dp[i] = max(dp[i], 1 + f(j, nums, dp));       // take nums[j]
    }

    return dp[i];                                         // best length from i
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());                       // sort for divisibility order

    int n = nums.size();
    vector<int> dp(n, -1);                                // memoized lengths

    int start = 0;
    for (int i = 0; i < n; i++) {
        if (f(i, nums, dp) > f(start, nums, dp))          // find best starting index
            start = i;
    }

    vector<int> ans;
    int i = start;
    ans.push_back(nums[i]);                               // add first element

    while (dp[i] > 1) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] % nums[i] == 0 &&                 // divisible
                dp[i] == 1 + dp[j]) {                     // belongs to optimal chain
                ans.push_back(nums[j]);                   // add element
                i = j;                                    // move forward
                break;
            }
        }
    }

    return ans;                                            // largest divisible subset
}



// (optimal) -tabulation t.c- O(n * n) s.c- O(n)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());                       // sort for divisibility order

    int n = nums.size();
    vector<int> dp(n, 1);                                 // longest subset ending at i
    int last = 0;                                         // index of last element

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0)                  // divisible pair
                dp[i] = max(dp[i], dp[j] + 1);            // extend subset

        }
        if (dp[i] > dp[last]) last = i;                   // best ending index
    }

    vector<int> ans;
    ans.push_back(nums[last]);                             // add last element

    while (dp[last] > 1) {
        for (int j = last - 1; j >= 0; j--) {
            if (nums[last] % nums[j] == 0 &&              // divisible
                dp[last] == dp[j] + 1) {                  // previous optimal element
                ans.push_back(nums[j]);                   // add element
                last = j;                                 // move backward
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());                      // restore original order
    return ans;                                            // largest divisible subset
}