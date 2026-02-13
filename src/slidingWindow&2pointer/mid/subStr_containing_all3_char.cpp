// statement- string s consists of char 'a', 'b', 'c. Find cnt of all possible substr that contain at least one occurrence of all these characters 'a' , 'b' , 'c'

// method1(brute) t.c- O(n^2)  s.c- O(3)
int numberOfSubstrings(string s){
    int count = 0;

    for (int i = 0; i < s.size(); i++){
        unordered_map<char, int> mpp;

        for (int j = i; j < s.size(); j++){
            mpp[s[j] - 'a']++; // Update frequency for current character in map

            if (mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0){ // Check if all 3 char are present & only then update the cnt
                // this part can be optimised by doing
                // cnt += s.size()-j ; break
                // i.e. after 1st valid substr having all 3 char further char will also be valid, so we add all of that & break
                count++;
            }
        }
    }
    return count;
}

// method2(optimal) t.c- O(n + n)  s.c- O(3)
int numberOfSubstrings(string s){
    int l = 0, r = 0;
    int cnt = 0;
    unordered_map<char, int> mpp;

    while (r < s.size()){
        mpp[s[r]]++; // Add the current char to map & incr its cnt

        while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0){ // we keep on shrinking 'l' pointer to the right until we get mpp.size <= 2
            cnt += s.size() - r;  //after 1st valid substr having all 3 char further char will also be valid, so we add all of that

            mpp[s[l]]--; // Remove one char from the left side
            l++; 
        }
        r++;
    }
    return cnt;
}

//alternative to map we can also use vector for freq
//use map only for que where huge data is to stored, as here we know that only 3 char is to be stored in map we should use a vector for better tc
int countSubstring(string s) {
    int n = s.size();
    int l = 0;
    long long cnt = 0;
    vector<int> freq(3, 0); // for a, b, c

    for (int r = 0; r < n; r++) {
        freq[s[r] - 'a']++;

        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            cnt += (n - r);
            freq[s[l] - 'a']--;
            l++;
        }
    }
    return cnt;
}