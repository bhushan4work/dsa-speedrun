//statement- task is to reverse a DLL & return the head of the modified DLL


//(brute) t.c- O(2n)  s.c- O(n)
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) { // If list is empty or has only one node, return as-is
        return head;
    }

    stack<int> st; // Stack to store node data
    Node* temp = head;
    
    while (temp != nullptr) { // Push all node values to stack
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head; // Reset temp to head for second pass

    while (temp != nullptr) { // Replace node values with those from stack
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}


//(optimal) t.c- O(n)  s.c- O(1)
Node* reverseDLL(Node* head) {
    // If list is empty or has one node, nothing to reverse
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* curr = head; // Pointer to track the current node

    while (curr != nullptr) {
        // Swap next and back pointers of current node
        Node* temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;

        head = curr;   // update head to curr node (this will become the new head after reversal)
        curr = temp;   // move to next node in original list (stored earlier in temp)
    }
    return head;
}
