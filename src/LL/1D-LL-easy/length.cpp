// statement-  given the head of a LL, print length of the LL

// (optimal) t.c- O(n)  s.c- O(1)
int lengthOfLinkedList(Node *head){
    int count = 0;

    Node *temp = head; // Initialize a temp pointer to head

    while (temp != nullptr){
        count++; // Increment count for each node
        temp = temp->next; // Move to the next node
    }
    return count;
}