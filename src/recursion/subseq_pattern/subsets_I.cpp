// statement- Given an arr print all the sum of subset generated from it, in increasing order


// method1(brute) t.c- O(2^n)  s.c- O(n)
void solve(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    current.push_back(nums[index]); // Include
    solve(index + 1, nums, current, result);

    current.pop_back(); // Backtrack

    solve(index + 1, nums, current, result); // Exclude
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> current;

    solve(0, nums, current, result);

    return result;
}