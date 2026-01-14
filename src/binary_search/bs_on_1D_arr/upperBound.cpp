// statement-  write a program to find the upper bound of x
// upperBound- It is smallest index where arr[ind] > x. But if such index is not found, it returns n

// method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int upperBound(vector<int> &arr, int x, int n){
    for (int i = 0; i < n; i++){
        if (arr[i] > x){
            return i; // First element strictly greater than x
        }
    }
    return n; // If no such element exists, return n
}

// method2(optimal) t.c- O(logn) base is 2  s.c- O(1)   -bs is done here
int upperBound(vector<int> &arr, int x, int n){
    int low = 0, high = n - 1;
    int ans = n;  // Default set to n (if x not found)

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] > x){
            ans = mid;      // Potential answer found
            high = mid - 1; // Try to find smaller valid index on the left
        }
        else{
            low = mid + 1; // Move right if mid is <= x
        }
    }
    return ans; // Return the index of the upper bound
}