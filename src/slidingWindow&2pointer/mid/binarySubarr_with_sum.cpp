// statement- given a binary arr & an integer goal. Return no of subarr whose sum is == goal

// (brute) t.c- O(n^2)  s.c- O(1)
int numSubarraysWithSum(vector<int> &nums, int goal){
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        int sum = 0; // sum resets to 0 on every new iteration of i

        for (int j = i; j < nums.size(); j++){
            sum += nums[j]; // Add the current element to sum

            if (sum == goal){ // If subarray sum equals goal, increment count
                count++;
            }
        }
    }
    return count;
}


// (better) t.c- O(n)  s.c- O(n)
int numSubarraysWithSum(vector<int> &nums, int goal){
    unordered_map<int, int> prefixSumCount; // Hashmap to store prefix sum frequencies
    int count = 0, sum = 0;
    prefixSumCount[0] = 1; // Add base case: prefix sum 0 has frequency 1

    for (int i=0;i<nums.size();i++){
        sum += nums[i]; // Add current element to prefix sum

        if (prefixSumCount.find(sum - goal) != prefixSumCount.end()){ // If (sum - goal) exists in map, add its freq to count
            count += prefixSumCount[sum - goal];
        }

        prefixSumCount[sum]++; // Increment freq of current prefix sum
    }
    return count;
}


// (optimal) t.c- O(2 * 2n)  s.c- O(1)
int numSubarraysWithSum(vector<int> &nums, int goal){
    // Return difference between subarrays with sum  <=goal & <=(goal - 1)
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

// Helper function to compute number of subarrays with sum <=k
int atMost(vector<int> &nums, int k){
    // edge case for goal = 0 , so goal-1 thing will go -ve , thats why we keep this
    if (k < 0) return 0;

    int l = 0, r = 0;
    int sum = 0;
    int cnt = 0;
    while (r < nums.size()){
        sum += nums[r]; // Add current element to sum

        while (sum > k){ // Shrink the window from the left if sum exceeds k
            sum -= nums[l]; // keep on removing elements & move forward from left until sum <= k
            l++;
        }

        // else when sum <= k do thiss :
        //we cnt the length here which gives all possible subarr for current iteration
        cnt += (r - l + 1); // Add the number of valid subarrays
        r++;                // move right
    }
    return cnt;
}