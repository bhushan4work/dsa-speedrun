// statement- Given an array of numbers, print all subsets of it using bitwise operators

//(better) t.c- O(2^n * n)  s.c- O(2^n * n)
vector<vector<int>> getPowerSet(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ans;

    int subsets = 1 << n; // i.e 2^n, Calculates total no of subsets using bitwise shift

    // Iterate through all numbers from 0 to 2^n - 1
    for (int num = 0; num < subsets; num++){
        vector<int> subset;

        // Iterate through each bit of the number ex: for num = 0 -> 000
        for (int i = 0; i < n; i++){
            if (num & (1 << i)){ // If the ith bit is set i.e 1, include arr[i] in subset
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}