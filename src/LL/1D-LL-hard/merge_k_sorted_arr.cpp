// statement- given an arr of k linked-lists lists, each LL is sorted. Merge all LL into 1 sorted LL & return it


// (brute) t.c- O(nlogn)  s.c- O(n)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> nodes; // Array to store all node values.
    for (ListNode* head : lists) { // Traverse through all linked lists.
        ListNode* curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr->val); // Push each value into array.
            curr = curr->next;
        }
    }

    sort(nodes.begin(), nodes.end()); // Sort all collected values in ascending order.

    ListNode* dummy = new ListNode(-1); // Dummy node to simplify list creation.
    ListNode* curr = dummy;
    for (int val : nodes) { // Iterate through sorted array.
        curr->next = new ListNode(val); // Create new nodes with sorted values.
        curr = curr->next;
    }

    return dummy->next; // Return head of newly constructed sorted list.
}



// (better) t.c- O(k * n)  s.c- O(1)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    while (l1 != nullptr && l2 != nullptr) { // Standard merge routine for two sorted lists.
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        }
        else {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    if (l1 != nullptr) { // Attach remaining elements of l1 if any.
        curr->next = l1;
    }
    else { // Attach remaining elements of l2 if any.
        curr->next = l2;
    }

    return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) { // Edge case for empty lists array.
        return nullptr;
    }
    
    ListNode* head = lists[0]; // Start with first list as base.
    for (int i = 1; i < lists.size(); i++) { // Merge accumulated list with next list sequentially.
        head = mergeTwoLists(head, lists[i]);
    }

    return head;
}



// (optimal) t.c- O(nlogk)  s.c- O(k)
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap comparator based on node values.
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for (ListNode* head : lists) { // Push head of each non-empty list into min-heap.
        if (head != nullptr) {
            pq.push(head);
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    while (!pq.empty()) { // Process until heap is empty.
        ListNode* minNode = pq.top(); // Extract node with smallest value.
        pq.pop();
        curr->next = minNode; // Attach it to our merged list.
        curr = curr->next;
        if (minNode->next != nullptr) { // If extracted node has a next node, push it to heap.
            pq.push(minNode->next);
        }
    }

    return dummy->next;
}