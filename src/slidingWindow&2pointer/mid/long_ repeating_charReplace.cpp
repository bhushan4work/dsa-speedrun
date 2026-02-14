// statement- any char in str can be selected & changed to any other uppercase char. This can be performed up to k times. return length of longest substr that contains same letter
// here we need to replace k char's in given str with any other char to get maxLen. so we'll only change char's having lesser freq in the str

// method1(brute) t.c- O(n^2 * 26)  s.c- O(26)
int characterReplacement(string s, int k){
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++){
        vector<int> freq(26, 0); // tracks freq of char in the str
        int maxFreq = 0;         // Track char having max freq in current substr

        for (int j = i; j < s.length(); j++){
            freq[s[j] - 'A']++; // Update freq of current char

            maxFreq = max(maxFreq, freq[s[j] - 'A']); // Update the most frequent char seen so far

            int windowLen = r - l + 1; // calculate window length

            // this is the space of char's amongst which we'll replace k places
            int replace = windowLen - maxFreq;

            // If number of replacements is within allowed k, update answer
            if (replace <= k){
                maxLength = max(maxLength, windowLen);
            }
        }
    }
    return maxLength;
}

// method2(better) t.c- O(n + n + 26)  s.c- O(26)
int characterReplacement(string s, int k){
    unordered_map<char, int> freq; // Map to count frequency of characters in current window
    int l = 0, r = 0;
    int maxFreq = 0; // Tracks the count of the most frequent character in the window
    int maxLen = 0;  // Stores maxLen

    while (r < s.size()){
        freq[s[r]]++; // Increase frequency of the current character

        maxFreq = max(maxFreq, freq[s[r]]); // Update max frequency seen so far in the window

        int windowLen = r - l + 1; // calculate window length

        // this tracks current space of char's amongst which we'll replace k places
        int replace = windowLen - maxFreq;

        while (replace > k){ // If window is invalid (needs more than k replacements)
            freq[s[l]]--; // Decrease frequency of the character at left
            l++;          // move left pointer to the right side

            windowLen = r - l + 1;         // Update window length
            replace = windowLen - maxFreq; // Recompute replacements needed
        }

        // else when replace <= k, update len & move right
        maxLen = max(maxLen, windowLen); // Update max_len with current valid window size
        r++;
    }
    return maxLen;
}

// method3(optimal) t.c- O(n + 26)  s.c- O(26)
int characterReplacement(string s, int k){
    unordered_map<char, int> freq; // Map to count frequency of characters in current window
    int l = 0, r = 0;
    int maxFreq = 0; // Tracks the count of the most frequent character in the window
    int maxLen = 0;  // Stores maxLen

    while (r < s.size()){
        freq[s[r]]++; // Increase frequency of the current character

        maxFreq = max(maxFreq, freq[s[r]]); // Update max frequency seen so far in the window

        int windowLen = r - l + 1; // calculate window length

        // this tracks current space of char's amongst which we'll replace k places
        int replace = windowLen - maxFreq;

        if (replace > k){ // If window is invalid (needs more than k replacements)
            freq[s[l]]--; // Decrease frequency of the character at left
            l++;          // move left pointer to the right side

            //these 2 updations not needed as we using 'if' instead of 'while'
            windowLen = r - l + 1;         // Update window length
            replace = windowLen - maxFreq; // Recompute replacements needed
        }

        // else when replace <= k, update len & move right
        maxLen = max(maxLen, windowLen); // Update max_len with current valid window size
        r++;
    }
    return maxLen;
}