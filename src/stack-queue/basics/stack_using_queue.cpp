// implement stack using queue


class QueueStack {
    queue<int> q;

public:
    // Method to push element in the stack, t.c- O(n) s.c- O(k)
    void push(int x) {
        int s = q.size(); 
        q.push(x);  // Add element

        // Move elements before new element to back
        for (int i = 0; i < s; i++) {
            q.push(q.front()); 
            q.pop(); 
        }
    }

    // Method to pop element from stack, t.c- O(1) s.c- O(k)
    int pop() {
        int n = q.front();  // Get front element 
        q.pop();  // Remove front element
        return n;  // Return removed element
    }

    // Method to return the top of stack, t.c- O(1) s.c- O(k)
    int top() {
        return q.front(); // Return front element
    }

    // Method to check if the stack is empty, t.c- O(1) s.c- O(k)
    bool isEmpty() {
        return q.empty(); 
    }
};