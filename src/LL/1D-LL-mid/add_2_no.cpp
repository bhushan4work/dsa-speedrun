// statement- add 2 nos represented as lists, making a single combined list

// (optimal) t.c- O(max(n1,n2))  s.c- O(max(n1,n2))  --(list already reversed, so we just add)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *dummy = new ListNode(); // Initialize a dummy node as a new node
    ListNode *temp = dummy;
    int carry = 0; // Carry will be carried to the next new node created
    
    // Iterate until l1 exist or l2 exist or carry exist
    while (l1 != nullptr || l2 != nullptr || carry == 1){
        int sum = 0;
        if (l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
        }
        // Repeat the same process for l2
        if (l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        // Carry gets added to sum in the node (carry=sum/10)
        sum += carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}


// (optimal) t.c- O(n1 + n2 + max(n1,n2) + max(n1,n2) + max(n1,n2))  s.c- O(1)  --(list not reversed, so we reverse & add)
Node *reverse(Node *head){
    Node *prev = nullptr;
    while (head){
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
Node *addTwoLists(Node *l1, Node *l2){
    //reverse both lists
    l1 = reverse(l1);
    l2 = reverse(l2);

    Node *dummy = new Node(0);
    Node *temp = dummy;
    int carry = 0;

    // Iterate until l1 exist or l2 exist or carry exist
    while (l1 != nullptr || l2 != nullptr || carry == 1){
        int sum = 0;

        if (l1 != nullptr){
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr){
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry ;
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    //reverse result
    Node *result = reverse(dummy->next);

    // remove leading zeros
    while (result && result->data == 0 && result->next){
        result = result->next;
    }
    return result;
}