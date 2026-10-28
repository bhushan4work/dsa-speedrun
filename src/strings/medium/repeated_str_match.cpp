//statement- Given 2 strs a, b. return min no of times u should repeat str a so that str b is substr of it. If its impossible for b​​​​​​ to be substr of a after repeating it, return -1.
//Note: str "abc" repeated 0 times is "", repeated 1 time is "abc" & repeated 2 times is "abcabc"


// (optimal) t.c- O(n + m)  s.c- O(n)
bool rabinKarp(string s, string pattern) {
    int n = s.length();                   // Get length of source string
    int m = pattern.length();         // Get length of target pattern
    if (n < m) {               // If source is shorter than pattern
        return false;              // It is impossible to find a match
    }
    
    long long p = 31;         // Prime base for polynomial rolling hash
    long long mod = 1e9 + 9;           // Large prime modulo to prevent overflow
    long long p_pow = 1;             // Multiplier for highest degree character
    
    for (int i = 0; i < m - 1; i++) {         // Loop to calculate p^(m-1) % mod
        p_pow = (p_pow * p) % mod;      // Keep multiplying base and taking modulo
    }
    
    long long hash_pattern = 0;      // Rolling hash value for target pattern
    long long hash_window = 0;        // Rolling hash value for current window
    
    for (int i = 0; i < m; i++) {        // Loop over first m characters
        hash_pattern = (hash_pattern * p + (pattern[i] - 'a' + 1)) % mod; // Build pattern hash
        hash_window = (hash_window * p + (s[i] - 'a' + 1)) % mod;      // Build first window hash
    }
    
    for (int i = 0; i <= n - m; i++) {         // Slide window across source string
        if (hash_pattern == hash_window) {      // If hash values match
            bool match = true;            // Assume it is a valid match initially
            for (int j = 0; j < m; j++) {       // Iterate character by character to confirm
                if (s[i + j] != pattern[j]) {    // If any character mismatches
                    match = false;     // Mark as false positive
                    break;        // Break early to save time
                }
            }
            if (match) {     // If exact match is confirmed
                return true;     // We found pattern
            }
        }
        
        if (i < n - m) {     // If there are more windows left to check
            hash_window = (hash_window - (s[i] - 'a' + 1) * p_pow) % mod;    // Remove leading character
            if (hash_window < 0) {    // If modulo subtraction yields a negative result
                hash_window += mod;        // Add modulo to wrap around to positive
            }
            hash_window = (hash_window * p + (s[i + m] - 'a' + 1)) % mod;   // Append new trailing character
        }
    }
    return false;      // Target pattern was never found
}

int repeatedStringMatch(string a, string b) {
    string repeatedA = a;       // Start with a single instance of string a
    int count = 1;             // Track how many times we have repeated a, initially its 1
    
    while (repeatedA.length() < b.length()) {        // Loop until repeatedA is atleast as long as b
        repeatedA += a;             // Append another instance of a
        count++;           // Increment our repeat counter
    }
    
    if (rabinKarp(repeatedA, b)) {    // Check if b exists in current repeated string
        return count;                 // If found, return current repeat count
    }
    
    repeatedA += a;       // Append one final instance to cover boundary splits
    if (rabinKarp(repeatedA, b)) {         // Check if b exists in this extended string
        return count + 1;               // If found now, return incremented count
    }
    
    return -1;       // If still not found, it is impossible
}