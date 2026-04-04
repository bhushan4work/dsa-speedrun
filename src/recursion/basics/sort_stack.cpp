//statement- Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

// sortStack([3,1,4,2]) → pop 2 (store), call sortStack([3,1,4])
// sortStack([3,1,4]) → pop 4 (store), call sortStack([3,1])
// sortStack([3,1]) → pop 1 (store), call sortStack([3])
// sortStack([3]) → pop 3 (store), call sortStack([])
// sortStack([]) → base case → return

// → insert([], 3) → [3]
// → insert([3], 1) → pop 3 → [] → push 1 → push 3 → [1,3]
// → insert([1,3], 4) → push directly → [1,3,4]
// → insert([1,3,4], 2) → pop 4,3 → [1] → push 2 → push 3 → push 4 → [1,2,3,4]


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