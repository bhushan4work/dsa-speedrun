// statement- return kth largest element in given arr

//(brute) t.c- O(nlogk)  s.c- O(k)
int kthLargest(vector<int> &nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap: smallest element stays at top

    for (int x : nums){
        pq.push(x); // insert curr element
        if (pq.size() > k){// Keep only k largest elements in heap
            pq.pop(); // remove smallest among them
        }
    }
    return pq.top(); // Top of heap = k-th largest element
}


//(optimal) -using quickselect(hoare's partition) t.c- O(n^2) in worstcase  s.c- O(1)
int findKthLargest(vector<int> &nums, int k){
    int n = nums.size();

    int targetIdx = n - k; // Convert kth largest → (n - k)th smallest (0-based index)

    return quickSelect(nums, 0, n - 1, targetIdx); // Run Quickselect on full array
}

int quickSelect(vector<int> &nums, int left, int right, int targetIdx){
    if (left == right){ // Base case: only one element left
        return nums[left];
    }

    int pivot = nums[left]; // Choose pivot (here: first element of current segment)

    // Two pointers for Hoare-style partitioning
    int low = left;
    int high = right;

    // Partition loop
    while (low <= high){
        while (low <= high && nums[low] < pivot){ // Move 'low' forward until element >= pivot
            low++;
        }

        while (low <= high && nums[high] > pivot){ // Move 'high' backward until element <= pivot
            high--;
        }

        if (low <= high){ // Swap elements that are on wrong sides
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }

    // Decide which partition contains the target index
    if (targetIdx <= high){
        return quickSelect(nums, left, high, targetIdx); // Target lies in left partition
    }
    else if (targetIdx >= low){
        return quickSelect(nums, low, right, targetIdx); // Target lies in right partition
    }
    else{
        return nums[targetIdx]; // Target lies between high & low. This region corresponds to elements = pivot. So nums[targetIdx] is already correct
    }
}





// statement- return kth smallest element in given arr

//(brute) t.c- O(nlogk)  s.c- O(k)
int kthSmallest(vector<int> &arr, int k){
    priority_queue<int> pq; // max heap (largest element on top)

    for (int x : arr){
        pq.push(x); // insert element

        if (pq.size() > k){// maintain size k
            pq.pop(); // remove largest
        }
    }
    return pq.top(); // top = kth smallest
}


//(optimal) -using quickselect(hoare's partition) t.c- O(n^2) in worstcase  s.c- O(1)
int findKthSmallest(vector<int> &nums, int k){
    int targetIdx = k - 1; // kth smallest → index k-1
    return quickSelect(nums, 0, nums.size() - 1, targetIdx);
}

int quickSelect(vector<int> &nums, int left, int right, int targetIdx){
    if (left == right){
        return nums[left];
    }

    int pivot = nums[left];     // Choose pivot (here: first element)

    int low = left;
    int high = right;

    // Partition process (Hoare-style)
    while (low <= high){
        while (low <= high && nums[low] < pivot){ // Move low forward until element >= pivot
            low++;
        }

        while (low <= high && nums[high] > pivot){ // Move high backward until element <= pivot
            high--;
        }

        if (low <= high){ // Swap misplaced elements
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }

    // Decide which side to recurse into
    if (targetIdx <= high){
        return quickSelect(nums, left, high, targetIdx); // kth smallest is in left partition
    }
    else if (targetIdx >= low){
        return quickSelect(nums, low, right, targetIdx); // kth smallest is in right partition
    }
    else{
        return nums[targetIdx]; // target index lies between high and low → pivot region
    }
}