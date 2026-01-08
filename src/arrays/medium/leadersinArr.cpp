//statement- Find all leaders in arr. An element is a leader if it is strictly greater than all the elements on its right side
//Note: Rightmost element is always a leader

//method1(brute) t.c- O(n^2)  s.c- O(n) for storing ans in other vec
//add nlogn in t.c if arr is sorted at last, add n in t.c if arr is reversed at last for final output
vector<int> leaders(vector<int> &nums){
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++){
        bool leader = true;
        for (int j = i + 1; j < nums.size(); j++){  //Check whether nums[i] is greater than all elements to its right
            if (nums[j] >= nums[i]){
                leader = false;  //If any element to the right is greater or equal, nums[i] is not a leader
                break;   //so we break out of the loop
            }
        }
        if (leader){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

//method2(optimal) t.c- O(n)  s.c- O(n) for storing ans in other vec
//add nlogn in t.c if arr is sorted at last, add n in t.c if arr is reversed at last for final output
vector<int> leaders(vector<int> &nums){
    vector<int> ans;
    int n = nums.size();
    int max = nums[n - 1]; //Last element of the arr is always a leader
    ans.push_back(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--){   // Check elements from right to left
        if (nums[i] > max){
            ans.push_back(nums[i]);
            max = nums[i]; //updates max after every iteration
        }
    }
    return ans;
}
