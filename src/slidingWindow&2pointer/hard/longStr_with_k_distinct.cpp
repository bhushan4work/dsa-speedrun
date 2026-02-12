//statement- Find the length of the longest substring with at most k distinct characters


//method1(brute) t.c- O(n^2 * log256)  s.c- O(256) 
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
        unordered_map<char, int> mpp; //we placed this map here instead of above outer loop so it resets for every new index i

        for (int j = i; j < s.size(); j++) {
            mpp[s[j]]++; //Add the current char to map & incr its cnt

            if (mpp.size() > k) break;  // If no of distinct char's exceeds k, break

            maxLen = max(maxLen, j - i + 1); //calculate current window size & update maxLen 
        }
    }
    return maxLen;
}

//method2(better) t.c- O(n + n + log256)  s.c- O(256) 
int totalFruit(vector<int> &arr){
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<char, int> mpp;
    
    while (r < arr.size()){
        mpp[arr[r]]++; //Add the current char to map & incr its cnt
        
        if (mpp.size() > k){
            while (mpp.size() > k){ //we keep on shrinking 'l' pointer to the right until we get mpp.size <= 2
                mpp[arr[l]]--; //Remove one char from the left side
                if (mpp[arr[l]] == 0){ //If certain char cnt becomes 0, remove it completely from map
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        
        if (mpp.size() <= k){
            maxLen = max(maxLen, r - l + 1);  //calculate current window size & update maxLen 
        }
        r++;
    }
    return maxLen;
}

//method3(optimal) t.c- O(n + log256)  s.c- O(256) 
int totalFruit(vector<int> &arr){
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<int, int> mpp;
    while (r < arr.size()){
        mpp[arr[r]]++; //Add the current char to map & incr its cnt

        if (mpp.size() > k){
            mpp[arr[l]]--; //Remove one char from the left side
            if (mpp[arr[l]] == 0){ //If certain char cnt becomes 0, remove it completely from map
                mpp.erase(arr[l]);
            }
            l++; 
        }

        if (mpp.size() <= k){
            maxLen = max(maxLen, r - l + 1); //calculate current window size & update maxLen 
        }
        r++;
    }
    return maxLen;
}
