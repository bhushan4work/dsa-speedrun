// statement- check if 2 strings are anagrams of each other. Anagrams: all possible permutations of string

// method1(brute) t.c- O(nlogn + n)  s.c- O(1)
bool CheckAnagrams(string str1, string str2){
    if (str1.length() != str2.length()){  // checks edge case
        return false; // Strings can't be anagrams if lengths are different
    }

    //sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    //check if every char of str1 & str2 matches with each other
    for (int i = 0; i < str1.length(); i++){ 
        if (str1[i] != str2[i]){
            return false; // If any character doesn't match, they aren't anagrams
        }
    }
    return true; 
}

// method2(optimal) t.c- O(n)  s.c- O(1)
bool CheckAnagrams(string str1, string str2){
    if (str1.length() != str2.length()){  // checks edge case
        return false; // Strings can't be anagrams if lengths are different
    }

    int freq[26] = {0}; // make a freq arr to store char count

    // Count freq of each char in str
    for (int i = 0; i < str1.length(); i++){ 
        freq[str1[i] - 'A']++; // Increment freq for each char in str1
        freq[str2[i] - 'A']--; // Decrement freq for each char in str2
    }

    // Check if all freq are zero, i.e both strings have same char's
    for (int i = 0; i < 26; i++){
        if (freq[i] != 0){ // If freq of any char is non-zero,then they ain't anagrams
            return false;
        }
    }
    return true;
}
