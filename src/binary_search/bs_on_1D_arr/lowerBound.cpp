//statement-  write a program to find the lower bound of x
//lowerBound- It is smallest index where arr[ind] >= x. But if such index is not found, it returns n

// method1(brute) t.c- O(n)  s.c- O(1)   -normal iteration is done i.e bs not used here
int lowerBound(vector<int> arr, int n, int x){
    for (int i = 0; i < n; i++){
        if (arr[i] >= x){
            return i; 
        }
    }
    return n; //when no val is >= x 
}

// method2(optimal) t.c- O(logn) base is 2  s.c- O(1)  -bs is done here
int lowerBound(vector<int> arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int ans = n; // Default set to n (if x not found)

    while (low <= high){  // Binary search loop
        int mid = (low + high) / 2; // gives Middle index

        if (arr[mid] >= x){
            ans = mid;      // Stores possible answer
            high = mid - 1; // Try to find smaller index on left side
        }
        else{
            low = mid + 1; // Move right if current element is less than x
        }
    }
    return ans; // Return the index of the lower bound
}