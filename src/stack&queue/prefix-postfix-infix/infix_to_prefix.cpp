// statement- Given infix expression, task is to convert given infix expression to prefix expression
//  Approach:
//  Reverse given infix expression
//  When operand is encountered, add it in ans
//  If op is encountered & stack is empty, push op into stack
//  If scanned op has higher priority than top of stack, push it into stack
//  If scanned op has same priority as top of stack, push it into stack
//  If scanned op is other than '^' , put it in stack
//  If op is '(', put it in stack
//  If scanned char is a ‘)’, pop the stack & add it in ans until a ‘(’ is encountered, thereby discard both parenthesis
//  At end of expression, pop & add all remaining op from stack to ans
//  Finally, reverse the output & print it as prefix expression




//(optimal) t.c- O(n\2 + n\2 + 2n)  s.c- O(n)

// function to return precedence of op
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// function to check if char is op
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if op is right-associative
bool isRightAssociative(char op) {
    return (op == '^');
}

// function to convert infix to prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    // swap '(' and ')'
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;    
    string result = ""; 

    // convert to postfix (on reversed expression)
    for (int i = 0; i < (int)s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) {
            result += c; 
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); 
        }
        else if (isOperator(c)) {
                while (!st.empty() && st.top() != '(' &&
                ((precedence(st.top()) > precedence(c)) ||
                (precedence(st.top()) == precedence(c) && isRightAssociative(c)))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop all remaining op
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end()); // reverse result to prefix
    return result;
}