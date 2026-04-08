//statement- find all unique combi in arr where nos sum to target. Each number in candidates may only be used once in the combination. duplicates exist in given arr


//method1(brute) -using recursion t.c- O(2^n * k)  s.c- O(k * x)
void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) { // Base case: If target becomes 0, we found valid combi
        ans.push_back(ds);  // Add curr combi to result
        return;
    }

    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1]) continue; // Skip duplicates to avoid repeating combi

        if (arr[i] > target) break; // If curr element > remaining target, break loop

        ds.push_back(arr[i]); // Include curr element in combi

        findCombination(i + 1, target - arr[i], arr, ans, ds); // Recur with updated target & next index (i.e i+1 to avoid repetition)

        ds.pop_back(); // Backtrack by removing last added element
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  // Sort the arr to handle duplicates
    vector<vector<int>> ans;  // To store final answer
    vector<int> ds;  // To store curr combi
    findCombination(0, target, candidates, ans, ds);  // Calls helper func
    return ans;  // Return all valid combi
}

