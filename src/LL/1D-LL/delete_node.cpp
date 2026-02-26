//statement- delete 1st node(head)
//method1(optimal) t.c- O(1)  s.c- O(1)  
Node *deleteLast(Node* head){
    if(head == nullptr ) return nullptr; //checks if list is empty

    Node* temp = head;
    head = head->next;
    delete temp;
    return head; 
}


//statement- delete last node(tail)
//method1(optimal) t.c- O(n)  s.c- O(1)  
Node *deleteLast(Node* head){
    if(head == nullptr || head->next == nullptr ) return nullptr; //edge case check for list of size <= 1
    Node* temp = head;
    //we loop until we get last 2nd position in list
    while(temp->next->next != nullptr){ 
        temp = temp->next;
    }
    //once the loop is over, we get last 2nd position in list
    delete temp->next; //so we delete val next to the last second
    temp->next = nullptr; //give a nullptr to the val removed
    return head; 
}


//statement- delete node at kth position
//method1(optimal) t.c- O(n)  s.c- O(1)
Node* deleteNode(Node* head, int k){
    if (head == nullptr) return nullptr; //checks if list is empty
    
    
    // If need to delete head (k = 0 because 0-based indexing)
    if (k == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* temp = head;
    Node* prev = nullptr; //to remember past prev value
    int cnt = 0;
    // Go to the node just before the k-th node
    while (temp != nullptr && cnt < k - 1) {
        if(cnt == k){
            prev->next = prev->next->next; //move pointer to 1 place forward of temp
            delete temp;
            break;
        }
        prev = temp; //prev takes curr temp's place 
        temp = temp->next; //curr temp takes next forward place
        cnt++; //as we using 0-based indexing in que we cnt afterwards instead of cnting before if statement
    }

    // If k is out of range, do nothing
    if (temp == nullptr || temp->next == nullptr) {
        return head;
    }

    return head;
}


//statement- delete a specific node of given value from list (head is given)
//method1(optimal) t.c- O(n)  s.c- O(1) 
Node* deleteElement(Node* head, int val){
    if (head == nullptr) return nullptr; //checks if list is empty
    
    // If need to delete head
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* temp = head;
    Node* prev = nullptr;  //to remember past prev value
    // Go to the node just before the k-th node
    while (temp != nullptr) {
        if(temp->data == val){
            prev->next = prev->next->next; //
            delete temp;
            break;
        }
        prev = temp; //prev takes curr temp's place 
        temp = temp->next; //curr temp takes next forward place
    }
    
    // If value is out of range, do nothing
    if (temp == nullptr || temp->next == nullptr) {
        return head;
    }
    
    return head;
}


//statement- delete a specific node of given value from list (head not given)
//method1(optimal) t.c- O(1)  s.c- O(1) 
void deleteNode(Node* node) {
    Node* temp = node->next;      // get next node
    node->data = temp->data;      // copy its data into current node
    node->next = temp->next;      // skip the next node
    delete temp;                  // delete the skipped node
}