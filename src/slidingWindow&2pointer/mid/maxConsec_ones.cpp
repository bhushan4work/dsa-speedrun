// statement- Given arr & an integer k, return max no of consecutive 1's in the arr if you can flip at most k 0's
//           - basically we need to find longest subarr with atmost k zeroes

// method1(brute) t.c- O(n^2)  s.c- O(1)
int longestOnes(vector<int> &nums, int k){
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++){
        int cntZeros = 0;
        for (int j = i; j < nums.size(); j++){

            if (nums[j] == 0){ // If current element is zero, increment zero count
                cntZeros++;
            }

            if (cntZeros > k){ // If number of cntZeros exceeds k, break this subarray
                break;
            }
            maxLen = max(maxLen, j - i + 1);  // Update max length if this subarray is valid
        }
    }
    return maxLen;
}

// method2(better) t.c- O(2n)  s.c- O(1)
//here we shrink from left to right if cntZeros exceeds k until we find 1st 0 
int longestOnes(vector<int> &nums, int k){
    int left = 0;
    int cntZeros = 0;
    int maxLen = 0;

    for (int right = 0; right < nums.size(); right++){
        
        if (nums[right] == 0){ // If current element is zero, increment zero counter
            cntZeros++;
        }

        while (cntZeros > k){ // If cntZeros exceeds k, shrink the window from left to right till we get 1st zero 
            if (nums[left] == 0){
                cntZeros--;
            }
            left++; // Move the left pointer forward
        }
        // Update the max length of valid window
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// method3(optimal) t.c- O(n)  s.c- O(1)
//here we move both l & r until we find a window with cntZeros <= k & so the while loop in above aproach is not needed here
int longestOnes(vector<int> &nums, int k){
    int left = 0;
    int cntZeros = 0;
    int maxlen = 0;

    for (int right = 0; right < nums.size(); right++){

        if (nums[right] == 0){ // If current element is 0, increment cntZeros
            cntZeros++;
        }

        if (cntZeros > k){ // If zero count exceeds k, move left pointer and adjust cntZeros
            if (nums[left] == 0){
                cntZeros--;
            }
            left++; // Shrink the window from left
        }
        maxlen = max(maxlen, right - left + 1); // Update the maximum window size
    }
    return maxlen;
}
