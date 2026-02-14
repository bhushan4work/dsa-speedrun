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

// method2(better) t.c- O(n + n)  s.c- O(1)
//here we shrink from left to right if cntZeros exceeds k until we find 1st 0 
int longestOnes(vector<int> &nums, int k){
    int l = 0 , r = 0;
    int cntZeros = 0;
    int maxLen = 0;

    while(r < nums.size()){
        if (nums[r] == 0 ){ // If current element is zero, increment zero counter
            cntZeros++;
        }

        while (cntZeros > k){ // If cntZeros exceeds k, shrink the window from left to right till we get 1st zero 
            if (nums[l] == 0){
               cntZeros--; //if u find zero to the left , remove it & decr its counter
            }
            l++; // Move the left pointer forward
        }
        // else when cntZeros <= k, Update max length of valid window & move right
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// method3(optimal) t.c- O(n)  s.c- O(1)
//here we move both l & r by 1 alternatively until we find a window with cntZeros <= k & so the while loop in above aproach is not needed here
int longestOnes(vector<int> &nums, int k){

    int l = 0 , r = 0;
    int cntZeros = 0;
    int maxLen = 0;

    while(r < nums.size()){
        if (nums[r] == 0 ){ // If current element is zero, increment zero counter
            cntZeros++;
        }

        if (cntZeros > k){ // If cntZeros exceeds k, shrink the window from left to right till we get 1st zero 
            if (nums[l] == 0){
               cntZeros--; //if u find zero to the left , remove it & decr its counter
            }
            l++; // Move the left pointer forward
        }
        //else when cntZeros <= k, Update max length of valid window & move right
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
