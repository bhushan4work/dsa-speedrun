//statement- given 2 str s,t of size m,n ;return min window substr of s such that every char in t (including duplicates) is included in the window of s

//(brute) t.c- O(n^2)  s.c- O(256) 
string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    int minLen = INT_MAX;   // store minimum length found
    int startInd = -1;      // starting index of best window

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> mpp; // Frequency map of char needed from t
        for (char c : t) {
            mpp[c]++;
        }

        int cnt = 0; // how many characters of t we have matched so far
        for (int j = i; j < n; j++) {
            if (mpp[s[j]] > 0) { // If this char is still needed, we matched one required char
                cnt++;
            }
            mpp[s[j]]--; // decr the mpp for this char (even if it becomes negative)

            if (cnt == m) { // If we have matched all characters of t
                // Check if this window is smaller than previous best
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startInd = i;
                }
                break; // This is the smallest window for this i, so break
            }
        }
    }
    if (startInd == -1) return ""; // If no valid window was found
    return s.substr(startInd, minLen); // Return the minimum window substring
}


//(optimal) t.c- O(n)  s.c- O(256)  
string minWindow(string s, string t) {
    if (t.size() > s.size()) return ""; // handling edge case
    int n = s.size();
    int m = t.size();

    unordered_map<char, int> mpp;
    for (char c : t) {
        mpp[c]++;  // count frequency of each char in t
    }

    int l = 0, r = 0;
    int minLen = INT_MAX;   // length of best min window
    int startInd = -1;
    int cnt = 0;            // how many characters matched so far

    while (r < n) {
        if (mpp[s[r]] > 0) { // If this char is still needed, we matched one
            cnt++;
        }
        mpp[s[r]]--; // Always decrease count (can go negative)

        while (cnt == m) { // Try to shrink window from left while it's valid
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                startInd = l;
            }

            mpp[s[l]]++; // Put back the left char

            if (mpp[s[l]] > 0) { // If this char becomes needed again, window is no longer valid
                cnt--;
            }
            l++; // move left pointer
        }
        r++; // move right pointer
    }

    if (startInd == -1) return "";
    return s.substr(startInd, minLen);
}

