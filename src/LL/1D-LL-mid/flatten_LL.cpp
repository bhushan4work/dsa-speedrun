//statement- Given a special LL containing n head nodes where every node in LL contains 2 ptr: ‘Next’ points to next node, ‘Child’ ptr to LL where curr node is head
//           Each of these child LLs is in sorted order & connected by 'child' ptr. Flatten this LL such that all nodes appear in single sorted layer connected by 'child' ptr & return head of modified list


//(brute) t.c- O(nlogn)  s.c- O(n)
Node* flatten(Node* root) {
    vector<int> values; // Store every node value from all bottom chains.
    Node* horizontal = root; // Traverse each vertical linked list.
    while (horizontal != nullptr) {
        Node* vertical = horizontal;
        while (vertical != nullptr) { // Collect values from current bottom chain.
            values.push_back(vertical->data);
            vertical = vertical->bottom;
        }

        horizontal = horizontal->next; // Move to next vertical linked list.
    }

    sort(values.begin(), values.end()); // Sort all collected values.

    Node dummy(0); // Dummy node simplifies building final bottom chain.
    Node* tail = &dummy;
    for (int value : values) { // Create a new sorted bottom linked list.
        tail->bottom = new Node(value);
        tail = tail->bottom; // Advance tail after attaching new node.
    }

    return dummy.bottom; // Return head of flattened linked list.
}



//(optimal) t.c- O(nlogk)  s.c- O(k)
Node* flatten(Node* root) {
    auto compare = [](Node* first, Node* second) { // Compare nodes by value so smallest node stays on top.
        return first->data > second->data;
    };

    priority_queue<Node*, vector<Node*>, decltype(compare)> minHeap(compare); // Store current smallest node from every vertical list.
    Node* horizontal = root; // Traverse horizontal chain.
    while (horizontal != nullptr) {
        minHeap.push(horizontal); // Add head of current vertical list to heap.
        horizontal = horizontal->next; // Move to next vertical list.
    }

    Node dummy(0); // Dummy node simplifies construction of flattened list.
    Node* tail = &dummy;
    while (!minHeap.empty()) { // Process nodes until every vertical list is exhausted.
        Node* smallest = minHeap.top(); // Extract smallest available node.
        minHeap.pop();
        if (smallest->bottom != nullptr) { // Add next node from same vertical chain.
            minHeap.push(smallest->bottom);
        }
        
        tail->bottom = smallest; // Attach smallest node to flattened bottom chain.
        tail = tail->bottom; // Move tail to newly attached node.
        tail->next = nullptr; // Remove old horizontal connection.
    }

    return dummy.bottom; // Return head of flattened linked list.
}