// statement- arr has distinct int, return list of all unique combi where chosen nos sum to target. same no can be chosen unlimited no of times

// (brute) -using recursion t.c- O(2^t * k)  s.c- O(k * x)
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if (ind == arr.size()){ // Base case: if we have considered all elements in arr
        if (target == 0){ // If target is zero, we found valid combi
            ans.push_back(ds); // Add curr combi to result
        }
        return;
    }

    if (arr[ind] <= target){ // Recursive case: pick element if its <= target
        ds.push_back(arr[ind]);                                // Add curr element to combi
        findCombination(ind, target - arr[ind], arr, ans, ds); // Continue with same index to allow repeated elements
        ds.pop_back();                                         // Backtrack by removing the last added element
    }

    findCombination(ind + 1, target, arr, ans, ds); // Skip curr element & move to next index
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>> ans;                         // To store the result
    vector<int> ds;                                  // To store a curr combi
    findCombination(0, target, candidates, ans, ds); // Start recursive search
    return ans;                                      // Return all valid combi
}
