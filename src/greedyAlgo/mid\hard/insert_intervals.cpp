// statement- Insert newInterval arr into intervals arr such that intervals is still sorted in ascending order by starti & intervals still doesnt have any overlapping intervals (merge overlapping intervals if necessary)


// (optimal) t.c- O(n)  s.c- O(n)
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval){
    int n = intervals.size(); // Total no of existing intervals
    vector<vector<int>> res;  // Result vector to store final merged intervals

    int i = 0;

    // Add all intervals that come completely before newInterval (i.e., their end < start of newInterval)
    while (i < n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]);
        i++;
    }

    // Merge all overlapping intervals with newInterval. Overlap cond: interval start <= newInterval end
    while (i < n && intervals[i][0] <= newInterval[1]){
        // Update newInterval to cover the merged range
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval); // Add the merged interval

    //  Add all remaining intervals (those after newInterval)
    while (i < n){
        res.push_back(intervals[i]);
        i++;
    }
    return res; // Return final list of intervals
}