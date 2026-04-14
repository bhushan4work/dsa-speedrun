// statement- Return the number of good subarr of nums. good subarr: subarr that contains exactly k distinct integers

// (brute) t.c- O(n^2 * k)  s.c- O(k)
int subarraysWithKDistinct(vector<int> &nums, int k){
    int count = 0;

    for (int i = 0; i < nums.size(); i++){
        unordered_map<int, int> freq;

        for (int j = i; j < nums.size(); j++){
            freq[nums[j]]++; // Increment frequency of current element

            if (freq.size() == k){ // If the map size equals k, incr count
                count++;
            }

            if (freq.size() > k) break; // If size of map exceeds k, break out
        }
    }
    return count;
}


// (optimal) t.c- O(2 * 2n)  s.c- O(k)
//  Helper function to compute number of subarrays with cnt <=k
int atMost(vector<int> &nums, int x){
    // edge case for k = 0 , so k-1 thing will go -ve , thats why we keep this
    if (x < 0) return 0;
    unordered_map<int, int> mpp;
    int l = 0, r = 0;
    int cnt = 0;
    while (r < nums.size()){
        mpp[nums[r]]++;

        while (mpp.size() > x){ // Shrink the window from the left if mpp.size() exceeds k
            mpp[nums[l]]--; 
            if (mpp[nums[l]] == 0){ //remove element completely from map if its freq turns 0
                mpp.erase(nums[l]);
            }
            l++; // move forward from left until  mpp.size() <= x
        }

        // we cnt the length here which gives all possible subarr for curr iteration
        cnt += (r - l + 1); // adds the number of valid subarr
        r++;                // move right
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int> &nums, int k){
    // Return difference between subarrays with sum  <=goal & <=(goal - 1)
    return atMost(nums, k) - atMost(nums, k - 1);
}
