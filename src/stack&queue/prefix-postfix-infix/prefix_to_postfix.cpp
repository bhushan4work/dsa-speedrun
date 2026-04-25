// statement- convert given prefix into valid postfix expression
// Approach:
//traverse from right to left
// Use stack to store operands
// For each op, pop 2 operands from stack, combine them with op, push result back
// final item in stack will be postfix expression


//(optimal) t.c- O(n)  s.c- O(n)
string prefixToPostfix(string prefix) {
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
            // Pop 2 operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            s.push(op1 + op2 + c); // Form new postfix expression & push back to stack
        }
    }
    return s.top();
}