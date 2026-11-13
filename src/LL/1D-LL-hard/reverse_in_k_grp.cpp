// statement- Given head of a singly LL containing integers, reverse nodes of list in grps of k & return head of modified list. If no of nodes is not multiple of k,
//            then remaining nodes at end should be kept as is & not reversed. dont change values of nodes, only change links between nodes


// (brute) t.c- O(n)  s.c- O(k)
Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k <= 1) { // Base case: No transformation required for empty lists or groups of 1
        return head;
    }

    Node* dummy = new Node(0);
    Node* tail = dummy;
    Node* current = head;

    while (current != nullptr) {
        stack<Node*> st;
        int count = 0;
        while (current != nullptr && count < k) { // Collect up to k nodes into the stack container
            st.push(current);
            current = current->next;
            count++;
        }

        while (!st.empty()) { // Pop nodes from the stack to reconstruct the group in reverse order
            tail->next = st.top();
            st.pop();
            tail = tail->next;
        }
    }

    tail->next = nullptr; // Set the final pointer to null to avoid circular list configurations
    return dummy->next;
}



// (better) t.c- O(n)  s.c- O(n / k)
Node* reverseKGroup(Node* head, int k) { // Reverse nodes of a linked list in groups of size k recursively.
    if (head == nullptr || k <= 1) {
        return head;
    }

    Node* temp = head;
    for (int i = 0; i < k; i++) { // Check whether a complete group of k nodes exists.
        if (temp == nullptr) {
            return head;
        }
        temp = temp->next;
    }

    Node* previous = nullptr;
    Node* current = head;
    for (int i = 0; i < k; i++) { // Reverse the current group of k nodes.
        Node* front = current->next;
        current->next = previous;
        previous = current;
        current = front;
    }

    head->next = reverseKGroup(current, k); // Connect the current reversed group with the remaining groups.
    return previous;
}



// (optimal) t.c- O(n)  s.c- O(1)
Node* getKthNode(Node* current, int k) { // Return the kth node starting from a given node.
    while (current != nullptr && k > 1) {
        current = current->next;
        k--;
    }

    return current;
}

Node* reverseList(Node* head) { // Reverse a detached linked list segment.
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* front = current->next;
        current->next = previous;
        previous = current;
        current = front;
    }

    return previous;
}

Node* reverseKGroup(Node* head, int k) { // Reverse nodes of a linked list in groups of size k in-place.
    if (head == nullptr || k <= 1) {
        return head;
    }

    Node* temp = head;
    Node* previousLast = nullptr;
    while (temp != nullptr) {
        Node* kthNode = getKthNode(temp, k); // Locate the kth node of the current group.
        if (kthNode == nullptr) {
            if (previousLast != nullptr) {
                previousLast->next = temp;
            }

            break;
        }

        Node* nextNode = kthNode->next; // Store the next group head before detaching the segment.
        kthNode->next = nullptr;
        reverseList(temp); // Reverse the detached group.
        if (temp == head) {
            head = kthNode;
        }
        else {
            previousLast->next = kthNode;
        }

        previousLast = temp; // Connect the reversed group tail with the next group.
        temp = nextNode;
    }

    return head;
}