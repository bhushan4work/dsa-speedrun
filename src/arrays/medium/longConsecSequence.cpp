// statement- given an arr, return length of longest sequence of consecutive integers. if any duplicates exist count it only once

// method1(brute) t.c- O(n^2) s.c- O(1)
bool linearSearch(vector<int> &a, int num){
    int n = a.size();
    for (int i = 0; i < n; i++){
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestConsecutive(vector<int> &nums){
    int n = nums.size();
    int longest = 1;
    for (int i = 0; i < n; i++){
        int x = nums[i];
        int cnt = 1;
        while (linearSearch(nums, x + 1)){   // check consecutive numbers
            x = x + 1; 
            cnt++;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// method2(better) t.c- O(nlogn + n) s.c- O(1)
int longestConsecutive(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN; // Track last smaller element
    int cnt = 0;               // Count current sequence length
    int longest = 1;           // Track longest sequence length

    for (int i = 0; i < n; i++){
        if (nums[i] - 1 == lastSmaller){    // If consecutive number exists
            cnt += 1;     // Increment sequence count
            lastSmaller = nums[i];   // Update last smaller element
        }
        else if (nums[i] != lastSmaller){ // If consecutive number doesn't exits
            cnt = 1; // Reset count for new sequence
            lastSmaller = nums[i]; // Update last smaller element
        }
        longest = max(longest, cnt); // Update longest if needed
    }
    return longest;
}

// method3(optimal) t.c- O(n) s.c- O(n)
int longestConsecutive(vector<int> &a){
    int n = a.size();
    int longest = 1; 
    unordered_set<int> st;
    for (int i = 0; i < n; i++){ // Put all the array elements into the set
        st.insert(a[i]);
    }
    for (auto it : st){
        if (st.find(it - 1) == st.end()){  // Check if 'it' is a starting number of a sequence
            int cnt = 1;
            int x = it;   // Starting element of the sequence

            while (st.find(x + 1) != st.end()){  // Find consecutive numbers in the set
                x = x + 1;  // Move to the next element in the sequence
                cnt = cnt + 1;   // Increment the count of the sequence
            }
            longest = max(longest, cnt);  // Update the longest sequence length
        }
    }
    return longest;
}
