// statement- arr is called nice if it contains k odd numbers. Find no of nice subarr in given arr
//  this que is same as binarySubarr with sum, here we just change oddNum to 1, evenNum to 0

// (brute) t.c- O(n^2)  s.c- O(1)
int numberOfSubarrays(vector<int> &nums, int k){
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        int sum = 0; // sum resets to 0 on every new iteration of i

        for (int j = i; j < nums.size(); j++){
            sum += nums[j] % 2; // Add the current element to sum

            if (sum == k){ // If subarray sum equals k, increment count
                count++;
            }
        }
    }
    return count;
}


// (better) t.c- O(n)  s.c- O(n)
int numberOfSubarrays(vector<int> &nums, int k){
    unordered_map<int, int> prefixSumCount; // Hashmap to store prefix sum frequencies
    int count = 0, sum = 0;
    prefixSumCount[0] = 1; // Add base case: prefix sum 0 has frequency 1

    for (int i = 0; i < nums.size(); i++){
        sum += nums[i] % 2; // Add current element to prefix sum

        if (prefixSumCount.find(sum - k) != prefixSumCount.end()){ // If (sum - k) exists in map, add its freq to count
            count += prefixSumCount[sum - k];
        }

        prefixSumCount[sum]++; // Increment freq of current prefix sum
    }
    return count;
}


// method3(optimal) t.c- O(2 * 2n)  s.c- O(1)
int numberOfSubarrays(vector<int> &nums, int k){
    // Return difference between subarrays with sum  <=goal & <=(goal - 1)
    return atMost(nums, k) - atMost(nums, k - 1);
}

// Helper function to compute number of subarrays with sum <=k
int atMost(vector<int> &nums, int x){
    // edge case for k = 0 , so k-1 thing will go -ve , thats why we keep this
    if (x < 0) return 0;

    int l = 0, r = 0;
    int sum = 0;
    int cnt = 0;
    while (r < nums.size()){
        sum += nums[r] % 2; // Add current element to sum

        while (sum > x){  // Shrink the window from the left if sum exceeds k
            sum -= nums[l] % 2; // keep on removing elements & move forward from left until sum <= k
            l++;
        }

        // else when sum <= k do thiss :
        // we cnt the length here which gives all possible subarr for current iteration
        cnt += (r - l + 1); // Add the number of valid subarrays
        r++;                // move right
    }
    return cnt;
}