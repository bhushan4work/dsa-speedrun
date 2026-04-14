//statement- given head of DLL & Key. task is to delete all occurrences of given key if its present & return new DLL


//(optimal) t.c- O(n)  s.c- O(1)
Node* deleteAllOccurrences(Node* head, int key) {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == key) {

            Node* temp = curr;              // store node to be deleted
            Node* prevNode = curr->back;
            Node* nextNode = curr->next;

            // If key is head,move head to next node & remove linking 
            if (curr == head) {
                head = curr->next;
                if (head) head->back = nullptr;
            } 

            if (prevNode) prevNode->next = nextNode;
            if (nextNode) nextNode->back = prevNode;

            curr = curr->next;   // move BEFORE deleting the node
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
