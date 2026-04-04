//statement- You are given a stack st[]. You have to reverse the stack


//method1(brute) -using recursion t.c- O(n^2)  s.c- O(n)
void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) { // If stack is empty, push the value
        st.push(val);
        return;
    }

    // Pop the top element
    int topVal = st.top();
    st.pop();

    insertAtBottom(st, val); // Recurse for the rest of the stack

    st.push(topVal); // Push the popped element back
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return; // Base case: If stack is empty, return

    // Pop the top element
    int topVal = st.top();
    st.pop();

    reverseStack(st); // Recursively reverse the remaining stack

    insertAtBottom(st, topVal); // Insert the popped element at the bottom
}