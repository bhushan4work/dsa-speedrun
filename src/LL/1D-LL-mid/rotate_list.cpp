//statement- Given head of a singly LL, shift elements of LL to right by k places & return head of modified list. Dont change values of nodes, only change links betw nodes


//(brute) t.c- O(n * (k % n))  s.c- O(1) 
ListNode* rotateRight(ListNode* head, int k) { // Rotates the linked list to the right by k places
    if (head == nullptr || head->next == nullptr || k == 0) { // Handle empty list, single node, or zero rotations
        return head;
    }

    int length = 0;
    ListNode* temp = head;
    while (temp != nullptr) { // Calculate total length of the list
        length++;
        temp = temp->next;
    }

    k = k % length; // Remove redundant full cycles
    while (k > 0) { // Rotate the list one node at a time
        ListNode* secondLast = nullptr;
        ListNode* last = head;
        while (last->next != nullptr) { // Traverse to the end of the list
            secondLast = last;
            last = last->next;
        }
        secondLast->next = nullptr; // Move the last node to the front
        last->next = head;
        head = last;
        k--;
    }

    return head;
}



//(optimal) t.c- O(n)  s.c- O(1)
ListNode* rotateRight(ListNode* head, int k) { // Rotates the linked list by k places using a circular connection 
    if (head == nullptr || head->next == nullptr || k == 0) { // Handle empty list, single node, or zero rotations
        return head;
    }

    int length = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) { // Locate the tail node while calculating list length
        tail = tail->next;
        length++;
    }
    k = k % length; // Skip redundant complete rotation cycles
    
    if (k == 0) {
        return head;
    }
    tail->next = head; // Link tail to head to form a temporary circle

    int stepsToNewTail = length - k - 1;
    ListNode* newTail = head;
    for (int step = 0; step < stepsToNewTail; step++) { // Traverse to locate the node that will serve as the new tail
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next; // Pinpoint the new head node next to the new tail
    newTail->next = nullptr; // Break the circular reference to restore linear list structure
    return newHead;
}