//statement- check if given array is sorted or not and return boolean

bool check(vector<int> &nums){
    for (int i = 1; i < nums.size(); i++){
        if (nums[i - 1] <= nums[i]){ //checks if prev element is <= current element
        
        }
        else{
            return false;
        }
    }
    return true;
}