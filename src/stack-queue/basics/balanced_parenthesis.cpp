//statement- given str '(', ')', '{', '}', '[' ']', check if input str is valid & return true if str is balanced otherwise return false
//Note: Open brackets must be closed by same type of brackets, Open brackets must be closed in correct order


//(optimal) t.c- O(n)  s.c- O(n)
bool isValid(string s) {
    stack<char> st;  // Stack to store opening brackets

    for (auto it : s) {
        if (it == '(' || it == '{' || it == '['){
            st.push(it);  // Push opening brackets to stack
        }
        else {
            if (st.empty()){
                return false;  // No matching opening bracket
            }
            char ch = st.top();
            st.pop();

            // Check for matching pair
            if ((it == ')' && ch == '(') ||
                (it == ']' && ch == '[') ||
                (it == '}' && ch == '{')) {
                    continue;
            }
            else{
                return false;
            }
        }
    }
    return st.empty();  // True if all brackets matched
}