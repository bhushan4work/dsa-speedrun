//statement- subque1) if sum of 2 nums == target print yes else no ; subque2) if sum of 2 nums == target return their index else {-1,-1}

//method1(brute) t.c- O(n^2) s.c- O(1)
string twoSumExists(vector<int> &arr, int target){
    //type1
    for (int i = 0; i < arr.size(); i++){ 
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[i] + arr[j] == target){   // If sum equals target, return "YES"
                return "YES";  
            } 
        }
    }
    return "NO"; // No pair found that sums to target
}
vector<int> twoSumIndices(vector<int>& arr, int target) {
    //type2
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target) {  // If sum equals target, return the pair of indices
                return {i, j};
            }
        }
    }
    return {-1, -1}; // No such pair found
}


//method2 with hashing(better)  t.c- O(n) s.c- O(n)
//if we take map here t.c- O(nlogn) 
string twoSumExists(vector<int>& arr, int target) {
    //type1
    unordered_map<int, int> mp;  // Map to store element -> index
    for (int i = 0; i < arr.size(); i++) {
        int moreNeeded = target - arr[i];  // Needed value to reach target sum
        // Check if moreNeeded is already in map
        if (mp.find(moreNeeded) != mp.end()) {
            return "YES";  // Pair found
        }
        // Store current element with its index for future reference
        mp[arr[i]] = i;
    }
    return "NO";  // No pair found
}
vector<int> twoSumIndices(vector<int>& arr, int target) {
    //type2
    unordered_map<int, int> mp;  // Map to store element -> index
    for (int i = 0; i < arr.size(); i++) {
        int moreNeeded = target - arr[i];
        if (mp.find(moreNeeded) != mp.end()) {
            return {mp[moreNeeded], i}; // If moreNeeded found, return indices
        }
        mp[arr[i]] = i; // Store current element and index
    }
    return {-1, -1};  // No pair found
}

//method3 with 2pointer(optimal) t.c- O(n+nlogn)  s.c- O(n)
string twoSumExists(vector<int> arr, int target) {
    //type1
    int left = 0, right = arr.size() - 1;
    sort(arr.begin(), arr.end()); // Sort based on the element values
    while (left < right) {   // Loop until the 2 pointers cross
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";  // Pair found
        } else if (sum < target) {
                left++;  // Need bigger sum, move left pointer right as arr is sorted
        } else {
                right--; // Need smaller sum, move right pointer left as arr is sorted
        }
    }
    return "NO";  // No pair found
}
vector<int> twoSumIndices(vector<int> arr, int target) {
    //type2 - this is not optimal approach for type2 , go with better approach only for type2
    vector<pair<int, int>> numsWithIndex; // Create vector of pairs to remember original indices after sorting
    for (int i = 0; i < arr.size(); i++) {
        numsWithIndex.push_back({arr[i], i});
    }
    sort(numsWithIndex.begin(), numsWithIndex.end());
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = numsWithIndex[left].first + numsWithIndex[right].second;
        if (sum == target) {
            return {numsWithIndex[left].second, numsWithIndex[right].second}; // Return original indices
        } else if (sum < target) {
                left++;
        } else {
            right--;
        }
    }
    return {-1, -1};  // No pair found
}

