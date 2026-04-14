//statement- given 2 strings s,t. find the min substring of s such that t is subsequence of s. If it doesnt exists return ""
//subsequence: a sequence that can be derived from another sequence by removing zero or more elements, without changing the order


//(brute) t.c- O(n^2)  s.c- O(1) 
string minWindow(string s, string t){
    int n = s.size();
    int m = t.size();
    
    int minLen = INT_MAX;
    int startInd = -1;
    
    for (int i = 0; i < n; i++) {
        int k = 0; // pointer for t
        
        for (int j = i; j < n; j++) {
            if (s[j] == t[k]) {
                k++; // matched one char of t
            }
            
            if (k == m) { // matched full t as subsequence
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startInd = i;
                }
                break; // smallest window for this i
            }
        }
    }
    
    if (startInd == -1) return "";
    return s.substr(startInd, minLen);
}


//(optimal) t.c- O(n)  s.c- O(1)
string minWindow(string s, string t){
    int n = s.size(), m = t.size();
    int bestStart = -1, bestLen = INT_MAX;
    int i = 0;

    while (i < n) {
        // Forward pass: match t left to right
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) j++;
            i++;
        }
        if (j < m) break; // t not found

        int end = i - 1;

        // Backward pass: shrink from end
        int k = end;
        j = m - 1;
        while (k >= 0 && j >= 0) {
            if (s[k] == t[j]) j--;
            k--;
        }
        int start = k + 1;

        if (end - start + 1 < bestLen) {
            bestLen = end - start + 1;
            bestStart = start;
        }

        // Restart just after tightest start
        i = start + 1;
    }
    if(bestStart == -1) return "";
    return s.substr(bestStart, bestLen);
}