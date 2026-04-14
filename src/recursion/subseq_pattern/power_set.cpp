// statement- find all possible subsequences of the str including str itself.
//In subseq problem: We use idea of "pick or not pick" for each char in str or element in arr


// (brute) -using recursion t.c- O(n * 2^n)  s.c- O(n * 2^n)
void helper(string &s, int index, string &current, vector<string> &result) {
    if (index == s.size()) { // BASE CASE:If we have processed all char
        result.push_back(current);  // store the curr subsequence
        return;
    }
    
    // STEP 1: EXCLUDE the curr char
    helper(s, index + 1, current, result); // Move to next index without adding anything

    // STEP 2: INCLUDE the current character
    current.push_back(s[index]);   // choose the char

    helper(s, index + 1, current, result);

    current.pop_back(); // BACKTRACK: Remove the last added char to restore prev state
}

vector<string> getSubsequences(string s) {
    vector<string> result;   // stores all subsequences
    string current = "";     // temporary str

    helper(s, 0, current, result);

    return result;
}
