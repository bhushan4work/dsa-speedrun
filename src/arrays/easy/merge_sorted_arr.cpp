//statement- Given 2 integer arr. Both arr are sorted in non-decreasing order. merge both arr sorted in non-decreasing order. final sorted arr should be stored inside
//           arr nums1 & should be done in-place. nums1 has length of m + n, where first m elements denote elements of nums1 & rest are 0s. nums2 has a length of n


// (brute) t.c- O(2 * (n + m))  s.c- O(n + m)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> arr3(m + n);
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < m && right < n) {
        if (nums1[left] <= nums2[right]) {
            arr3[index] = nums1[left];
            left++, index++;
        }
        else {
            arr3[index] = nums2[right];
            right++, index++;
        }
    }

    while (left < m) {
        arr3[index++] = nums1[left++];
    }

    while (right < n) {
        arr3[index++] = nums2[right++];
    }

    for (int i = 0; i < m + n; i++) {
        nums1[i] = arr3[i]; // Copying back to nums1 as required by LeetCode 88
    }
}



// (optimal1) t.c- O(min(n,m) + nlogn + mlogm)  s.c- O(1)
void merge(long long arr1[], long long arr2[], int n, int m) {
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}



// (optimal2) -using gap method(shell sort) t.c- O(log(n + m) + (n + m))  s.c- O(1)
void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) { // Swap if first element is strictly greater.
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m + n; // Total length of both arrays combined.
    int gap = (len / 2) + (len % 2); // Calculate initial gap using ceiling division.
    
    while (gap > 0) { // Continue until gap reduces to 0.
        int left = 0;
        int right = left + gap; // Right pointer is ahead by current gap.
        
        while (right < len) {
            if (left < m && right >= m) { // Left pointer in nums1, right pointer in nums2.
                swapIfGreater(nums1, nums2, left, right - m);
            }
            else if (left >= m) { // Both left and right pointers are in nums2.
                swapIfGreater(nums2, nums2, left - m, right - m);
            }
            else { // Both left and right pointers are in nums1.
                swapIfGreater(nums1, nums1, left, right);
            }

            left++, right++; // Move both pointers forward.
        }
        
        if (gap == 1) { // Stop if gap was 1 to prevent an infinite loop.
            break;
        }

        gap = (gap / 2) + (gap % 2); // Reduce gap for next iteration.
    }
    
    for (int i = 0; i < n; i++) { // Append sorted nums2 elements to end of nums1.
        nums1[m + i] = nums2[i];
    }
}