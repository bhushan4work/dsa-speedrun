//statement- Given an integer arr. Return no of inversions in arr. 2 elements a[i] & a[j] form an inversion if a[i] > a[j] & i < j.
//           it indicates how close an arr is to being sorted. sorted arr has an inversion count of 0. arr sorted in descending order has max inversion


// (brute) t.c- O(n^2)  s.c- O(1)
long long countInversions(vector<int>& arr) { // Returns total number of inversions.
    int n = arr.size();
    long long inversions = 0;

    for (int left = 0; left < n; left++) { // Choose each position as left side of a pair.
        for (int right = left + 1; right < n; right++) { // Check only positions that appear after left index.
            if (arr[left] > arr[right]) { // A pair is an inversion only when left value is greater.
                inversions++;
            }
        }
    }

    return inversions;
}



// (optimal) -using mergesort approach t.c- O(nlogn)  s.c- O(n)
long long mergeAndCount(vector<int>& nums, int left, int mid, int right) { // Merges two sorted ranges & returns their cross inversions.
    vector<int> merged;
    int first = left;
    int second = mid + 1;
    long long inversions = 0;

    while (first <= mid && second <= right) { // Combine both sorted halves & count cross inversions.
        if (nums[first] <= nums[second]) { // Choose left value when it is not greater; otherwise right value creates cross inversions.
            merged.push_back(nums[first]);
            first++;
        }
        else {
            inversions += mid - first + 1;
            merged.push_back(nums[second]);
            second++;
        }
    }

    while (first <= mid) { // Copy any values still remaining in left half.
        merged.push_back(nums[first]);
        first++;
    }

    while (second <= right) { // Copy any values still remaining in right half.
        merged.push_back(nums[second]);
        second++;
    }

    int mergedSize = merged.size();
    for (int index = 0; index < mergedSize; index++) { // Move sorted values back into active range.
        nums[left + index] = merged[index];
    }

    return inversions;
}

long long mergeSort(vector<int>& nums, int left, int right) { // Counts inversions while sorting current range.
    if (left >= right) { // A range with zero or one value has no inversion.
        return 0;
    }

    int mid = left + (right - left) / 2;
    long long inversions = 0;
    inversions += mergeSort(nums, left, mid); // Count inversions inside left half.
    inversions += mergeSort(nums, mid + 1, right); // Count inversions inside right half.
    inversions += mergeAndCount(nums, left, mid, right); // Count inversions formed across two sorted halves.

    return inversions;
}

long long countInversions(vector<int>& arr) { // Returns total number of inversions.
    vector<int> nums = arr;
    if (nums.size() <= 1) { // An empty or single-element array has no inversion.
        return 0;
    }

    int n = nums.size();

    return mergeSort(nums, 0, n - 1);
}