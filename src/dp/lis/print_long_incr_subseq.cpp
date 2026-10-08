//statement- given an arr, return LIS i.e Index-wise Lexicographically Smallest. LIS is longest subseq where all elements are in strictly increasing order.
//           subseq A1 is Index-wise Lexicographically Smaller than another subseq A2 if, at 1st position where A1 & A2 differ, element in A1 appears earlier in array arr than corresponding element in S2.
//           return LIS that is Index-wise Lexicographically Smallest from given arr


// (optimal) -memoization t.c- O(n * n) s.c- O(n + n)
int lis(int i, vector<int>& arr, vector<int>& dp) {
    if (dp[i] != -1) return dp[i];                         // already calculated

    dp[i] = 1;                                             // arr[i] itself
    for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] > arr[i])                              // strictly increasing
            dp[i] = max(dp[i], 1 + lis(j, arr, dp));       // extend LIS
    }

    return dp[i];                                          // LIS starting at i
}

vector<int> LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);                                 // memo table

    for (int i = 0; i < n; i++)
        lis(i, arr, dp);                                   // calculate every LIS length

    int need = 0;                                          // required LIS length
    for (int i = 0; i < n; i++)
        need = max(need, dp[i]);                           // find maximum length

    vector<int> ans;                                       // answer subsequence
    int last = INT_MIN;                                    // previous selected value

    for (int i = 0; i < n && need > 0; i++) {
        if (arr[i] > last && dp[i] >= need) {              // earliest valid index
            ans.push_back(arr[i]);                         // choose this element
            last = arr[i];                                 // update previous value
            need--;                                        // one element selected
        }
    }

    return ans;                                            // index-wise lexicographically smallest LIS
}



// (optimal) -tabulation t.c- O(n * n) s.c- O(n)
vector<int> LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);                                  // LIS starting at each index

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i])                           // strictly increasing
                dp[i] = max(dp[i], 1 + dp[j]);              // extend LIS
        }
    }

    int need = 0;                                          // required LIS length
    for (int i = 0; i < n; i++)
        need = max(need, dp[i]);                           // find maximum length

    vector<int> ans;                                       // answer subsequence
    int last = INT_MIN;                                    // previous selected value

    for (int i = 0; i < n && need > 0; i++) {
        if (arr[i] > last && dp[i] >= need) {              // choose earliest valid index
            ans.push_back(arr[i]);                         // add element to LIS
            last = arr[i];                                 // update previous value
            need--;                                        // one element selected
        }
    }

    return ans;                                            // index-wise lexicographically smallest LIS
}