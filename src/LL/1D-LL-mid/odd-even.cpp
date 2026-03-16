// statement- group all nodes with odd indices followed by all nodes with even indices & return reordered list. Consider 1st node to have index 1 and so on. relative order of elements inside odd & even group must remain same as given input

// method1(brute) t.c- O(n)  s.c- O(n)
ListNode *oddEvenList(ListNode *head){
    if (!head) return head;

    vector<int> arr;
    ListNode *temp;

    // collect odd positions
    temp = head;
    while (temp){
        arr.push_back(temp->val);
        if (temp->next){
            temp = temp->next->next;
        }
        else{
            break;
        }
    }

    // collect even positions
    temp = head->next;
    while (temp){
        arr.push_back(temp->val);
        if (temp->next){
            temp = temp->next->next;
        }
        else{
            break;
        }
    }

    // rewrite values
    temp = head;
    for (int x : arr){
        temp->val = x;
        temp = temp->next;
    }
    return head;
}


// method2(optimal) t.c- O(n)  s.c- O(1)
ListNode *oddEvenList(ListNode *head){
    if (head == NULL || head->next == NULL) return head; // Edge case

    ListNode *odd = head;        // first node
    ListNode *even = head->next; // second node
    ListNode *evenHead = even;   // store start of even list

    // Traverse until even or even->next becomes NULL
    while (even && even->next){
        // connect next odd node
        odd->next = odd->next->next;
        odd = odd->next; // move to next node

        // connect next even node
        even->next = even->next->next;
        even = even->next; // move to next node
    }
    // attach even list after odd list
    odd->next = evenHead;

    return head;
}