// statement- search for the index of the target value 'x' in the arr

//(optimal) t.c- O(logn)  s.c- O(1)   -lowerBound algo is applied here
int searchInsert(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n; // Default set to n (if t not found)

    while (low <= high){  // Binary search loop
        int mid = (low + high) / 2; // gives Middle index

        if (nums[mid] >= target){
            ans = mid;      // Stores possible answer
            high = mid - 1; // Try to find smaller index on left side
        }
        else{
            low = mid + 1; // Move right if current element is less than t
        }
    }
    return ans; // Return the index of the lower bound
}
