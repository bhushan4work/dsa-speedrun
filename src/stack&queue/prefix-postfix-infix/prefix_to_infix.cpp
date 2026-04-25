// statement- convert given prefix into fully parenthesized infix expression
// Approach:
//traverse from right to left
// Use stack to store operands
// For each op, pop 2 operands from stack, wrap them in parentheses, push resulting expression back
// final item in stack will be infix expression


//(optimal) t.c- O(n)  s.c- O(n)
string prefixToInfix(string prefix) {
    stack<string> s;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        // If char is operand, push it to stack
        if (c >='A' && c <='Z' || 
            c >='a' && c <='z' ||
            c >='0' && c <='9') {
            s.push(string(1, c)); //here stack stores both char\string simultaneously so we explicitly add char s[i]
        }
        else {
            // Pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Form new infix expression & push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }
    return s.top();
}