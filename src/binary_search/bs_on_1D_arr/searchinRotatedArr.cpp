// statement- arr is sorted & have a target value k. The arr is rotated at some pivot point that is unknown. Find the index at which k is present & if not then return -1
// note: After sorting, indices change → wrong answer even if value is found. So return the index from the original rotated arr & not by sorting it manually
//  in this given rotated arr , either the left or right half will be sorted from mid so we check for such side & then eliminate accordingly


//method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int search(vector<int> &arr, int target){
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

//method2(optimal) t.c- O(logn)  s.c- O(1)  -bs algo used here
int search(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high){
        int mid = (low + high) / 2;

        if (nums[mid] == target){
            return mid;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]){
            if (nums[low] <= target && target < nums[mid]) { // If target lies in the sorted left half, search there
                high = mid - 1;
            }
            else{ // Else search in the right half
                low = mid + 1;
            }
        }

        // Otherwise, right half is sorted
        else{
            if (nums[mid] < target && target <= nums[high]){ // If target lies in the sorted right half, search there
                low = mid + 1;
            }
            else{ // Else search in the left half
                high = mid - 1;
            }
        }
    }
    return -1;
}




//FAQ's- same above question with duplicate elements
//note: same above code with one edge case added will will work here. [3,1,2,3,3,3,3]
//in above example we get mid=low=high so we cant determine sorted side & so we shrink the arr from both sides by 1

//(optimal) t.c- O(logn)  s.c- O(1)  -bs algo used here
bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) return true;

        // Edge case: all three are equal, we cannot determine which side is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;  //shrink from left side by 1
            high--;  //shrink from right side by 1
            continue;  //this rechecks again from start until all 3 are not equal & only then below code is executed 
        }

        // If the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1; // Target lies in left
            } else {
                low = mid + 1;  // Target lies in right
            }
        } else {
            // Right half is sorted
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;  // Target lies in right
            } else {
                high = mid - 1; // Target lies in left
            }
        }
    }
    return false;
}