// statement- Given 2 sorted arr, return median of 2 sorted arr. median is defined as middle value. If length of list is even, median is avg of 2 middle elements


// (brute) t.c- O( (n + m + log(n + m))  s.c- O(n + m)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { // Finds median after putting both arrays into one combined sorted order.
    vector<int> merged; // This stores all values from both arrays in one place.
    for (int value : nums1) {
        merged.push_back(value);
    }

    for (int value : nums2) {
        merged.push_back(value);
    }

    sort(merged.begin(), merged.end()); // Sorting creates final order needed for median calculation.

    int total = merged.size(); // This is total number of values after both arrays are combined.
    if (total % 2 == 1) { // If total is odd, there is one exact middle element.
        return merged[total / 2];
    }
    else { // If total is even, median is average of two middle elements.
        return ((double)merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
}



// (better) t.c- O( (n + m / 2)  s.c- O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { // Finds median by simulating merge process only until middle position is reached.
    int n = nums1.size();
    int m = nums2.size();
    int i = 0; // These pointers track next unused value in each array.
    int j = 0;
    int previous = 0; // previous and current store last two picked values.
    int current = 0;
    int middle = (n + m) / 2; // Only positions up to middle can affect median.

    for (int count = 0; count <= middle; count++) {
        previous = current;
        if (i < n && j < m) { // If both arrays still have values, choose smaller one.
            if (nums1[i] <= nums2[j]) { // nums1 is chosen when it has smaller current value.
                current = nums1[i];
                i++;
            }
            else { // nums2 is chosen because its current value is smaller.
                current = nums2[j];
                j++;
            }
        }
        else if (i < n) { // nums2 is finished, so next value must come from nums1.
            current = nums1[i];
            i++;
        }
        else { // nums1 is finished, so next value must come from nums2.
            current = nums2[j];
            j++;
        }
    }

    if ((n + m) % 2 == 1) { // If total is odd, current is exact middle value.
        return current;
    }
    else { // If total is even, previous and current are two middles.
        return ((double)previous + current) / 2.0;
    }
}



// (optimal) t.c- O( (log(min(n,m)))  s.c- O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) { // Binary search should run on smaller array.
        return findMedianSortedArrays(nums2, nums1);
    }

    int n = nums1.size();
    int m = nums2.size();
    int leftSize = (n + m + 1) / 2; // This is how many elements must stay in left half.
    int low = 0;
    int high = n;

    while (low <= high) {
        int cut1 = low + (high - low) / 2; // cut1 means how many elements are taken from nums1.
        int cut2 = leftSize - cut1; // cut2 fills remaining left-half positions from nums2.
        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1]; // If cut1 is at start, nums1 has no left value.
        int right1 = (cut1 == n) ? INT_MAX : nums1[cut1]; // If cut1 is at end, nums1 has no right value.
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1]; // If cut2 is at start, nums2 has no left value.
        int right2 = (cut2 == m) ? INT_MAX : nums2[cut2]; // If cut2 is at end, nums2 has no right value.

        if (left1 <= right2 && left2 <= right1) { // This condition means all left values are small enough.
            if ((n + m) % 2 == 1) { // If total length is odd, median is larger value from left side.
                return max(left1, left2);
            }
            else {
                return ((double)max(left1, left2) + min(right1, right2)) / 2.0; // If total length is even, average two values around middle cut.
            }
        }
        else if (left1 > right2) { // Too many elements were taken from nums1, so move its cut toward left.
            high = cut1 - 1;
        }
        else { // Too few elements were taken from nums1, so move its cut toward right.
            low = cut1 + 1;
        }
    }

    return 0.0;
}