// statement- convert given postfix into valid prefix expression
// Approach:
// Use stack to store operands
// For each op, pop 2 operands, combine them with op in prefix order,push result back
// final item in stack will be prefix expression


//(optimal) t.c- O(n)  s.c- O(n)
string postfixToPrefix(string postfix) {
    stack<string> s;
    int n = postfix.size();

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        // If the char is operand, push it to stack
        if (c >='A' && c <='Z' || 
            c >='a' && c <='z' ||
            c >='0' && c <='9') {
            s.push(string(1, c)); //here stack stores both char\string simultaneously so we explicitly add char s[i]
        }
        else {
            // Pop 2 operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            
            s.push(c + op2 + op1); // Form new prefix expression & push back to stack
        }
    }
    return s.top();
}