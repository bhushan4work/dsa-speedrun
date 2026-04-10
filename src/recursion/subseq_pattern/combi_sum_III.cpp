// statement- Determine all possible set of k nos that can be added together to equal n while meeting following requirements: 1)use numerals 1-9 2)single use of each no


// method1(brute) t.c- O(2^9 * k)  s.c- O(k)
void backtrack(int start, int k, int remaining, vector<int> &path, vector<vector<int>>& result){
    if (path.size() == k){ // Base case: if we picked k nos
        if (remaining == 0){ // Check if sum is satisfied
            result.push_back(path); // valid combi
        }
        return; // stop further recursion
    }

    for (int i = start; i <= 9; i++){
        if (i > remaining) break; // Pruning: if curr no exceeds remaining sum, stop loop

        path.push_back(i); // Choose curr no

        backtrack(i + 1, k, remaining - i, path, result); // Recurse with next nos (i+1 to avoid reuse)

        path.pop_back(); // Backtrack: remove last chosen no
    }
}

vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>> result; // stores final valid combinations
    vector<int> path;         // current combination
    backtrack(1, k, n, path, result); // start from 1
    return result;
}