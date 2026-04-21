// implement queue using stack


//approach1: Using two Stacks where push operation is O(N)
class StackQueue {
private:
    stack <int> st1, st2;

public: 
    // Empty Constructor
    StackQueue () {
        
    }
    
    // Method to push elements in the queue, t.c- O(n) s.c- O(n)
    void push(int x) {
        // Pop out elements from the first stack and push on top of the second stack
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x); // Insert the desired element
        
        // Pop out elements from the second stack and push back on top of the first stack
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Method to pop element from the queue, t.c- O(1) s.c- O(n)
    int pop() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Get the top element
        int topElement = st1.top();
        st1.pop(); // Perform the pop operation
        
        return topElement; // Return the popped value
    }
    
    // Method to get the front element from the queue, t.c- O(1) s.c- O(n)
    int peek() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        return st1.top();
    }
    
    // Method to find whether the queue is empty, t.c- O(1) s.c- O(n)
    bool isEmpty() {
        return st1.empty();
    }
};



//approach2: Using Two Stacks Where Push Operation is O(1)
class StackQueue {
  public:
    stack<int> input, output;

    // Initialize your data structure here
    StackQueue() {}

    // Push element x to the back of queue, t.c- O(1) s.c- O(n)
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element, t.c- O(n) s.c- O(n)
    int pop() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element, t.c- O(n) s.c- O(n)
    int peek() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }
        return output.top();
    }

    // Returns true if the queue is empty, false otherwise, t.c- O(n) s.c- O(n)
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};