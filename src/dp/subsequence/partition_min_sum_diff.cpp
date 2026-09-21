//statement- Given an arr of n integers, partition arr into 2 subsets such that absolute diff betw their sums is minimized
//note: due to size of statespace the memo code gives tle, use meet in the middle approach to avoid tle


// (optimal) -memoization t.c- O(n × n/2 × 2^n)  s.c- O(n × n/2 × 2^n)
map<tuple<int, int, long long>, int> dp;

int solve(int index, int count, long long sum, vector<int>& nums, int half, long long total) {
    if (count == half) { // Exactly n/2 elements must be selected.
        return llabs(total - 2 * sum); // Difference between two partition sums.
    }

    if (index == nums.size()) { // No elements are left.
        return INT_MAX;
    }

    auto state = make_tuple(index, count, sum);
    if (dp.count(state)) { // Return already calculated state.
        return dp[state];
    }

    int notTake = solve(index + 1, count, sum, nums, half, total); // Do not take current element.
    int take = solve(index + 1, count + 1, sum + nums[index], nums, half, total); // Take current element.

    return dp[state] = min(take, notTake); // Store minimum difference.
}

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int half = n / 2;
    long long total = 0;

    for (int x : nums) total += x; // Calculate total sum.

    return solve(0, 0, 0, nums, half, total);
}



// (optimal) -tabulation(meet in the middle approach) t.c- O( 2^(n/2) × n + 2^(n/2) log(2^(n/2)) )  s.c- O( 2^(n/2) )
int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int half = n / 2;

    long long total = 0;
    for (int x : nums) total += x; // Calculate total sum.

    vector<vector<long long>> left(half + 1);
    vector<vector<long long>> right(half + 1);

    // Generate all subset sums of left half.
    for (int mask = 0; mask < (1 << half); mask++) {
        long long sum = 0;
        int count = 0;

        for (int i = 0; i < half; i++) {
            if (mask & (1 << i)) {
                sum += nums[i]; // Take current element.
                count++;
            }
        }

        left[count].push_back(sum); // Store sum according to number of elements taken.
    }

    // Generate all subset sums of right half.
    for (int mask = 0; mask < (1 << half); mask++) {
        long long sum = 0;
        int count = 0;

        for (int i = 0; i < half; i++) {
            if (mask & (1 << i)) {
                sum += nums[half + i]; // Take current element from right half.
                count++;
            }
        }

        right[count].push_back(sum); // Store sum according to number of elements taken.
    }

    for (auto& v : right) {
        sort(v.begin(), v.end()); // Sorting helps find closest required sum.
    }

    long long mini = LLONG_MAX;

    for (int count = 0; count <= half; count++) {
        int need = half - count; // Remaining elements required from right half.

        for (long long leftSum : left[count]) {
            long long target = total / 2 - leftSum; // Ideal right-half sum.

            auto& v = right[need];

            auto it = lower_bound(v.begin(), v.end(), target); // Find closest sum >= target.

            if (it != v.end()) {
                long long sum = leftSum + *it;
                mini = min(mini, llabs(total - 2 * sum)); // Update minimum difference.
            }

            if (it != v.begin()) {
                --it; // Also check closest sum smaller than target.

                long long sum = leftSum + *it;
                mini = min(mini, llabs(total - 2 * sum)); // Update minimum difference.
            }
        }
    }

    return (int)mini;
}