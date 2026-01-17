//statement- sorted arr is rotated between 1 to N times which is unknown. Find how many times the arr has been rotated
//approach- index of min in rotated arr == amt of time it is rotated 

//method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int findMin(vector<int> &arr){
    int mini = INT_MAX;
    int miniIndex = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] < mini){
            miniIndex = i;
            mini = arr[i];
        }
    }
    return miniIndex;
}

//method2(optimal) t.c- O(logn)  s.c- O(1)  -bs is used here
int findMin(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;
    int miniIndex = 0;

    while (low <= high){
        int mid = (low + high) / 2;
        //If search space is already sorted, break out of the loop & return mini
        if(arr[low] <= arr[high]){
            if(arr[low] < mini){ 
                miniIndex = low;
                mini = arr[low];
            }
            break; 
        }

        if(arr[low] <= arr[mid]){  //leftSide is sorted 
            if(arr[low] < mini){ 
                miniIndex = low;
                mini = arr[low];
            }
            low = mid + 1;  //move to other part i.e rightSide to check for min val
        }
        else{ //arr[low] > arr[mid] , i.e right part is sorted
            if(arr[mid] < mini){ 
                miniIndex = mid;
                mini = arr[mid];
            }
            high = mid - 1;  //move to other part i.e leftSide to check for min val
        }
    }
    return miniIndex ;
}

//FAQ's- same above question with duplicate elements

//(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int findKRotation(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;
    int miniIndex = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        //to handle duplicates
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            if(arr[low] < mini){
                mini = arr[low];
                miniIndex = low;
            }
            low++;
            high--;
        }
        // If searchSpace is already sorted
        else if(arr[low] <= arr[high]){
            if(arr[low] < mini){
                mini = arr[low];
                miniIndex = low;
            }
            break;
        }
        // Left part sorted
        else if(arr[low] <= arr[mid]){
            if(arr[low] < mini){
                mini = arr[low];
                miniIndex = low;
            }
            low = mid + 1;
        }
        // Right part sorted
        else{
            if(arr[mid] < mini){
                mini = arr[mid];
                miniIndex = mid;
            }
            high = mid - 1;
        }
    }
    return miniIndex;
}