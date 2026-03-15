//statement- given the head of LL. check whether LL values form a palindrome or not. return true if it forms palindrome else false


//method1(brute) t.c- O(n)  s.c- O(n) 
bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;

    while (temp != NULL) {
        st.push(temp->data); // Push data from curr node onto the stack
        temp = temp->next;   // Move to next node
    }

    temp = head; // Reset the temp ptr back to head of LL

    // Compare values by popping from the stack and checking against LL nodes
    while (temp != NULL) {
        if (temp->data != st.top()) {
            return false; // If values don't match, it's not a palindrome
        }
        st.pop();           // Pop the value from the stack
        temp = temp->next;  // Move to the next node in the linked list
    }
    return true; // If all values match, it's a palindrome
}


//method2(optimal) -using tortoise & hare algo t.c- O(n)  s.c- O(1)
Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) { // Check if the list is empty or has only one node
        return head; 
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    Node* front = head->next;  // Store next node in 'front' to reverse the link
    front->next = head;   // Update 'next' ptr of 'front' to point to the curr head
    head->next = NULL; // Set the 'next' ptr of the curr head to null to break original link

    return newHead;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {    // Check if LL is empty or has only one node
        return true;  
    }

    Node* slow = head;
    Node* fast = head;

    // Traverse the LL to find the middle
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps
    }

    // Reverse 2nd half of LL starting from middle (in 1D-LL we move in 1 direc & so for comparing we need to reverse 2nd half)
    Node* newHead = reverseLinkedList(slow->next);

    Node* first = head; // Pointer to the first half
    Node* second = newHead; // Pointer to the reversed second half

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->data != second->data) {   // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }
    reverseLinkedList(newHead); // Reverse the second half back to its original state
    return true; // List is palindrome
}
