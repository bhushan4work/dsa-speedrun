// statement-  Every element in the arr except one appears twice. Find the single element in the arr

// method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int singleNonDuplicate(vector<int> &arr){
    int n = arr.size();
    // handling edge case initially for 1st & last element of arr
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    for (int i = 1; i < n - 1; i++){
        if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]){
            return arr[i];
        }
    }
    return -1;
}

// method2(brute) t.c- O(n)  s.c- O(1)  -XOR is done i.e bs not used here
// a ^ a = 0, a ^ 0 = a, XOR all elements, all duplicates will be = 0 & we'll get single element
int singleNonDuplicate(vector<int> &arr){
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

// method3(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int singleNonDuplicate(vector<int> &arr){
    int n = arr.size();
    // handling edge case initially for 1st & last element of arr
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high){
        int mid = (low + high) / 2;

        //right & left of mid are != mid then we got our single element
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]){
            return arr[mid]; 
        }

        // we are in left side (even,odd)
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            low = mid + 1; // eliminate left side & move to right of mid
        }
        // we are in right side (odd,even)
        else{
            high = mid - 1; // eliminate right side & move to left of mid
        }
    }
    return -1;
}