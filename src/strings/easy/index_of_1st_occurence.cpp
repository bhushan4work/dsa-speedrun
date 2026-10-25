// statement- Given 2 strings s1 & s2, return index of 1st occurrence of s2 in s1, else return -1 if s2 is not part of s1


// (brute) t.c- O(m * n)  s.c- O(1)
int strStr(string s1, string s2) { 
    int m = s1.length();        // Get length of main string (haystack)
    int n = s2.length();           // Get length of substring to find (needle)

    for(int i = 0; i<= m-n; i++) {        // Iterate through s1 up to last index where s2 can still fit
        for(int j = 0; j<n; j++) {         // Iterate through each char of s2 to check for a match

            if(s1[i+j] != s2[j])          // If chars don't match at current offset
                break;               // Break out of inner loop to try next starting position

            if(j == n-1)                // If we have successfully reached end of s2 (all chars matched)
                return i;              // Return starting index 'i' where match was found
        }
    }

    return -1;              // Return -1 if substring s2 is not found within s1
}