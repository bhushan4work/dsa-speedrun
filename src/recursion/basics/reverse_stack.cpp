//statement- You are given a stack st[]. You have to reverse the stack

// reverseStack([1,2,3]) → pop 3 (store), call reverseStack([1,2])
// reverseStack([1,2]) → pop 2 (store), call reverseStack([1])
// reverseStack([1]) → pop 1 (store), call reverseStack([])
// reverseStack([]) → base case → return

// → insertAtBottom([], 1) → [1]
// → insertAtBottom([1], 2) → pop 1 → [] → push 2 → push 1 → [2,1]
// → insertAtBottom([2,1], 3) → pop 1,2 → [] → push 3 → push 2 → push 1 → [3,2,1]


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