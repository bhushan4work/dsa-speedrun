//statement- Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).


//method1(brute) -using recursion t.c- O(n^2)  s.c- O(n)
void insert(stack<int>& s, int temp) {
    if (s.empty() || s.top() <= temp) { // Base case: if stack is empty or temp is larger than the top element
        s.push(temp);
        return;
    }
    
    // Otherwise, pop the top element & recursively insert
    int val = s.top();
    s.pop();
    insert(s, temp);
    
    s.push(val); // Push the popped element back
}

void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        
        sortStack(s);
        
        insert(s, temp);
    }
}