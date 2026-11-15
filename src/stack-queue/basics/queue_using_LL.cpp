// implement queue using linkedlist
//t.c- O(1) s.c- O(n)


struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

// Structure to represent stack
class LinkedListQueue {
private:
    Node *start; // Start of the queue
    Node *end; // End of the queue
    int size; // Size of the queue

public:
    // Constructor
    LinkedListQueue() {
        start = end = NULL;
        size = 0;
    }

    // Method to push an element in the queue
    void push(int x) {
        Node *element = new Node(x);
        
        if(start == NULL) { // If it is the first element being pushed
            start = end = element; // Initialise the pointers
        }
        else {
            end->next = element; // Updating the pointers
            end = element; // Updating the end
        }
        size++;
    }

    // Method to pop an element from the queue
    int pop() {
        if (start == NULL) {
            return -1; // Pop operation cannot be performed
        }
        
        int value = start->val; // Get the front value
        Node *temp = start; // Store the front temporarily
        start = start->next; // Update front to next node
        delete temp; // Delete old front node
        size--; // Decrement size
        
        return value; // Return data
    }
    
    // Method to get the front element in the queue
    int peek() {
        if (start == NULL) {
            return -1; // Top element cannot be accessed
        }
        return start->val; // Return the top
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }
};
