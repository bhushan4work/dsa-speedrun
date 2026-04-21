// implement stack using array
//t.c- O(1) s.c- O(n)


class ArrayStack {
private:
    int* stackArray; // Array to hold elements
    int capacity; // Maximum capacity
    int topIndex;   // Index of top element  

public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1; 
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return stackArray[topIndex--];
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

   /* Returns true if the 
   stack is empty, false otherwise*/
    bool isEmpty() {
        return topIndex == -1;
    }
};