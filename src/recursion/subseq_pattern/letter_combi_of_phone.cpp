// statement- str consisting of digits from 2-9. Return all possible letter combi that number can represent

// method1(brute) t.c- O(4^n * n)  s.c- O(n)
void backtrack(int index, string &digits, string &path, vector<string> &result,  vector<string>& mapping){
    if (index == digits.size()){ // Base case: if curr combi length == digits length
        result.push_back(path);
        return;
    }
    
    string letters = mapping[digits[index] - '0']; // Get letters corresponding to curr digit

    for (char ch : letters){
        path.push_back(ch);                         // choose
        backtrack(index + 1, digits, path, result, mapping); // explore
        path.pop_back();                            // backtrack
    }
}

vector<string> letterCombinations(string digits){
    vector<string> mapping = { // Mapping of digits to letters
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> result;
    if (digits.empty()) return result; // Edge case: empty input

    string path = "";
    backtrack(0, digits, path, result, mapping);

    return result;
}