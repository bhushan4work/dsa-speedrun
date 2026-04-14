//statement- task is to add 1 to the value represented by LL & return head of LL containing final value


//(brute) t.c- O(n + n + n)  s.c- O(1)
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverseList(head);

    Node* curr = head;
    int carry = 1;

    while (curr != nullptr) {
        curr->data += carry; 

        if (curr->data < 10) {
            carry = 0;
            break;
        }
        else{
            curr->data = 0;
            carry = 1;
        }

        // if last node & still carry exists we make new node
        if (curr->next == nullptr) {
            curr->next = new Node(1);
            carry = 0;
            break;
        }
        curr = curr->next;
    }
    return reverseList(head);
}


//(optimal) using recursion t.c- O(n)  s.c- O(n) for storing recursive stack
int addOneUtil(Node* temp) {
    if (temp == nullptr) return 1; //Base case: when reaching beyond last node, return carry=1
        
    int carry = addOneUtil(temp->next); // Recurse to the end

    temp->data += carry;
    if (temp->data < 10) return 0; //return 0 as carry
    temp->data = 0;
    return 1; // Return new carry as 1 
}

Node* addOne(Node* head) {
    int carry = addOneUtil(head); // Perform recursive addition

    // If carry remains after processing the head, create a new head node
    if (carry) {
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    return head;
}