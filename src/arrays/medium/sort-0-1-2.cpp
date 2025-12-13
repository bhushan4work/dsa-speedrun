//problem- Given an arr consisting of only 0,1,or2. Sort the arr in non-decreasing order. The sorting must be done in-place, without making copy of original arr.

//method1(brute) t.c- O(nlogn) s.c- O(logn)
void sortColors(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

//method2(better)- t.c-  O(2n) s.c- O(1)
void sortColors(vector<int> &arr){
    int n = arr.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0; // initialize counter
    //count 0's,1's,2's
    for (int i = 0; i < n; i++){
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    // put back values
    for (int i = 0; i < cnt0; i++){
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++){
        arr[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < n; i++){
        arr[i] = 2;
    }
}

//method3(optimal) using Dutch-NationalFlag-Algorithm  t.c- O(n)  s.c- O(1)
void sortColors(vector<int>& arr) {
    int low=0, mid=0, high=arr.size()-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low] , arr[mid]);
            low++;
            mid++ ;
        } 
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid] , arr[high]);
            high--; 
        }
    }
}