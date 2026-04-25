// statement- Given postfix expression, convert it into infix expression. infix expression should have proper parentheses to ensure correct op priority
// Approach:
// Use stack to store operands
// For each op, pop 2 operands from stack, wrap them in parentheses, push resulting expression back to stack
// final item in stack will be infix expression


//(optimal) t.c- O(n)  s.c- O(n)
string postfixToInfix(string s) {
    stack<string> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        // If character is an operand, push it to stack
         if ( (s[i] >= '0' && s[i] <= '9') || 
            (s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= 'a' && s[i] <= 'z') ) {
                st.push(string(1,s[i])); //here stack stores both char\string simultaneously so we explicitly add char s[i]
        }
        else {
            // Pop two operands from stack
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form new infix expression & push back to stack
            st.push("(" + op2 + s[i] + op1 + ")");
        }
    }
    return st.top();
}