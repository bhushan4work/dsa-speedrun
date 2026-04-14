// statement- given the head of LL & an integer k, find out whether the k is present in LL or not. Return true if present else false

// (optimal) t.c- O(n)  s.c- O(1)
int searchInLinkedList(Node<int>* head, int k) {
    Node<int>* current = head; // Pointer to traverse the list

    while (current != nullptr){
        if (current->data == k){ // Check if current node matches key
            return 1; // Return true if found
        }
        current = current->next; // Move to next node
    }
    return 0; // Return false if not found
}