//statement- Return no of non-empty subseq of nums such that sum of all elements in subseq = k


//method1(brute) t.c- O(2^n)  s.c- O(n)
int func(int ind, int sum, vector<int> &nums) {
    if (ind == nums.size()) {  // reached end → check if valid
        return (sum == 0) ? 1 : 0;
    }

    if (sum < 0) return 0;

    int take = func(ind + 1, sum - nums[ind], nums); // take curr element
    int notTake = func(ind + 1, sum, nums);    // skip curr element

    return take + notTake;
}

int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
    return func(0, target, nums);
}