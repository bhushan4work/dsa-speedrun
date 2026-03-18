// statement- given the head of LL, delete middle node of LL & return modified head. if LL has even no of nodes, delete second middle node


// method1(brute) t.c- O(n + n\2)  s.c- O(1)
Node *deleteMiddle(Node *head){
    Node *temp = head;
    int n = 0; // variable to hold length of LL
    while (temp != nullptr){ // Loop to count length of LL
        n++;
        temp = temp->next;
    }

    int mid = n / 2; // middle node pos
    temp = head; // Reset temp node to head of LL
    while (temp != nullptr){ // Loop to get pos before middle node
        mid--;

        //now we point to the node just before middle
        if (mid == 0){
            Node *middle = temp->next; // Create a pointer to middle node
            temp->next = temp->next->next; // Adjust pointers to skip middle node
            delete middle; // Free the memory

            break; // Exit loop after deleting middle
        }
        temp = temp->next;
    }
    return head;
}


// method2(optimal) t.c- O(n\2)  s.c- O(1)
Node *deleteMiddle(Node *head){
    if (head == nullptr || head->next == nullptr){ // If list has only one node, delete it
        return nullptr;
    }
    
    Node *slow = head; // Initialize slowptr to head
    Node *fast = head->next->next; // Initialize fastptr 2steps ahead (as we point to 1pos before mid)

    // Traverse until fast && fast->next reaches nullptr
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    //now we point to the node just before the mid

    //Node *middle = slow->next; // Pointer to middle node 
    slow->next = slow->next->next; // Adjust pointers to skip middle node
    //delete middle; //free the memory

    return head;
}