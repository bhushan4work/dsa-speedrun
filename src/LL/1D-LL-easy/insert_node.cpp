//statement- insert node at head
//(optimal) t.c- O(1)  s.c- O(1)
Node* insert1st(Node* head, int val){
    Node* newNode = new Node(val);   // create new node
    newNode->next = head;            // point new node to current head
    return newNode;                  // new node becomes head
}

//statement- insert node at tail
//(optimal) t.c- O(n)  s.c- O(1)
Node* insertLast(Node* head, int val) {

    Node* newNode = new Node(val);

    if (head == nullptr) { // If list is empty
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr) { // Traverse until last node
        temp = temp->next;
    }

    temp->next = newNode; // Attach new node at the end

    return head;
}


//statement- insert node at kth position (0 based indexing is used for k)
//(optimal) t.c- O(n)  s.c- O(1)
Node* insertAtK(Node* head, int k, int val) {
    Node* newNode = new Node(val);

    if (k == 0) { // If inserting at head (k = 0)
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int cnt = 0;

    while (temp != nullptr && cnt < k - 1) { // Go to (k-1)th node
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) { // If k is out of range
        return head;
    }
    
    newNode->next = temp->next; // Insert node
    temp->next = newNode;

    return head;
}

//statement- insert node having value x before node of value val (head is given)
//(optimal) t.c- O(n)  s.c- O(1) 
Node* insertBeforeValue(Node* head, int x, int val) {
    if (head == nullptr) return nullptr;

    Node* newNode = new Node(x);

    if (head->data == val) { // Insert before head
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->data == val) {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    return head;
}