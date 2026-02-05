// statement- Roman numerals are represented by 7 different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000, return integer value of given roman numeral

// method1(optimal) t.c- O(n)  s.c- O(1)
int romanToInt(string s){
    int ans = 0;

    unordered_map<char, int> roman = {   // Map of Roman numerals to their integer values
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} 
    };

    for (int i = 0; i < s.size() - 1; i++){  // Iterate through the string, except the last character
        if (roman[s[i]] < roman[s[i + 1]]){
            ans -= roman[s[i]]; // Subtract if current numeral is less than the next
        }
        else{
            ans += roman[s[i]];  // Otherwise, add the current value
        }
    }
    return ans + roman[s.back()];  // Add the value of the last character
}