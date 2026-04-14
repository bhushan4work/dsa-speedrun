//statement- given the head of LL, return reversed LL


//(brute) t.c- O(n)  s.c- O(n) 
ListNode *reverseList(ListNode *head){
    stack<int> st;
    ListNode *temp = head;
    
    while (temp != nullptr){
        st.push(temp->val);
        temp = temp->next;
    }
    
    temp = head;   // Reset temp back to head
    
    // Reassign values from stack in reverse order
    while (temp != nullptr){
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}


//(optimal) t.c- O(n)  s.c- O(1)  
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* temp = head;
    
    while (temp != nullptr) {
        ListNode* front = temp->next;  // Save the next node
        
        temp->next = prev;  // Reverse the curr node's pointer
        prev = temp; // Move prev to current node
        
        temp = front; // Move to the next node
    }
    return prev; // Return new head (last node becomes first)
}


//(optimal) -recursive t.c- O(n)  s.c- O(n)  
ListNode *reverseList(ListNode *head){
    ListNode *prev = nullptr;
    ListNode *temp = head;

    while (temp != nullptr){
        ListNode *front = temp->next;  //save next of curr node

        temp->next = prev; // Reverse the current node's pointer
        prev = temp; // Move prev to current node

        temp = front; // Move curr node to the next node
    }
    return prev; // Return new head (last node becomes first)
}

ListNode *reverseList(ListNode *head){
    // Base case: if list is empty or has one node
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *newHead = reverseList(head->next); // Recursively reverse the rest of the list

    ListNode *front = head->next;  // //save next of curr node

    front->next = head; // Make the next node point back to current
    head->next = nullptr;  // Break the current node's forward link

    return newHead; // Return the new head of the reversed list
}