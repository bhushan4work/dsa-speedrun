// statement- Given 2 sorted arr. Find kth element of final sorted arr


// (brute) t.c- O( (n + m + log(n + m))  s.c- O(n + m)
int kthElement(vector<int>& a, vector<int>& b, int k) { // Returns kth element after combining both sorted arrays into one sorted order.
    vector<int> merged;
    for (int value : a) {
        merged.push_back(value);
    }

    for (int value : b) {
        merged.push_back(value);
    }

    sort(merged.begin(), merged.end()); // Sorting gives exact final order that problem is asking about.

    return merged[k - 1]; // k is 1-based, so needed index is k - 1.
}



// (better) t.c- O( (k)  s.c- O(1)
int kthElement(vector<int>& a, vector<int>& b, int k) { // Returns kth element by simulating only needed part of merge process.
    int i = 0; // i points to next unused element in first array.
    int j = 0; // j points to next unused element in second array.
    int count = 0; // count tells how many elements have been picked so far.
    int answer = -1; // This stores most recently picked value from merged order.
    
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) { // Pick from a when its current value is smaller or equal, because it comes next.
            answer = a[i];
            i++;
        }
        else {
            answer = b[j]; // Pick from b because its current value is smaller than a[i].
            j++;
        }

        count++;
        if (count == k) { // last picked value is answer as soon as k elements are picked.
            return answer;
        }
    }

    while (i < (int)a.size()) {
        answer = a[i];
        i++;
        count++;
        if (count == k) { // If b is finished, kth value may still be in remaining part of a.
            return answer;
        }
    }

    while (j < (int)b.size()) {
        answer = b[j];
        j++;
        count++;
        if (count == k) { // If a is finished, kth value may still be in remaining part of b.
            return answer;
        }
    }

    return -1;
}



// (optimal) t.c- O( (log(min(n,m)))  s.c- O(1)
int kthElement(vector<int>& a, vector<int>& b, int k) { // Returns kth element by finding a valid partition between two sorted arrays.
    int n = (int)a.size();
    int m = (int)b.size();

    if (k < 1 || k > n + m) { // Invalid k cannot point to any position in combined sorted array.
        return -1;
    }

    if (n > m) { // Search smaller array so binary search stays short and safe.
        return kthElement(b, a, k);
    }

    int low = max(0, k - m); // cutA cannot take less than k - m elements, or cutB would become too large.
    int high = min(k, n); // cutA cannot take more than n elements, or more than k total left elements.

    while (low <= high) {
        int cutA = low + (high - low) / 2; // cutA decides how many elements are taken from first array.
        int cutB = k - cutA; // cutB fills remaining left-side positions so total left count is k.
        int leftA = (cutA == 0) ? INT_MIN : a[cutA - 1]; // If cutA is 0, no value exists on left side of a.
        int rightA = (cutA == n) ? INT_MAX : a[cutA]; // If cutA is n, no value exists on right side of a.
        int leftB = (cutB == 0) ? INT_MIN : b[cutB - 1]; // If cutB is 0, no value exists on left side of b.
        int rightB = (cutB == m) ? INT_MAX : b[cutB]; // If cutB is m, no value exists on right side of b.

        if (leftA <= rightB && leftB <= rightA) { // Both left parts fit before both right parts, so partition is correct.
            return max(leftA, leftB);
        }
        else if (leftA > rightB) { // Too many elements were taken from a, so move cutA to left.
            high = cutA - 1;
        }
        else { // Too few elements were taken from a, so move cutA to right.
            low = cutA + 1;
        }
    }

    return -1;
}
