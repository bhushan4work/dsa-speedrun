//statement- Given an integer arr, return all triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, j != k, & nums[i] + nums[j] + nums[k] == 0.
//note: that soln set must not contain duplicate triplets


//(brute) t.c- O(n^3) s.c- O(k)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) { // Three different indices are required.
        return {};
    }

    set<vector<int>> uniqueTriplets;

    for (int first = 0; first < n - 2; first++) { // Check every combination of three different indices exactly once.
        for (int second = first + 1; second < n - 1; second++) {
            for (int third = second + 1; third < n; third++) {

                long long sum = (long long) nums[first] + nums[second] + nums[third];
                if (sum == 0) { // A zero sum gives a valid triplet.
                    vector<int> triplet = {nums[first], nums[second], nums[third]};

                    sort(triplet.begin(), triplet.end()); // Sorting gives duplicate triplets the same arrangement.
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}



//(better) -using hashing t.c- O(n^2) s.c- O(n + k)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) { // Three different indices are required.
        return {};
    }

    set<vector<int>> uniqueTriplets;

    for (int first = 0; first < n - 2; first++) {
        unordered_set<long long> seenValues;
        for (int second = first + 1; second < n; second++) { // The set stores values already visited for the current fixed element.

            long long thirdValue = -(long long)(nums[first] + (long long)nums[second]);
            if (seenValues.find(thirdValue) != seenValues.end()) { // An earlier matching value completes the required zero-sum triplet.
                vector<int> triplet = {nums[first], nums[second], (int) thirdValue};

                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }

            seenValues.insert(nums[second]); // Insert after lookup so the current index cannot be reused.
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}



//(optimal) t.c- O(n^2) s.c- O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> answer;
    if (n < 3) { // Three different indices are required.
        return answer;
    }

    sort(nums.begin(), nums.end());

    for (int fixed = 0; fixed < n - 2; fixed++) {
        if (fixed > 0 && nums[fixed] == nums[fixed - 1]) {  // Skip adjacent duplicates for all elements after 1st to ensure unique results.
            continue;
        }

        int left = fixed + 1;
        int right = n - 1;
        while (left < right) {

            long long sum = (long long) nums[fixed] + nums[left] + nums[right];
            if (sum < 0) { // A smaller sum needs a larger left value.
                left++;
            }
            else if (sum > 0) { // A larger sum needs a smaller right value.
                right--;
            }
            else {
                answer.push_back({nums[fixed], nums[left], nums[right]});
                left++;
                right--;
                
                // Skip repeated values so the same triplet is not added again for j & k
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }
        }
    }

    return answer;
}
