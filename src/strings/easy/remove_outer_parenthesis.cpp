// statement- remove outermost parentheses from every primitive component of s & return resulting string
// note: primitive valid parentheses string is non-empty valid string that cant be split into 2 or more non-empty valid parentheses strings

// (brute) t.c- O(n)  s.c- O(n)
string removeOuterParentheses(string s){
    stack<char> st; 
    string ans = "";

    for (int i=0;i<s.size();i++){
        if (s[i] == '('){
            if (!st.empty()){  //when stack is not empty 
                ans += s[i]; //add '(' to ans
            }
            st.push(s[i]); //when stack empty
        }
        else if (s[i] == ')'){
            st.pop(); //remove prev added '(' as we get a pair of ()
            if (!st.empty()){  //when stack is not empty 
                ans += s[i]; //add ')' to ans
            }
        }
    }
    return ans;
}

// (optimal) t.c- O(n)  s.c- O(1)
string removeOuterParentheses(string s){
    string ans = "";
    int cnt = 0;
    // add parenthesis to ans only when cnter is > 0
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            if (cnt > 0) ans += s[i]; // check 1st & incr cnt later as we dont wanna add the 1st outer (
            cnt++;  // incr the cnter for '('
        }
        else{ // for ')' parenthesis
            cnt--; // decr the cnter for ')'
            if (cnt > 0) ans += s[i];
        }
    }
    return ans;
}