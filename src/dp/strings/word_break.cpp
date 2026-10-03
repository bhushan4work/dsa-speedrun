//statement- Given string, dictionary of strings. return true if s can be segmented into space-separated seq of 1 or more dictionary words otherwise return false.
//Note: same word in dictionary can be used multiple times in segmentation


// (optimal) -memoization t.c- O(n ^ 2 * w * l)  s.c- O(n + n)
bool solve(int i, string &s, vector<string> &wordDict, vector<int> &dp) {
    if (i == s.size()) return true;                              // reached end of string

    if (dp[i] != -1) return dp[i];                              // already calculated

    for (int j = i; j < s.size(); j++) {
        string x = s.substr(i, j - i + 1);                      // take current substring

        if (find(wordDict.begin(), wordDict.end(), x) != wordDict.end() && // word exists
            solve(j + 1, s, wordDict, dp))                      // check remaining string
            return dp[i] = 1;                                   // valid segmentation found
    }

    return dp[i] = 0;                                           // no valid segmentation
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> dp(s.size(), -1);                               // memoization array
    return solve(0, s, wordDict, dp);                            // start from index 0
}



// (optimal) -tabulation t.c- O(n ^ 2 * w * l)  s.c- O(n)
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<int> dp(n + 1, 0);                                   // dp[i] = valid segmentation up to i
    dp[0] = 1;                                                  // empty string is valid

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            string x = s.substr(j, i - j);                     // take current substring

            if (dp[j] && find(wordDict.begin(), wordDict.end(), x) != wordDict.end()) { // valid prefix + word
                dp[i] = 1;                                     // current prefix can be segmented
                break;                                         // no need to check further
            }
        }
    }

    return dp[n];                                               // answer for complete string
}