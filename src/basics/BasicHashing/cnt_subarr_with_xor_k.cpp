//statement- Given an arr, an integer k, return total no of subarr whose XOR equals to k


// (brute) t.c- O(n^3)  s.c- O(1)
long long countSubarraysWithXor(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    long long count = 0;
    for (int start = 0; start < n; start++) { // Generate every possible subarr using its start and end indices.
        for (int end = start; end < n; end++) {

            int currentXor = 0;
            for (int index = start; index <= end; index++) { // Calculate XOR of selected range.
                currentXor ^= nums[index];
            }

            if (currentXor == k) { // This range is valid when its XOR equals k.
                count++;
            }
        }
    }

    return count;
}



// (better) t.c- O(n^2)  s.c- O(1)
long long countSubarraysWithXor(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    long long count = 0;
    for (int start = 0; start < n; start++) {
        int currentXor = 0;

        for (int end = start; end < n; end++) { // Extend current range one element at a time and reuse its previous XOR.
            currentXor ^= nums[end];

            if (currentXor == k) { // Count every subarray whose XOR equals k.
                count++;
            }
        }
    }

    return count;
}



// (optimal) t.c- O(n)  s.c- O(n)
long long countSubarraysWithXor(vector<int>& nums, int k) {
    unordered_map<int, long long> prefixCount;
    prefixCount[0] = 1; // empty prefix allows subarrays starting from index 0 to be counted.
    int prefixXor = 0;
    long long count = 0;

    for (int value : nums) {
        prefixXor ^= value;
        int neededXor = prefixXor ^ k;

        if (prefixCount.find(neededXor) != prefixCount.end()) { // Every earlier occurrence of neededXor creates a valid subarray ending here.
            count += prefixCount[neededXor];
        }

        prefixCount[prefixXor]++; // Store current prefix only after checking earlier prefix XORs.
    }

    return count;
}