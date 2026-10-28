//statement- given a string s. u can convert s to palindrome by adding char in front of it. Return shortest palindrome u can find by performing this transformation


//(brute) t.c- O(n^2)  s.c- O(n)
bool isPalindrome(const string& s, int left, int right) { // Helper to check if a substring is a palindrome
    while (left < right) {                      // Loop until the two pointers meet in the middle
        if (s[left] != s[right]) {       // If characters at current pointers mismatch
            return false;            // It is not a palindrome, exit early
        }

        left++;                       // Move the left pointer forward
        right--;                    // Move the right pointer backward
    }
    return true;                // All characters matched, it is a palindrome
}

string shortestPalindrome(string s) {            // Main function to build the shortest palindrome
    int n = s.length();        // Get the length of the input string
    if (n == 0) {                // If the string is empty
        return s;           // An empty string is already a palindrome
    }
    
    for (int i = n - 1; i >= 0; i--) {           // Iterate backwards to find the longest palindromic prefix first
        if (isPalindrome(s, 0, i)) {            // If the prefix from index 0 to i is a palindrome
            string suffix = s.substr(i + 1);         // Extract the remaining characters after this prefix
            reverse(suffix.begin(), suffix.end());       // Reverse those remaining characters
            return suffix + s;         // Prepend the reversed characters to the original string
        }
    }
    
    return s;          // Fallback (in practice, i=0 is always a palindrome of length 1)
}



//(optimal) -kmp algo t.c- O(n)  s.c- O(n)
vector<int> buildLPS(string pattern) {   // Builds LPS array used by KMP to store longest prefix-suffix length at each index.
    int n = pattern.size();
    vector<int> lps(n, 0);  // lps[i] stores longest proper prefix that is also a suffix ending at index i.
    int length = 0;  // This stores current matched prefix length.
    int i = 1;   // Start from index 1 because lps[0] is always 0.

    while (i < n) {
        if (pattern[i] == pattern[length]) {  // If characters match, current prefix match can be extended by one character.
            length++;
            lps[i] = length;
            i++;
        }
        else if (length != 0) {  // If there is a mismatch after some matched characters, fall back to previous possible prefix length.
            length = lps[length - 1];
        }
        else {  // If there is no matched prefix left, this index cannot extend any prefix-suffix match.
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

string shortestPalindrome(string s) {  // Returns shortest palindrome that can be made by adding characters only in front of string.
    if (s.size() <= 1) {  // An empty string or a single character is already a palindrome.
        return s;
    }

    string reversed = s;   // Reverse string so prefix of s can be matched with its mirrored form.
    reverse(reversed.begin(), reversed.end());

    string combined = s + "#" + reversed;   // separator prevents false matches from crossing between 2 strings.
    vector<int> lps = buildLPS(combined);
    int palindromicPrefixLength = lps.back();   // This is length of longest prefix of s that is already a palindrome.
    string suffixToAdd = s.substr(palindromicPrefixLength);  // Only suffix after palindromic prefix must be mirrored and added in front.
    reverse(suffixToAdd.begin(), suffixToAdd.end());

    return suffixToAdd + s;
}