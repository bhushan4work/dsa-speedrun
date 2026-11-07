//statement- Given an integer arr. return product of elements present in that subarr. subarr is a contiguous non-empty seq of elements within an arr


// (brute) t.c- O(n^3)  s.c- O(1)
long long maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) { // No non-empty subarray exists.
        return 0;
    }

    long long maxProduct = nums[0];
    for (int start = 0; start < n; start++) { // Generate every possible subarray using its start and end indices.
        for (int end = start; end < n; end++) {
            long long currentProduct = 1;
            for (int index = start; index <= end; index++) { // Calculate product of selected range.
                currentProduct *= nums[index];
            }

            if (currentProduct > maxProduct) { // Keep largest product found so far.
                maxProduct = currentProduct;
            }
        }
    }

    return maxProduct;
}



// (better) t.c- O(n^2)  s.c- O(1)
long long maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) { // No non-empty subarray exists.
        return 0;
    }

    long long maxProduct = nums[0];
    for (int start = 0; start < n; start++) {
        long long currentProduct = 1;
        for (int end = start; end < n; end++) { // Extend current subarray one element at a time and reuse its previous product.
            currentProduct *= nums[end];

            if (currentProduct > maxProduct) { // Keep best product among all ranges seen so far.
                maxProduct = currentProduct;
            }
        }
    }

    return maxProduct;
}



// (optimal) t.c- O(n)  s.c- O(1)
long long maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) { // No non-empty subarray exists.
        return 0;
    }

    long long currentMax = nums[0];
    long long currentMin = nums[0];
    long long maxProduct = nums[0];

    for (int index = 1; index < n; index++) {
        long long currentValue = nums[index];
        long long previousMax = currentMax; // Preserve both previous states because a negative value can swap their roles.
        long long previousMin = currentMin;

        currentMax = max({currentValue, previousMax * currentValue, previousMin * currentValue}); // Either start fresh or extend one of previous product subarrays.
        currentMin = min({currentValue, previousMax * currentValue, previousMin * currentValue});

        if (currentMax > maxProduct) { // Record best product found anywhere so far.
            maxProduct = currentMax;
        }
    }

    return maxProduct;
}