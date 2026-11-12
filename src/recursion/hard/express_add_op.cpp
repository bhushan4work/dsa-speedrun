// statement- Given a string consisting of only digits, & an integer target. Return all possibilities to insert binary op '+' , '*' , '-' betw digits of string,
//            such that resultant equals to target. Note that operands in returned expression shouldnt contain leading zeros, given number can consist of multiple digits


// (optimal) t.c- O(n * (4^n))  s.c- O(n)
void dfs(int i, string path, long long resSoFar, long long prevNum, string& s, int target, vector<string>& ans) {
    if (i == s.length()) { // Base case: reached end of string.
        if (resSoFar == target) { // If evaluated expression matches target, add to results.
            ans.push_back(path);
        }
        return;
    }

    for (int j = i; j < s.length(); j++) { // Explore all possible substrings starting from index i.
        if (j > i && s[i] == '0') { // Skip numbers with leading zeros to prevent invalid numbers.
            break;
        }

        string numStr = s.substr(i, j - i + 1); // Extract current substring.
        long long currNum = stoll(numStr); // Convert extracted substring to a numeric value.
        if (i == 0) { // For very first number, pick it without adding any preceding operator.
            dfs(j + 1, path + numStr, currNum, currNum, s, target, ans);
        }
        else {
            dfs(j + 1, path + "+" + numStr, resSoFar + currNum, currNum, s, target, ans); // Try addition operator.
            dfs(j + 1, path + "-" + numStr, resSoFar - currNum, -currNum, s, target, ans); // Try subtraction operator.
            dfs(j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * currNum, prevNum * currNum, s, target, ans); // Try multiplication operator (adjusting precedence).
        }
    }
}

vector<string> addOperators(string s, int target) {
    vector<string> ans; // List to store all valid mathematical expressions.
    dfs(0, "", 0, 0, s, target, ans); // Start DFS traversal from index 0.

    return ans;
}