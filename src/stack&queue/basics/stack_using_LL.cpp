// implement stack using linkedlist
//t.c- O(1) s.c- O(n)


struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node *head; // Top of Stack
    int size; // Size

public:
    // Constructor
    LinkedListStack() {
        head = NULL;
        size = 0;
    }

    // Method to push an element onto the stack
    void push(int x) {
        Node *element = new Node(x);
        
        element->next = head; // Updating the pointers
        head = element; // Updating the top
        size++;
    }

    // Method to pop an element from the stack
    int pop() {
        // If the stack is empty
        if (head == NULL) {
            return -1; // Pop operation cannot be performed
        }
        
        int value = head->val; // Get the top value
        Node *temp = head; // Store the top temporarily
        head = head->next; // Update top to next node
        delete temp; // Delete old top node
        size--; // Decrement size
        
        return value; // Return data
    }
    
    // Method to get the top element of the stack
    int top() {
        if (head == NULL) {
            return -1; // Top element cannot be accessed
        }
        return head->val; // Return the top
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return (size == 0);
    }
};