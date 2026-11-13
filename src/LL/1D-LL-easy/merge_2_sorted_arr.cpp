// statement- Given heads of 2 LL, list1 and list2, where each LL has its elements sorted, merge them into a 1 sorted LL & return head of merged LL


// (brute) t.c- O(n+m * log(n + m))  s.c- O(n + m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // Function to merge sorted lists using value collection.
    vector<int> values;
    ListNode* current = list1;
    while (current != nullptr) { // Collect values from first sorted list.
        values.push_back(current->data);
        current = current->next;
    }

    current = list2;
    while (current != nullptr) { // Collect values from second sorted list.
        values.push_back(current->data);
        current = current->next;
    }

    sort(values.begin(), values.end());

    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int value : values) { // Build merged linked list from sorted values.
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummy.next;
}



// (better) t.c- O(n + m)  s.c- O(n + m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // Function to merge sorted lists using recursion.
    if (list1 == nullptr) {
        return list2;
    }
    
    if (list2 == nullptr) {
        return list1;
    }

    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2); // Attach merged suffix after first list node.
        return list1;
    }

    list2->next = mergeTwoLists(list1, list2->next); // Attach merged suffix after second list node.
    return list2;
}



// (optimal) t.c- O(m + n)  s.c- O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // Function to merge sorted lists by relinking nodes.
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) { // Link smaller current node from first list.
            tail->next = list1;
            list1 = list1->next;
        }
        else { // Link smaller current node from second list.
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    tail->next = (list1 != nullptr) ? list1 : list2; // Attach remaining suffix from non-empty list.
    return dummy.next;
}