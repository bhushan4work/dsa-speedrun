// statement- given start & end time arr for meeting. Find max no of meetings that can happen if only 1 meeting can happen at particular time
//note :  start time of one chosen meeting can't be equal to end time of other meeting


// method1(optimal) t.c- O(n)  s.c- O(1)
int maxMeetings(vector<int> &start, vector<int> &end){
    int n = start.size();
    vector<pair<int, int>> meetings;

    for (int i = 0; i < n; i++){
        meetings.push_back({end[i], start[i]});
    }

    //sort for a pair compares 1st element initially & if its samme then it compares 2nd element for sorting
    sort(meetings.begin(), meetings.end()); //sorts wrt end time of meeting

    int count = 1; // first meeting always selected
    int last_end = meetings[0].first; //last ended meeting time

    for (int i = 1; i < n; i++){ //we start loop from 2nd pair of meeting
        if (meetings[i].second > last_end){ // STRICT >
            count++;
            last_end = meetings[i].first; //update last ended meeeting time
        }
    }
    return count;
}