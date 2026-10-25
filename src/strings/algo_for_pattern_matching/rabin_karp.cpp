// statement- Given 2 strings s1 & s2, return index of 1st occurrence of s2 in s1, else return -1 if s2 is not part of s1


// (optimal) -rabin karp algo t.c- O(m * n)  s.c- O(1)
int strStr(string s1, string s2) {  
    int m = s1.length();            // Get length of main string (haystack)
    int n = s2.length();            // Get length of substring to find (needle)
    
    if (n == 0) return 0;                       // Edge case: if needle is empty, return 0
    if (m < n) return -1;                 // Edge case: if haystack is shorter than needle, return -1
    
    int d = 256;                         // Number of characters in input alphabet
    int q = 101;                     // A prime number for modulo arithmetic to avoid integer overflow
    int h = 1;                    // Multiplier for most significant digit
    int p = 0;                    // Hash value for needle (s2)
    int t = 0;                    // Hash value for current window of haystack (s1)
    
    for (int i = 0; i < n - 1; i++)         // Precompute d^(n-1) % q to easily remove leading character
        h = (h * d) % q;                                          
        
    for (int i = 0; i < n; i++) {          // Calculate initial hash values for needle and first window
        p = (d * p + s2[i]) % q;                                  
        t = (d * t + s1[i]) % q;                                  
    }
    
    for (int i = 0; i <= m - n; i++) {          // Slide window over haystack string
        if (p == t) {                   // If hash values match, check for an exact character match
            int j = 0;                        // Initialize pointer to verify needle characters
            for (j = 0; j < n; j++) {              // Compare characters one by one to handle hash collisions
                if (s1[i + j] != s2[j])                   // If any character mismatches
                    break;                     // Break out of verification loop
            }
            if (j == n)                    // If all characters matched successfully
                return i;               // Return starting index of match
        }
        
        if (i < m - n) {                 // Ifre is still a next window to compute in haystack
            t = (d * (t - s1[i] * h) + s1[i + n]) % q;          // Rolling hash: remove leading char, shift, add trailing char
            
            if (t < 0)                    // If calculated hash becomes negative due to subtraction
                t = (t + q);                  // Add q to make it positive again
        }
    }
    
    return -1;                  // Return -1 if substring s2 is not found within s1
}