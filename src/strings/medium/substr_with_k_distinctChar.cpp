//statement- given a str s & integer k. Return no of substr that contain exactly k distinct char
//same as counting binary sum problem where we do : exactly k = (k) - (k-1)

//method1(brute) t.c- O(n^2)  s.c- O(k) 
int countSubStrings(string s, int k) {
    int cnt = 0; 
    for(int i=0;i<s.size();i++){
        unordered_map<char,int> mpp; //stores char with its freq
        for(int j=i;j<s.size();j++){
            mpp[s[j]]++ ; //add char to the map
            if(mpp.size() == k){
                cnt++; //incr the cnter on getting k distinct char
            }
            if(mpp.size() > k ){
                break; //else break
            }
        }
    }
    return cnt ; 
}


//method2(optimal) t.c- O(n)  s.c- O(k)  
int atMostK(string &s, int x) {
    if (x < 0) return 0; //edge case for k=0 so it doesnt go -ve for k-1 cond

    int l = 0, r=0;
    int cnt = 0;
    unordered_map<char, int> mpp;

    while(r < s.size()) {
        mpp[s[r]]++;

        while (mpp.size() > x) { //keep shrinking from left until mapsize <= x
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]); //cleanup the map if any char turns 0
            }
            l++;
        }
        cnt += (r - l + 1); // All substr ending at r and starting from [l..r] are valid
        r++;
    }
    return cnt;
}
int countSubStrings(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}