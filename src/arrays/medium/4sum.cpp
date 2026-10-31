//statement- Given an arr, return an arr of all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that: 0 <= a, b, c, d < n ;
//a, b, c, d are distinct ; nums[a] + nums[b] + nums[c] + nums[d] == target ; return ans in any order


//(brute) t.c- O(n^4) s.c- O(m)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 4) { // Four different indices are required.
        return {};
    }

    set<vector<int>> uniqueQuadruplets;
    for (int first = 0; first < n - 3; first++) { // Generate every combination of four different indices exactly once.
        for (int second = first + 1; second < n - 2; second++) {
            for (int third = second + 1; third < n - 1; third++) {
                for (int fourth = third + 1; fourth < n; fourth++) {

                    long long sum = (long long) nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) { // A matching sum gives a valid quadruplet.
                        vector<int> quadruplet = {nums[first], nums[second], nums[third], nums[fourth]};

                        sort(quadruplet.begin(), quadruplet.end()); // Sorting gives duplicate quadruplets the same arrangement.
                        uniqueQuadruplets.insert(quadruplet);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
}



//(better) -using hashing t.c- O(n^3) s.c- O(n + m)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 4) { // Four different indices are required.
        return {};
    }

    set<vector<int>> uniqueQuadruplets;
    for (int first = 0; first < n - 3; first++) {
        for (int second = first + 1; second < n - 2; second++) {
            unordered_set<long long> seenValues;

            for (int third = second + 1; third < n; third++) { // Values seen earlier can act as the fourth element of a quadruplet.

                long long fourthValue = (long long) target - nums[first] - nums[second] - nums[third];
                if (seenValues.find(fourthValue) != seenValues.end()) { // A previously seen required value completes the target sum.
                    vector<int> quadruplet = {nums[first], nums[second], nums[third], (int) fourthValue};

                    sort(quadruplet.begin(), quadruplet.end());
                    uniqueQuadruplets.insert(quadruplet);
                }

                seenValues.insert(nums[third]); // Insert after lookup so the current index cannot be reused.
            }
        }
    }

    return vector<vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
}



//(optimal) t.c- O(n^3) s.c- O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> answer;
    if (n < 4) { // Four different indices are required.
        return answer;
    }

    sort(nums.begin(), nums.end());

    for (int first = 0; first < n - 3; first++) {
        if (first > 0 && nums[first] == nums[first - 1]) { // Bypass duplicates for 'first' to ensure unique answers.
            continue;
        }

        for (int second = first + 1; second < n - 2; second++) {
            if (second > first + 1 && nums[second] == nums[second - 1]) { // Bypass duplicates for 'second'.
                continue;
            }

            int left = second + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long) nums[first] + nums[second] + nums[left] + nums[right];
                if (sum < target) { // A smaller sum needs a larger left value.
                    left++;
                }
                else if (sum > target) { // A larger sum needs a smaller right value.
                    right--;
                }
                else {
                    answer.push_back({nums[first], nums[second], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip repeated boundary values to avoid duplicate answers.
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
    }

    return answer;
}
