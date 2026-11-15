//statement-  Design stack that supports below operations in const time: push, pop, top, & retrieving min element
// MinStack(): Initializes stack obj
// void push(int val): Pushes element val onto stack
// void pop(): removes the element on the top of the stack.
// int top(): gets the top element of the stack.
// int getMin(): retrieves the minimum element in the stack.



//(brute) t.c- O(1)  s.c- O(n) 
class MinStack {
private:
    stack <pair<int,int>> st;
    
public:
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        if(st.empty()) {
            st.push( {value, value} ); // Push curr value as min
            return;
        }
        
        int mini = min(getMin(), value); // Update curr min
        st.push({value, mini}); // Add pair to stack
    }
    
    // Method to pop a value from stack
    void pop() {
        st.pop();  // Add pair to stack
    }
    
    // Method to get the top of stack
    int top() {
        return st.top().first; // Return top value
    }
    
    // Method to get the minimum in stack
    int getMin() {
        return st.top().second; // Return the min
    }
};


//(optimal) t.c- O(1)  s.c- O(n)  
class MinStack {
private:
    stack <int> st;
    int mini; // To store min value 
    
public:
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        if(st.empty()) {
            mini = value; //Update min value
            st.push( value ); // Push curr value as min
            return;
        }
        
        if(value > mini) { // If value is greater than min
            st.push(value);
        }
        else {
            st.push(2 * value - mini); // Add modified value to stack
            mini = value; // Update min
        }
    }
    
    // Method to pop a value from stack
    void pop() {
        if(st.empty()) return; // Base case
        
        int x = st.top(); // Get top
        st.pop(); // Pop operation
        
        if(x < mini) { // If the modified value was added to stack
            mini = 2 * mini - x; // Update min
        }
    }
    
    // Method to get the top of stack
    int top() {
        if(st.empty()) return -1; // Base case
        
        int x = st.top(); // Get top
        if(mini < x) return x; // Returnn top if min is less than top
        
        return mini; //Otherwise return mini
    }
    
    // Method to get the minimum in stack
    int getMin() {
        return mini;
    }
};
