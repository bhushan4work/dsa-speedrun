//statement- sorted arr is rotated at any index which is unknown. Find the minimum element in the array (unique elements)
//approach- pick sorted part → store min val(i.e leftmost) → eliminate that part → check for min in other part & update min val

//method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int findMin(vector<int> &arr){
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] < mini){
            mini = arr[i];
        }
    }
    return mini;
}

//method2(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int findMin(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;

    while (low <= high){
        int mid = (low + high) / 2;
        //If search space is already sorted, break out of the loop & return mini
        if(arr[low] <= arr[high]){
            mini = min(mini, arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]){  //leftSide is sorted 
            mini = min(mini, arr[low]); //pick the min value in sorted part i.e 'low'
            low = mid + 1;  //move to other part i.e rightSide to check for min val
        }
        else{ //arr[low] > arr[mid] , i.e right part is sorted 
            mini = min(mini, arr[mid]); //pick min value in sorted part i.e 'mid'
            high = mid - 1;  //move to other part i.e leftSide to check for min val
        }
    }
    return mini ;
}


//FAQ's- same above question with duplicate elements

//(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int findMin(vector<int> &arr){ 
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;

    while (low <= high){
        int mid = (low + high) / 2;
        //If search space is already sorted, break out of the loop & return mini
        if(arr[low] <= arr[high]){
            mini = min(mini, arr[low]);
            break;
        }

        //edge case to handle duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) { 
            mini = min(mini, arr[low]);
            low++;
            high--;
        }

        if(arr[low] <= arr[mid]){  //leftSide is sorted 
            mini = min(mini, arr[low]); //pick the min value in sorted part i.e 'low'
            low = mid + 1;  //move to other part i.e rightSide to check for min val
        }
        else{ //arr[low] > arr[mid] , i.e right part is sorted 
            mini = min(mini, arr[mid]); //pick min value in sorted part i.e 'mid'
            high = mid - 1;  //move to other part i.e leftSide to check for min val
        }
    }
    return mini ;
}
