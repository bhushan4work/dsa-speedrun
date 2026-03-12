// statement- Given the head of LL that may contain a cycle, return the starting point of that cycle. If no cycle exists return null

// method1(brute) t.c- O(n * logn)  s.c- O(n)
ListNode *detectCycle(ListNode *head){
    unordered_set<ListNode *> visited;

    while (head != nullptr){
        if (visited.find(head) != visited.end()){ // If current node is already in set, it's the start of loop
            return head;
        }
        visited.insert(head); // else, insert current node into set

        head = head->next; // Move to the next node
    }
    return nullptr; // If loop not found, return nullptr
}


// method2(optimal) - using tortoise & hare algo t.c- O(n)  s.c- O(1)
ListNode *detectCycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next; // Move slow by one step
        fast = fast->next->next; // Move fast by two steps

        if (slow == fast){ // If they meet, loop exists
            slow = head; // Reset slow to head of list

            // now move both by 1 step until they meet, point where they meet will be startnode of loop
            while (slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return the start node of the loop
        }
    }
    return nullptr; // If no loop found, return null
}
