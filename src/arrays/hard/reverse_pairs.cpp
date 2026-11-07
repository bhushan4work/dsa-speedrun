//statement- Given an integer arr. Return no of reverse pairs in arr. index pair (i, j) is called reverse pair if: 0 <= i < j < nums.length, nums[i] > 2 * nums[j]


// (brute) t.c- O(n^2)  s.c- O(1)
int reversePairs(vector<int>& nums) { // Returns the number of reverse pairs.
    int n = nums.size();
    int pairs = 0;

    for (int left = 0; left < n; left++) { // Choose each position as the left side of a possible pair.
        long long leftValue = nums[left];
        for (int right = left + 1; right < n; right++) { // Check only positions that appear after the left index.
            long long doubledRight = 2LL * nums[right];

            if (leftValue > doubledRight) { // A reverse pair needs the left value to be more than twice the right value.
                pairs++;
            }
        }
    }

    return pairs;
}



// (optimal) -using mergesort approach t.c- O(nlogn)  s.c- O(n)
int countCrossPairs(vector<int>& arr, int left, int mid, int right) { // Returns cross pairs from the left half to the right half.
    int pairs = 0;
    int rightPointer = mid + 1;

    for (int leftPointer = left; leftPointer <= mid; leftPointer++) { // Count how many right-half values are valid for each left-half value.
        long long leftValue = arr[leftPointer];

        while (rightPointer <= right && leftValue > 2LL * arr[rightPointer]) { // Move across right-half values that satisfy the reverse-pair condition.
            rightPointer++;
        }

        pairs += rightPointer - (mid + 1);
    }

    return pairs;
}

void mergeSortedHalves(vector<int>& arr, int left, int mid, int right) { // Merges two sorted halves into one sorted range.
    vector<int> merged;
    int first = left;
    int second = mid + 1;

    while (first <= mid && second <= right) { // Merge the smaller available value from the two halves.
        if (arr[first] <= arr[second]) { // The smaller value should be placed next in the merged range.
            merged.push_back(arr[first]);
            first++;
        }
        else {
            merged.push_back(arr[second]);
            second++;
        }
    }

    while (first <= mid) { // Copy any remaining values from the left half.
        merged.push_back(arr[first]);
        first++;
    }

    while (second <= right) { // Copy any remaining values from the right half.
        merged.push_back(arr[second]);
        second++;
    }

    for (int index = 0; index < merged.size(); index++) { // Write the merged values back into the selected range.
        arr[left + index] = merged[index];
    }
}

int mergeSort(vector<int>& arr, int left, int right) { // Counts reverse pairs while sorting the selected range.
    if (left >= right) { // A range with zero or one value cannot contain a pair.
        return 0;
    }

    int mid = left + (right - left) / 2;
    int pairs = 0;

    pairs += mergeSort(arr, left, mid);
    pairs += mergeSort(arr, mid + 1, right);
    pairs += countCrossPairs(arr, left, mid, right);
    mergeSortedHalves(arr, left, mid, right);

    return pairs;
}

int reversePairs(vector<int>& nums) { // Returns the number of reverse pairs.
    vector<int> arr = nums;
    int n = arr.size();

    if (n < 2) { // Arrays with fewer than two values cannot form a pair.
        return 0;
    }

    return mergeSort(arr, 0, n - 1);
}