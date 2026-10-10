//statement- given arr of words where each word consists of lowercase eng letters. wordA is predecessor of wordB if & only if we can insert exactly 1 letter anywhere in wordA 
//           without changing order of r chars to make it equal to wordB. For ex, "abc" is predecessor of "abac", while "cba" is not predecessor of "bcad".
//           word chain is seq of words [w1, w2, ..., wk] with k >= 1, where w1 is predecessor of w2, w2 is predecessor of w3, & so on. single word is trivially word chain with k == 1.
//           Return length of longest possible word chain with words chosen from given list of words.


// (optimal) -memoization t.c- O(n * n * l) s.c- O(n + n)
bool checkPossible(string &s1, string &s2) {
    if (s1.size() != s2.size() + 1) return false;        // length must differ by 1

    int first = 0, second = 0;                           // pointers for both strings

    while (first < s1.size() && second < s2.size()) {
        if (s1[first] == s2[second]) {
            first++;                                     // match found
            second++;
        }
        else first++;                                    // skip one character in longer string
    }

    return second == s2.size();                           // all shorter characters matched
}

bool comp(string s1, string s2) {
    return s1.size() < s2.size();                          // sort by increasing length
}

int solve(int i, vector<string>& arr, vector<int>& dp) {
    if (dp[i] != -1) return dp[i];                        // return stored result

    dp[i] = 1;                                            // every word forms a chain of length 1

    for (int prev = 0; prev < i; prev++) {
        if (checkPossible(arr[i], arr[prev]))              // check predecessor
            dp[i] = max(dp[i], 1 + solve(prev, arr, dp)); // extend chain
    }

    return dp[i];                                         // longest chain ending at i
}

int longestStrChain(vector<string>& arr) {
    sort(arr.begin(), arr.end(), comp);                   // shorter words first

    int n = arr.size(), maxi = 1;
    vector<int> dp(n, -1);                                // memoization table

    for (int i = 0; i < n; i++)
        maxi = max(maxi, solve(i, arr, dp));               // check each ending word

    return maxi;                                           // longest string chain
}



// (optimal) - tabulation t.c- O(n * n * l) s.c- O(n)
bool checkPossible(string &s1, string &s2) {
    if (s1.size() != s2.size() + 1) return false;        // length must differ by 1

    int first = 0, second = 0;                           // pointers for both strings

    while (first < s1.size() && second < s2.size()) {
        if (s1[first] == s2[second]) {
            first++;                                     // match found
            second++;
        }
        else first++;                                    // skip one character in longer string
    }

    return second == s2.size();                           // all shorter characters matched
}

bool comp(string s1, string s2) {
    return s1.size() < s2.size();                          // sort by increasing length
}

int longestStrChain(vector<string>& arr) {
    sort(arr.begin(), arr.end(), comp);                   // shorter words first

    int n = arr.size(), maxi = 1;
    vector<int> dp(n, 1);                                 // each word starts a chain

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (checkPossible(arr[i], arr[prev]))          // check predecessor
                dp[i] = max(dp[i], 1 + dp[prev]);         // extend chain
        }

        maxi = max(maxi, dp[i]);                          // update longest chain
    }

    return maxi;                                           // longest string chain
}