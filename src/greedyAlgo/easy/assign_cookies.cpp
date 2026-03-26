//statement- given 2 arr, student & cookie, ith value in student arr describes min size of cookie that the ith student can be assigned.
//           jth value in cookie arr represents size of jth cookie. If cookie[j] >= student[i], jth cookie can be assigned to ith student.
//           Maximize no of students assigned with cookies & output max no


//method1(optimal) t.c- O(nlogn + mlogm + n + m)  s.c- O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    //sort both arr to apply greedy algo
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0; // pointer for children
    int j = 0; // pointer for cookies

    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            i++; // child satisfied
        }
        j++; // move to next cookie
    }
    return i; // number of satisfied children
}
