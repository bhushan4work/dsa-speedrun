// statement-  find longest common prefix string amongst arr of strings. If no common prefix, return empty string ""

// (optimal) t.c- O(nlogn + m)  s.c- O(m)
string longestCommonPrefix(vector<string> &str){
    if (str.empty()) return ""; //handling edge case

    sort(str.begin(), str.end());
    
    string first = str[0]; // 1st string in sorted order
    string last = str[str.size() - 1]; // 2nd string in sorted order
    string ans = "";

    int minLength = min(first.size(), last.size()); // Compare upto length of shorter string

    for (int i = 0; i < minLength; i++){ // Compare characters of 1st & last string
        if (first[i] != last[i]) break;  // Stop if characters differ
        ans += first[i]; // Add matching character to ans
    }
    return ans;
}