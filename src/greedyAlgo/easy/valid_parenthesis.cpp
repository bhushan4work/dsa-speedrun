// statement- given a str s containing only 3 types of char: '(',')' & '*', return true if s is valid
// note: '*' could be treated as ')' or '(' or empty string ""

// (brute) t.c- O(3^n)  s.c- O(n)
bool solve(int i, int open, string &s){
    if (open < 0) return false;

    if (i == s.size()){
        return open == 0;
    }

    if (s[i] == '('){
        return solve(i + 1, open + 1, s);
    }
    else if (s[i] == ')'){
        return solve(i + 1, open - 1, s);
    }
    else{ // '*'
        return solve(i + 1, open + 1, s) || // '('
               solve(i + 1, open - 1, s) || // ')'
               solve(i + 1, open, s);       // empty
    }
}

bool checkValidString(string s){
    return solve(0, 0, s); // start at index 0 with 0 open brackets
}


// (optimal) t.c- O(n)  s.c- O(1)
bool checkValidString(string s){
    int minOpen = 0, maxOpen = 0; // range of possible open brackets

    for (char c : s){
        if (c == '('){
            minOpen++; // definitely increases open
            maxOpen++;
        }
        else if (c == ')'){
            minOpen--; // definitely decreases open
            maxOpen--;
        }
        else{ // '*'
            minOpen--;  // treat as ')'
            maxOpen++; // treat as '('
        }

        if (maxOpen < 0) return false; // we have more ')' than '(' → impossible
        if (minOpen < 0) minOpen = 0; //  we assumed too many ')' from '*' → adjust by treating some '*' as empty
    }
    return minOpen == 0; // valid if 0 open possible
}