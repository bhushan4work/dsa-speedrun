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

//(optimal) t.c- O()  s.c- O(1)
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPriority(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string infix){
    stack<char> st;
    string output;

    for (char c : infix){

        if (isalnum(c)){
            output += c;
        }

        else if (c == '('){
            st.push(c);
        }

        else if (c == ')'){
            while (!st.empty() && st.top() != '('){
                output += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        else{ // operator
            while (!st.empty() &&
                   ((getPriority(c) < getPriority(st.top())) ||
                    (getPriority(c) == getPriority(st.top()) && c != '^'))){
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty() &&
       ((getPriority(c) < getPriority(st.top())) ||
        (getPriority(c) == getPriority(st.top()) && c == '^'))) {
        output += st.top();
        st.pop();
    }

    return output;
}

string infixToPrefix(string infix){
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++){
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}