// statement- find 'kth' positive integer missing from arr

// method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int missingK(vector<int> vec, int n, int k){
    for (int i = 0; i < n; i++){
        if (vec[i] <= k){
            k++; // If current num is <= k, increment k
        }
        else{
            break; // else stop when we reach a num > k
        }
    }
    return k; // Return final val of k which is the missing num
}

// method2(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int missingK(vector<int> vec, int n, int k){
    int low = 0, high = n - 1;

    while (low <= high){
        int mid = low + ((high - low) / 2);

        // Calculate how many numbers are missing till vec[mid]
        int missing = arr[mid] - (mid + 1);

        if (missing < k){
            low = mid + 1; // Move right to find more missing numbers
        }
        else{
            high = mid - 1; // Move left to find a smaller valid index
        }
    }
    // After loop, 'high' points to the largest index such that
    // number of missing elements till there < k
    return k + high + 1;
}