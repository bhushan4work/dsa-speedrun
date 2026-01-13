// statement- search for target in given sorted arr. No duplicate num exists.

//if search space is till INT_MAX, use 'long long' instead of 'int' to store mid
// t.c- we divide search space into 2 equal halves. After a certain num of divisions, we'll not be able to divide it further. The num of total divisions = t.c

// method1(Iterative) t.c- O(logn) base is 2  s.c- O(1)
int binarySearch(vector &nums, int target){
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;

    while (low <= high){ // Keep searching until low crosses high
        int mid = (low + high) / 2; // Find the middle index
        if (nums[mid] == target)
            return mid; // Target found
        else if (target > nums[mid])
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }
    return -1; // Target not found
}

// method2(Recursive) t.c- O(logn) base is 2   s.c- O(1)
int binarySearch(vector &nums, int low, int high, int target){
    if (low > high)
        return -1; // Base case: target not found

    // Find middle index
    int mid = (low + high) / 2;

    // If target is found at mid
    if (nums[mid] == target)
        return mid;
    // If target is greater, search right half
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    // Otherwise, search left half
    return binarySearch(nums, low, mid - 1, target);
}

// Public function to initiate search
int search(vector &nums, int target){
    return binarySearch(nums, 0, nums.size() - 1, target);
}