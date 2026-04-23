// statement- Given infix expression, task is to convert given infix expression to postfix expression
// Approach:
// If scanned char is operand, add it in ans str
// If scanned char is a ‘(’, push it into the stack
// If scanned char is a ‘)’, pop the stack & add it in ans until a ‘(’ is encountered, thereby discard both parenthesis
// If scanned char is an op:
//                     If priority of this char is > than op in stack or stack is empty or stack contains a ‘(’, push op into stack
//                     else, pop all op from stack with higher or equal priority than the scanned operator, push it to ans, then push this scanned op to stack
// Repeat this until entire infix expression has been scanned
// Finally, pop from stack & add all char in ans until stack is empty

//(optimal) t.c- O(n + n)  s.c- O(n + n)
int priorityy(char c){
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string &s){
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++){
        char c = s[i];

        // Operand
        if ( (c >= '0' && c <= '9') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') ) {
                result += c;
        }

        // Opening bracket
        else if (c == '('){
            st.push(c);
        }

        // Closing bracket
        else if (c == ')'){
            while (!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // remove '('
        }

        // Operator
        else{
            while (!st.empty() &&
                   ((priorityy(c) < priorityy(st.top())) ||
                    (priorityy(c) == priorityy(st.top()) && c != '^'))){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Remaining operators
    while (!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;
}
