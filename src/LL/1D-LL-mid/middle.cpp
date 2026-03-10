//statement- head of LL is given, determine the middle node of LL. if LL has even number of nodes, return second middle node


//method1(brute) t.c- O(n + n\2)  s.c- O(1) 
Node *findMiddle(Node *head) {
    if (head == nullptr || head->next == nullptr) { // If the list is empty or has only 1 element, return the head as it's the middle
        return head;
    }

    Node* temp = head; 
    int count = 0;

    // returns length of LL
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    int mid = (count / 2) + 1;
    temp = head; //assign temp as head of list again

    while (temp != nullptr) {
        mid = mid - 1;
        
        if (mid == 0){ // Check if middle position is reached
            break;
        }
        temp = temp->next; // Move temp ahead
    }
    return temp;
}


//method2(optimal)- using tortoise & hare algo t.c- O(n\2)  s.c- O(1)
Node *findMiddle(Node *head) {
    Node *slow = head;   // Initialize slow ptr to head
    Node *fast = head;   // Initialize fast ptr to head

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;  // Move slow-ptr by 1 step
        fast = fast->next->next;   // Move fast-ptr by 2 steps
    }
    // after half traversal in list, slow will point to middle, & fast will point to lastNode or null
    return slow; 
}