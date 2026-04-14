//statement- Find length of longest substring without repeating char's

//(brute) t.c- O(n^2)  s.c- O(1) 
int longestNonRepeatingSubstring(string &s) {
    int n = s.size(); 
    int maxLen = 0; //stores maxLen 
        
    for (int i = 0; i < n; i++) {
        vector<int> hash(256, 0);  
        for (int j = i; j < n; j++) {
            if (hash[s[j]] == 1) break;  // If s[j] is already in the current substring window
                  
            hash[s[j]] = 1;     // Update the hash to mark s[j] as 'present' in current window

            int len = j - i + 1;  // Calculate length of current substring
            maxLen = max(maxLen, len); // Update maxLen
        }
    }
    return maxLen; 
}

//(optimal) t.c- O(n)  s.c- O(1)  
int longestNonRepeatingSubstring(string& s) {
    int n = s.size();
    int HashLen = 256; 
    int hash[HashLen];  /* Hash table to store last occurrence of each character*/
    
    for (int i = 0; i < HashLen; ++i) { 
        hash[i] = -1;     /* Initialize hash table with -1 (indicating no occurrence)*/
    }

    int l = 0, r = 0, maxLen = 0;
    while (r < n) {
        if (hash[s[r]] != -1) { /* If current character s[r] is already in the substring*/
            l = max(hash[s[r]] + 1, l); /* Move left pointer to the right of the last occurrence of s[r]*/
        }
            
        int len = r - l + 1; // Calculate the current substring length
        maxLen = max(len, maxLen); // Update maximum length found so far
            
        hash[s[r]] = r; /* Store the index of the current character in the hash table*/
        
        r++; // Move right pointer to next position
    }
    return maxLen;
}