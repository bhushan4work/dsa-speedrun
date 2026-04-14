// statement- Given a LL & integer k, task is to delete kth node from end of LL & print updated LL

// (brute) t.c- O(n + n-k)  s.c- O(1)
Node *deleteNthNodeFromEnd(Node *head, int k){
    if (head == nullptr){ // If list is empty, return NULL
        return nullptr;
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr){ // get size of LL
        cnt++;
        temp = temp->next;
    }

    // If k equals the total number of nodes, delete the head
    if (cnt == k){
        Node *newHead = head->next;
        delete head; // free memory
        return newHead;
    }

    int ans = cnt - k; //this is pos before kth term
    temp = head;
    // Traverse to the node just before the one to delete
    while (temp != nullptr){
        ans--;
        if (res == 0){
            break;
        }
        temp = temp->next;
    }

    Node *delNode = temp->next; //store the node to be deleted in a var
    temp->next = temp->next->next; //change links
    delete delNode; // free memory

    return head;
}


// (optimal) -using tortoise & hare algo  t.c- O(n)  s.c- O(1)
Node *deleteNthNodeFromEnd(Node *head, int k){
    // Initialize slow and fast pointers at head
    Node *slow = head;
    Node *fast = head;

    // Move fastptr k steps ahead to create a gap
    for (int i = 0; i < k; i++){
        if(fast == nullptr) return head; //checks if k > length
        fast = fast->next;
    }
    if (fast == nullptr) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }

    // Move both pointers by 1 until fast reaches end
    while (fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    // Slow is now at node before target
    Node *delNode = slow->next; //store the node to be deleted in a var
    slow->next = slow->next->next; //change links
    delete delNode; // free memory

    return head;
}