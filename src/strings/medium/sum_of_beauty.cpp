// statement- beauty of str: difference betn most frequent char & least freq char. return sum of beauty values of all possible substr

// (optimal) t.c- O(n^2)  s.c- O(26)
int beautySum(string s){
    int ans = 0;

    for (int i = 0; i < s.size(); i++){
        vector<int> freq(26, 0);

        for (int j = i; j < s.size(); j++){
            freq[s[j] - 'a']++;

            int maxi = 0;
            int mini = INT_MAX;

            for (int c = 0; c < 26; c++){
                if (freq[c] > 0){ // Find max and min frequency (ignore zeros)
                    maxi = max(maxi, freq[c]);
                    mini = min(mini, freq[c]);
                }
            }
            ans += (maxi - mini); //calculate sum for curr substr
        }
    }
    return ans;
}