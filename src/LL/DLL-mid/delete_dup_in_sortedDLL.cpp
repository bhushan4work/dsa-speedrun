// statement-  given head of sorted DLL. remove all duplicates in list. return head of modified list

// method1(optimal) t.c- O(n)  s.c- O(1)
Node *removeDuplicates(){
    if (!head) return nullptr; // If list is empty, return null
    Node *current = head;

    while (current != nullptr && current->next != nullptr){
        Node *nextDistinct = current->next;

        // Skip and delete all nodes with the same value as current
        while (nextDistinct != nullptr && nextDistinct->data == current->data){
            Node *duplicateNode = nextDistinct;
            nextDistinct = nextDistinct->next;
            delete duplicateNode; // Free memory of duplicate node
        }

        //here we get nextDistinct->data != current->data so we
        // connect current node to the next distinct node
        current->next = nextDistinct;
        if (nextDistinct != nullptr){ //& if next exist link it back with curr
            nextDistinct->prev = current;
        }
        current = current->next;
    }
    return head;
}
