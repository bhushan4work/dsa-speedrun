// statement- Given arr intervals[i] = [starti, endi], merge all overlapping intervals, return arr of non-overlapping intervals that cover all intervals in input


// method1(brute) t.c- O(nlogn + n^2)  s.c- O(n)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end()); //  Sort intervals based on starting time
    vector<vector<int>> res;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Try merging with upcoming intervals
        for (int j = i + 1; j < n; j++) {
            if (intervals[j][0] <= end) { // If overlapping exist, extend curr interval
                end = max(end, intervals[j][1]);
            }
            else{
                break; // no more overlap possible (since sorted)
            }
        }
        res.push_back({start, end}); // Add merged interval
    }
    return res;
}


// method2(optimal) t.c- O(nlogn + n)  s.c- O(n)
vector<vector<int>> merge(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end()); // Sort intervals based on starting time
    vector<vector<int>> ans;               // Vector to store final merged intervals

    for (auto interval : intervals){
        if (ans.empty() || ans.back()[1] < interval[0]){ // If merged is empty or curr interval doesnt overlap
            ans.push_back(interval); // Add curr interval as new non-overlapping block
        }
        else{
            ans.back()[1] = max(ans.back()[1], interval[1]); // overlap exist: merge by extending the end time
        }
    }
    return ans;
}
