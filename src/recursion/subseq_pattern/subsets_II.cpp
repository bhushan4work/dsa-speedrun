// statement- given arr can have duplicate entries, provide the power set. Duplicate subsets cant exist in soln set. Return ans in any seq


// method1(brute) t.c- O(2^n)  s.c- O(n)
void backtrack(int start, vector<int> &nums, vector<int> &current, vector<vector<int>> &result){
    result.push_back(current); // Add the curr subset to result

    for (int i = start; i < nums.size(); i++){ // Iterate over the arr from 'start' index
        if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates: if curr no is same as prev & not at start index

        current.push_back(nums[i]); // Include nums[i] in curr subset

        backtrack(i + 1, nums, current, result); // Recurse for next index

        current.pop_back(); // Backtrack: remove last added element
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    sort(nums.begin(), nums.end()); // Sort the arr to handle duplicates

    vector<vector<int>> result;
    vector<int> current;

    backtrack(0, nums, current, result); // Start backtracking from index 0

    return result;
}
