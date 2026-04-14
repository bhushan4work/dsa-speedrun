//statement- Given a str s, return longest palindromic substring in s
//for most optimal: t.c- O(n)  s.c- O(n) - Manacher’s Algorithm is used 


//(brute) t.c- O(n^3)  s.c- O(1)
bool isPalindrome(const string &s, int l, int r) { //helper fxn to return if curr substr is pal 
    while (l < r) {
        if (s[l] != s[r]) return false; //pal not found
        l++; //else move l forward 
        r--; //move r inward
    }
    return true;
}
string longestPalindromeBrute(string s) { //main fxn to get longest pal
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                int len = j - i + 1; //finds len of curr pal substr
                if (len > ans.size()) { 
                    ans = s.substr(i, len); //updates max pal substr
                }
            }
        }
    }
    return ans;
}



//(optimal) t.c- O(n^2)  s.c- O(1) - expand around approach
string longestPalindrome(string s) {
    if (s.size() == 0) return "";  //edge case handling
    int start = 0;   // starting index of best palindrome
    int maxLen = 1;  // length of best palindrome

    for (int i = 0; i < s.size(); i++) {
        // Odd length palindrome (center at i)
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) { //finds curr pal substr 
            int len = r - l + 1; //calculates curr length of pal substr founded
            if (len > maxLen) { 
                maxLen = len; //update maxLen
                start = l; //update new starting index to l
            }
            l--; 
            r++;
        }

        //Even length palindrome (center betn i and i+1)
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {//finds curr pal substr 
            int len = r - l + 1;  //calculates curr length of pal substr founded
            if (len > maxLen) {
                maxLen = len; //update maxLen
                start = l; //update new starting index to l
            }
            l--;
            r++;
        }
    }
    return s.substr(start, maxLen);
}