// statement- peak element: element greater than both neighbours. If multiple peak num exist, return index of any peak num

// method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int findPeakElement(vector<int> &arr){
    int n = arr.size();
    // handling edge cases of 1st & last element
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    for (int i = 1; i < n - 1; i++){
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
    }
    return -1;
}

// method2(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int findPeakElement(vector<int> &arr){
    int n = arr.size();
    // handling edge cases of 1st & last element
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
            return mid;
        }
        // left is incr curve till mid, so we wont find peak on left
        else if (arr[mid] > arr[mid - 1]){
            low = mid + 1; // move to right side
        }
        // right is decr curve after mid, so we wont find peak on right
        else{  // arr[mid] > arr[mid+1] ,
            high = mid - 1; // move to left side
        }
    }
    return -1;
}
