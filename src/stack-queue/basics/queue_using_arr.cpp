// implement queue using array
//t.c- O(1) s.c- O(1) 



class ArrayQueue {
    int* arr; // Array to store queue elements
    int start, end; // Indices for start and end of the queue
    int currSize, maxSize; // Current size and maximum size of the queue

public:
    // Constructor
    ArrayQueue() {
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }

    // Method to push an element into the queue
    void push(int x) {
        if (currSize == maxSize) { // Check if the queue is full
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        
        if (end == -1) { // If the queue is empty, initialize start and end
            start = 0;
            end = 0;
        } 
        else {
            end = (end + 1) % maxSize; // Circular increment of end
        }

        arr[end] = x;
        currSize++;
    }

    // Method to pop an element from the queue
    int pop() {
        if (start == -1) { // Check if the queue is empty
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];
        
        if (currSize == 1) { // If the queue has only one element, reset start and end
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % maxSize; // Circular increment of start
        }
        
        currSize--;
        return popped;
    }

    // Method to get the front element of the queue
    int peek() {
        if (start == -1) { // Check if the queue is empty
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    // Method to determine whether the queue is empty
    bool isEmpty() {
        return (currSize == 0);
    }
};