// statement- Given an arr, there is a sliding window of size k which is moving from very left of arr to very right. You can only see k numbers in window.
//            Each time sliding window moves right by one position. Return max sliding window


// (brute) t.c- O(n * k)  s.c- O(1)
vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i <= n - k; i++) { // Loop through each window start position.
        int maxVal = nums[i]; // Initialize max with first element of window.
        for (int j = 1; j < k; j++) { // Traverse rest of window.
            if (nums[i + j] > maxVal) { // Update max if a greater element is found.
                maxVal = nums[i + j];
            }
        }
        result.push_back(maxVal); // Store maximum of current window.
    }
    return result;
}



// (optimal) -using monotonic deque t.c- O(n)  s.c- O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    deque<int> dq; // Store indices, keeping corresponding values strictly decreasing.
    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() == i - k) { // Remove index if it falls outside current window of size k.
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] <= nums[i]) { // Remove indices of smaller elements as they are useless now.
            dq.pop_back();
        }
        dq.push_back(i); // Add current element's index to deque.
        if (i >= k - 1) { // Once first window is fully formed, record max element.
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}