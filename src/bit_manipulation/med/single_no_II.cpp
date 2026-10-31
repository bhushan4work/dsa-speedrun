// statement- Given an integer arr where every element appears 3 times except for one, which appears exactly once. Find single element & return it. 
//            implement a soln with a linear runtime complexity & use only constant extra space


//(brute) t.c- O(n * logm + m)  s.c- O(m)
int singleNumber(vector<int>& nums) { // Function to find single number using frequency counting
    unordered_map<int, int> frequency;
    for (int num : nums) { // Count occurrences of each number
        frequency[num]++;
    }
    for (auto pair : frequency) { // Find number that appears exactly once
        if (pair.second == 1) {
            return pair.first;
        }
    }
    return -1; // Fallback if no single number exists
}



//(better) -using bit t.c- O(32 * n)  s.c- O(1)
int singleNumber(vector<int>& nums) { // Function to find single number using bit counting approach
    int result = 0;
    for (int i = 0; i < 32; i++) { // Iterate through all 32 bits of an integer
        int cntof1 = 0;
        for (int num : nums) { // Count how many numbers have i-th bit set
            if ((num >> i) & 1) {
                cntof1++;
            }
        }

        if (cntof1 % 3 != 0) { // If cntof1 is not a multiple of 3, unique number has this bit set
            result = result | (1 << i);
        }
    }

    return result;
}



//(optimal) -sorting approach t.c- O(nlogn + n/3)  s.c- O(1)
int singleNumber(vector<int>& nums) { // Function to find single number using sorting approach
    sort(nums.begin(), nums.end()); // Sort array to group identical elements together

    for (int i = 0; i < nums.size() - 1; i += 3) { // Iterate through array in steps of 3
        if (nums[i] != nums[i + 1]) { // If current element does not match next, it is unique one
            return nums[i];
        }
    }
    
    return nums[nums.size() - 1]; // If loop finishes without returning, unique number is last element
}



//(most optimal) -bucket approach t.c- O(n)  s.c- O(1)
int singleNumber(vector<int>& nums) { // Function to find single number using optimal bitwise buckets
    int ones = 0; // Tracks bits that have appeared exactly once
    int twos = 0; // Tracks bits that have appeared exactly twice

    for (int num : nums) { // Iterate through each number in arr
        ones = (ones ^ num) & ~twos; // Add bit to ones if not in twos, or remove if already in ones
        twos = (twos ^ num) & ~ones; // Add bit to twos if it was just removed from ones, or remove if already in twos
    }

    return ones; // unique number that appears exactly once will be left in ones
}