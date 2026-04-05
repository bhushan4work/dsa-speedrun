// statement- generate all combinations of well-formed parentheses of n pair of '()'


// method1(brute) -using recursion t.c- O(Cn * n)  s.c- O(Cn * n + n) i.e for output + recursive stack space
void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    
    if (curr.length() == 2*n) { // BASE CASE: If curr str length becomes 2*n, it means we used all brackets
        res.push_back(curr);   // store valid combination
        return;                // return to caller
    }

    // CHOICE 1: Add '(' Allowed only if we still have opening brackets left
    if (open < n) {
        backtrack(curr + '(', open + 1, close, n, res); // Create new str with '(' & go deeper
    }

    // CHOICE 2: Add ')' Allowed only if it keeps str valid i.e., number of ')' used must be < '(' used
    if (close < open) {
        backtrack(curr + ')', open, close + 1, n, res); // Create new str with ')' & go deeper
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res); // Start recursion with empty str & 0 brackets used
    return res;
}