//statement- given arr containing +ve, -ve integer. find length of longest contiguous subarr with sum = 0. Return length if it exists else 0


// (brute) t.c- O(n^3)  s.c- O(1)
int maxLen(vector<int>& arr) {
    int n = arr.size(); // Get total number of elements in array.
    int max_length = 0; // Variable to keep track of max length found.

    for (int i = 0; i < n; i++) { // Outer loop to fix starting index of subarray.

        for (int j = i; j < n; j++) { // Inner loop to fix ending index of subarray.
            int current_sum = 0; // Initialize sum for current subarray to 0.

            for (int k = i; k <= j; k++) { // Loop through current subarray to calculate its sum.
                current_sum += arr[k]; // Add each element to current sum.
            }

            if (current_sum == 0) { // Check if calculated sum of subarray is exactly zero.
                max_length = max(max_length, j - i + 1); // Update max_length if current valid subarray is longer.
            }
        }
    }

    return max_length; // Return length of longest subarray with a zero sum.
}



// (better) t.c- O(n^2)  s.c- O(1)
int maxLen(vector<int>& arr) {
    int n = arr.size(); // Get total number of elements in array.
    int max_length = 0; // Variable to track max length found so far.

    for (int i = 0; i < n; i++) { // Outer loop to fix starting index of subarray.
        int current_sum = 0; // Initialize sum for subarray starting at index i.

        for (int j = i; j < n; j++) { // Inner loop to expand subarray ending at index j.
            current_sum += arr[j]; // Add current element to running sum.

            if (current_sum == 0) { // Check if subarray from i to j has a sum of exactly zero.
                max_length = max(max_length, j - i + 1); // Update max_length if this valid subarray is longer.
            }
        }
    }

    return max_length; // Return max length found.
}



// (optimal) t.c- O(n)  s.c- O(n)
int maxLen(int A[], int n) {
    unordered_map<int, int> mpp; // Map to store prefix sums and their earliest occurrences.
    int maxi = 0; // Track max length of zero-sum subarray.
    int sum = 0; // Running prefix sum.

    for (int i = 0; i < n; i++) { // Iterate through array.
        sum += A[i]; // Add current element to prefix sum.

        if (sum == 0) { // If sum from start is zero, update max length.
            maxi = i + 1;
        }
        else {
            if (mpp.find(sum) != mpp.end()) { // If sum is seen before, zero-sum subarray exists between indices.
                maxi = max(maxi, i - mpp[sum]); // Update max length comparing with current subarray length.
            }
            else {
                mpp[sum] = i; // Store first occurrence of this prefix sum to maximize length later.
            }
        }
    }

    return maxi; // Return final max length.
}