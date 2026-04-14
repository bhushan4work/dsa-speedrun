//statement- given arr in form  (start[i], end[i]), return min no of intervals that need to be removed to make remaining intervals non-overlapping
//  its similar to n_meetings_in_room que, for this que: [1,3],[3,5] is not taken as an overlap


//(optimal) t.c- O(nlogn + n)  s.c- O(1)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {  // Sort by endtime to maximize no of intervals we can take
        return a[1] < b[1];
    });

    int count = 1;                 // at least one interval can always be taken
    int prevEnd = intervals[0][1]; // track last chosen interval's end
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= prevEnd) { // If no overlap, include this interval
            count++;
            prevEnd = intervals[i][1];
        }
    }
    return intervals.size() - count; // Removals = total - intervals kept
}