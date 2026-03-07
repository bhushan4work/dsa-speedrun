//statement- delete 1st node(head)
//method1(optimal) t.c- O(1)  s.c- O(1)  
Node *delete1st(Node* head){
    if(head == nullptr || head->next == nullptr ) return nullptr; //edge case check for list of size <= 1

    Node* prev = head; //store head in 'prev'
    head = head->next; //move head forward 
    head->back = nullptr;  // since head is moved forward, its backptr should be null
    prev->next = nullptr; //disconnect old 1st node from the list
    delete prev; //delete the 1st node in list
    return head; 
}


//statement- delete last node(tail)
//method1(optimal) t.c- O(n)  s.c- O(1)  
Node *deleteLast(Node* head){
    if(head == nullptr || head->next == nullptr ) return nullptr; //edge case check for list of size <= 1

    Node* tail = head;
    //we loop until we reach the last position in list
    while(tail->next != nullptr){ 
        tail = tail->next;
    }
    //once the loop is over, we get last position in list
    Node* prev = tail->back //store last 2nd position in 'prev' node
    prev->next = nullptr; //disconnect 2nd last node from last node
    tail->back = nullptr; //remove backward linking of last node
    delete tail;
    return head;
}


//statement- delete node at kth position (0 based indexing is used for k)
//method1(optimal) t.c- O(n)  s.c- O(1)
Node* deleteNode(Node* head, int k){
    if(head == nullptr) return nullptr; // If list is empty

    int cnt = 0; //for 1 based indexing just change this cnt=1
    Node* temp = head;
    // Move to k-th node
    while(temp != nullptr){
        temp = temp->next;
        cnt++;
        if(cnt == k) break;
    }

    // If k is out of range
    if(temp == nullptr) return head;

    Node* prev = temp->back; //store temp's backptr in 'prev'
    Node* front = temp->next; //store temp's frontptr in 'front'

    if(prev == nullptr && front == nullptr){ // Case 1: only one node exists
        delete temp;
        return nullptr;
    }
    if(prev == nullptr){ // Case 2: first node
        head = head->next;
        head->back = nullptr;
        delete temp;
        return head;
    }
    if(front == nullptr){ // Case 3: last node
        prev->next = nullptr;
        delete temp;
        return head;
    }
    // Case 4: middle node
    prev->next = front; //points prev to 1 place ahead of k-node
    front->back = prev; //points front to 1 place behind of k-node
    delete temp;
    return head;
}


//statement- delete a specific node of given value from list (head is given)
//method1(optimal) t.c- O(n)  s.c- O(1) 
Node* deleteElement(Node* head, Node val){
    if (head == nullptr) return nullptr; //checks if list is empty
    
    Node* prev = val->back; //store val's backptr in 'prev'
    Node* front = val->next; //store val's frontptr in 'front'

    // If need to delete head
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    prev->next = front; //points prev to 1 place ahead of k-node
    front->back = prev; //points front to 1 place behind of k-node

    //remove linking of val with front & back
    val->next = nullptr;
    val->back = nullptr;
    delete val;

    return head;
}