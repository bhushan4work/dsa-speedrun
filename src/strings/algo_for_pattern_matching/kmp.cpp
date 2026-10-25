// statement- Given 2 strings s1 & s2, return index of 1st occurrence of s2 in s1, else return -1 if s2 is not part of s1


// (optimal) -kmp algo t.c- O(m + n)  s.c- O(n)
void computeLPS(string s2, int n, vector<int>& lps) {         // Helper function to compute LPS array
    int prevLPS = 0;                       // Length of previous longest prefix suffix
    lps[0] = 0;                                 // LPS of first character is always 0
    int i = 1;                                                // Pointer to iterate through needle
    
    while (i < n) {                   // Build LPS array for needle string
        if (s2[i] == s2[prevLPS]) {             // If current character matches prefix character
            lps[i] = prevLPS + 1;             // Store incremented length of matching prefix
            prevLPS++;                        // Advance prefix pointer
            i++;                   // Advance needle pointer
        }
        else {                        // If mismatch
            if (prevLPS == 0) {            // If we cannot fall back any fur
                lps[i] = 0;                // LPS for current character is 0
                i++;                        // Advance needle pointer
            }
            else {                         // If we can fall back to a shorter prefix
                prevLPS = lps[prevLPS - 1];        // Fall back using previously computed LPS values
            }
        }
    }
}

int strStr(string s1, string s2) {     
    int m = s1.length();          // Get length of main string (haystack)
    int n = s2.length();           // Get length of substring to find (needle)

    if (n == 0) return 0;                // Edge case: if needle is empty, return 0
    
    vector<int> lps(n, 0);                      // Initialize LPS array of size n with 0s
    computeLPS(s2, n, lps);                   // Call helper function to populate LPS array
    
    int i = 0;                 // Pointer for haystack string (s1)
    int j = 0;                  // Pointer for needle string (s2)
    
    while (i < m) {                  // Iterate through haystack string
        if (s1[i] == s2[j]) {             // If characters match between haystack and needle
            i++;                  // Advance haystack pointer
            j++;                     // Advance needle pointer
        }
        
        if (j == n) {               // If entire needle has been successfully matched
            return i - j;             // Return starting index of match in haystack
        }
        else if (i < m && s1[i] != s2[j]) {              // If a mismatch occurs after some matches
            if (j == 0) {             // If mismatch is at very first character of needle
                i++;                      // Move to next character in haystack
            }
            else {                   // If mismatch is in middle of needle
                j = lps[j - 1];             // Use LPS array to skip unnecessary comparisons
            }
        }
    }
    
    return -1;               // Return -1 if substring s2 is not found within s1
}