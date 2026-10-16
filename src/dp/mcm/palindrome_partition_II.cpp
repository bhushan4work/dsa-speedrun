//statement- Given string s, place cuts betw adj chars so every resulting substr is palindrome. Return smallest possible no of cuts. palindrome reads identically from both sides.
//           Every part must be non-empty contiguous substr, & parts must cover complete string in original order.


// (optimal) -memoization t.c- O(n ^ 3) s.c- O(n + n)
bool isPalindrome(string& s, int left, int right) { 
    while (left < right) { // Compares matching positions from both ends.
        if (s[left] != s[right]) { // A mismatch makes the range invalid.
            return false;
        }

        left++; // Moves both pointers toward the center.
        right--;
    }

    return true;
}

int solve(string& s, int end, vector<int>& dp) {
    if (end == 0) { // An empty prefix needs no piece.
        return 0;
    }

    if (dp[end] != -1) { // A stored answer avoids repeated recursion.
        return dp[end];
    }

    int best = s.size() + 1; // The sentinel exceeds every possible piece count.
    for (int start = end - 1; start >= 0; start--) { // Tries every possible final piece.
        if (isPalindrome(s, start, end - 1)) { // Only a palindrome can form a valid piece.
            int current = 1 + solve(s, start, dp); // The final palindrome adds one piece.

            best = min(best, current); // The smallest valid partition is retained.
        }
    }

    dp[end] = best; // The prefix answer is cached for later calls.
    return dp[end];
}

int minCut(string s) { 
    if (s.size() == 0) { // Empty input needs no cut.
        return 0;
    }

    vector<int> dp(s.size() + 1, -1); // Negative values mark uncalculated prefixes.
    int pieces = solve(s, s.size(), dp); // The full prefix contains every character.

    return pieces - 1; // One fewer cut than pieces joins the partition.
}



// (optimal) -tabulation t.c- O(n ^ 2) s.c- O(n ^ 2 + n)
int minCut(string s) {
    int n = s.size();
    if (n == 0) { // Empty input needs no cut.
        return 0;
    }

    vector<vector<bool>> palindrome(n, vector<bool>(n, false)); // table records every palindromic range.
    for (int start = n - 1; start >= 0; start--) { // Right-to-left order prepares inner ranges.
        for (int end = start; end < n; end++) { // Every range beginning at start is checked.
            bool sameEnds = s[start] == s[end]; // Matching ends are required.
            bool shortRange = end - start <= 1; // Short ranges have no unresolved middle.

            if (sameEnds && (shortRange || palindrome[start + 1][end - 1])) { // A valid middle completes palindrome.
                palindrome[start][end] = true;
            }
        }
    }

    vector<int> dp(n + 1, n + 1); // Large values mark unfinished prefix states.
    dp[0] = 0; // An empty prefix needs no piece.

    for (int end = 1; end <= n; end++) { // Prefixes are completed from short to long.
        for (int start = 0; start < end; start++) { // Every possible final piece is considered.
            if (palindrome[start][end - 1]) { // Only a palindrome can close prefix.
                int current = dp[start] + 1; // final palindrome adds one piece.

                dp[end] = min(dp[end], current); // smallest valid partition is retained.
            }
        }
    }

    return dp[n] - 1; // One fewer cut than pieces joins partition.
}