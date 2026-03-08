// DLL insertion is done in 2 ways- before & after in each type of que below, 'after' is what we did in 1D-LL, so we only do 'before' here


// statement- insert node before head
// method1(optimal) t.c- O(1)  s.c- O(1)
Node *insertBeforeHead(Node *head, int val){
    if (head == nullptr){ // If list is empty
        return new Node(val, nullptr, nullptr);
    }

    Node *newHead = new Node(val, head, nullptr); // (val, nextptr, backptr)
    head->back = newHead                          // point backptr of head to newHead
    return newHead;
}


// statement- insert node before tail
// method1(optimal) t.c- O(n)  s.c- O(1)
Node *insertBeforeLast(Node *head, int val){
    if (head == nullptr){ // If list is empty
        return new Node(val, nullptr, nullptr);
    }

    if (head->next == nullptr){ // if only 1-element exists i.e insert before head condn
        Node *newHead = new Node(val, head, nullptr); // (val, nextptr, backptr)
        head->back = newHead                          // point backptr of head to newHead
        return newHead;
    }

    Node* tail = head;
    while (tail->next != nullptr){ // Traverse until last node
        tail = tail->next;
    }
 
    Node* prev = tail->back;
    Node *newNode = new Node(val, tail, prev); //(val, nextptr, backptr)
    prev->next = newNode;
    tail->back = newNode;

    return head;
}


// statement- insert node at kth position (0 based indexing is used for k)
// method1(optimal) t.c- O(n)  s.c- O(1)
Node *insertBeforeK(Node *head, int k, int val){
    if (head == nullptr){ // If list is empty
        return nullptr;
    }

    if (k == 0){ // If inserting at head (k = 0) for 0-based indexing
        Node *newNode = new Node(val, head, nullptr); // (val, nextptr, backptr)
        head->back = newNode                          // point backptr of head to newHead
        return newNode;
    }

    Node* temp = head;
    int cnt = 0; //for 1-based k indexing change cnt=1 here
    while (temp != nullptr && cnt < k){ // Go to kth node
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) return head;
    
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp ,prev);
    temp->back = newNode; 
    prev->next = newNode;

    return head;
}


// statement- insert node having value x before node of value val (head is given)
// method1(optimal) t.c- O(n)  s.c- O(1)
Node *insertBeforeValue(Node *head, int x, int val){
    if (head == nullptr){ // If list is empty
        return new Node(val, nullptr, nullptr);
    }

    if (head->data == val){ // for insert before head
        Node *newNode = new Node(x, head, nullptr); // (val, nextptr, backptr)
        head->back = newNode;   // point backptr of head to newHead
        return newNode;
    }

    Node *temp = head;
    while (temp != nullptr && temp->data != val){
        temp = temp->next;
    }
    if (temp == nullptr) return head; 

    //now we are at the node having value 'val' & we insert newNode before it 
    Node* prev = temp->back;
    Node* newNode = new Node(x,temp ,prev);  // (val, nextptr, backptr)
    temp->back = newNode;
    prev->next = newNode;

    return head;
}