#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums){
    for (int i = 1; i < nums.size(); i++){
        if (nums[i - 1] <= nums[i]){ //checks if prev element is smaller than current element
        
        }
        else{
            return false;
        }
    }
    return true;
}