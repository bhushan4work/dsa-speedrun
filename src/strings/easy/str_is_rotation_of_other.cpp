// statement- return true if s can become goal after some number of shifts on s. shift on s consists of moving leftmost char of s to the rightmost position
//            For example, if s = "abcde", then it will be "bcdea" after one shift

// method1(brute) t.c- O(n^2)  s.c- O(n)
bool rotateString(string &s, string &goal){
    if (s.length() != goal.length()){   // str must be of same length to be rotations of each other
        return false;
    }
    // Try all possible rotations of 's'
    for (int i = 0; i < s.length(); i++){
        string rotated = s.substr(i) + s.substr(0, i); // (strt index of str, len of str)
        if (rotated == goal){
            return true; //goal found
        }
    }
    return false; //goal not found in given str
}

// method2(optimal) t.c- O(2n + n)  s.c- O(2n)
// Check if goal is rotation of s by doubling the given str
bool rotateString(string& s, string& goal) {
    if (s.length() != goal.length()) return false; // Strings must be of same length to be rotations of each other
    
    // Concatenate s with itself and check if goal exists in it
    string doubledS = s + s; // takes 2n space & 2n time
    if(doubledS.find(goal) != string::npos) {  //npos means not found & its index is -1
        return true ; //goal found as we get someIndex != -1
    }
    else{
        return false ; //goal not found as we get -1 == -1
    }
}
