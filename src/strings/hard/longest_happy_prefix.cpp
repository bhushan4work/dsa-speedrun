//statement- happy prefix: a non-empty prefix which is also a suffix (excluding itself). return longest happy prefix of given str s. Return "" if not found
 

//(optimal) -kmp algo t.c- O(n)  s.c- O(n)
string longestPrefix(string s) {   // Finds longest proper prefix of string that is also a suffix using KMP LPS array.
    int n = s.size();
    vector<int> lps(n, 0);  // LPS array stores longest prefix-suffix length for every substring ending at each index.
    int length = 0;  // This stores length of current prefix that is matching with a suffix.
    int index = 1;  // first character cannot have a proper prefix, so checking starts from index 1.

    while (index < n) {
        if (s[index] == s[length]) {  // If both characters match, current prefix-suffix match becomes longer by one.
            length++;
            lps[index] = length;
            index++;
        }
        else if (length > 0) {  // If there is a mismatch after some matches, try next best smaller prefix length.
            length = lps[length - 1];
        }
        else {   // If no prefix is currently matching, this index cannot extend any happy prefix.
            lps[index] = 0;
            index++;
        }
    }
    return s.substr(0, lps[n - 1]);  // last LPS value gives ans length for whole string.
}