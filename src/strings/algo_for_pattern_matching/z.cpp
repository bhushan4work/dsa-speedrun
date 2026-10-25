// statement- Given 2 strings s1 & s2, return index of 1st occurrence of s2 in s1, else return -1 if s2 is not part of s1


// (optimal) -z algo t.c- O(m + n)  s.c- O(m + n)
vector<int> zFunction(string s) {   
    int n = s.length();              // Get total length of concatenated string
    vector<int> z(n, 0);          // Initialize Z-array of size n with 0s
    int l = 0, r = 0;                 // Initialize left and right boundaries of Z-box

    for (int i = 1; i < n; i++) {              // Iterate through string starting from index 1
        if (i <= r) {                   // If current index is inside current Z-box
            z[i] = min(r - i + 1, z[i - l]);         // Reuse previously computed value, bounded by right edge
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {     // Try to match characters and extend Z-box
            z[i]++;            // Increment match length
        }

        if (i + z[i] - 1 > r) {          // If new match stretches past current right boundary
            l = i;                  // Update left boundary of Z-box
            r = i + z[i] - 1;          // Update right boundary of Z-box
        }
    }

    return z;             // Return computed Z-array
}

int strStr(string text, string pattern) {     // Main function to find first occurrence
    if (pattern.length() == 0) return 0;          // Edge case: if pattern is empty, return 0
    
    string s = pattern + '$' + text;         // Concatenate pattern, a unique separator, and text
    vector<int> z = zFunction(s);            // Call helper function to compute Z-array for concatenated string
    int m = pattern.length();           // Get length of pattern

    for (int i = m + 1; i < z.size(); i++) {      // Iterate only through Z-array part belonging to text
        if (z[i] == m) {                // If Z-value perfectly matches pattern length
            return i - m - 1;              // Immediately return starting index in original text
        }
    }
    
    return -1;         // Return -1 if pattern is never found
}