// statement- Given postfix expression, convert it into infix expression. infix expression should have proper parentheses to ensure correct op priority
// Approach:
// Use stack to store operands
// For each op, pop 2 operands from stack, wrap them in parentheses, push resulting expression back to stack
// final item in stack will be infix expression


//(optimal) t.c- O(n)  s.c- O(n)
string postfixToInfix(string postfix) {
    stack<string> s;
    int n = postfix.size();
    char c = postfix[i];

    for (int i = 0; i < n; i++) {
        // If character is an operand, push it to stack
        if (c >='A' && c <='Z' || 
            c >='a' && c <='z' ||
            c >='0' && c <='9') {
            s.push(string(1, c)); //here stack stores both char\string simultaneously so we explicitly add char s[i]
        }
        else {
            // Pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            s.push("(" + op2 + c + op1 + ")"); // Form new infix expression & push back to stack
        }
    }
    return s.top();
}