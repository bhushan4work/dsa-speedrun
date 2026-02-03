// statement- 2 str are isomorphic if char in s can be replaced to get t
//            No 2 char's may map to same char, but char may map to itself (ex: foo & bar is false but cdd & egg is true )

// method1(optimal) t.c- O(n)  s.c- O(1)
bool isomorphicString(string s, string t){
    int n = s.size();
    int m1[256] = {0}, m2[256] = {0}; // Arr to store lastSeen positions of char's in s & t

    for (int i = 0; i < n; ++i){
        if (m1[s[i]] != m2[t[i]]) return false; // If prev position of curr char differ, return false

        // Update the position with current index + 1
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}