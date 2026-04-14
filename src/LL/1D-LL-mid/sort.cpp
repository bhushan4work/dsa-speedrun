// statement- Given a LL, sort its nodes based on data value in them. return head of sorted LL


// (brute) t.c- O(n + nlog + n)  s.c- O(n)
Node *sortLL(Node *head){
    vector<int> arr;
    Node *temp = head;

    // Traverse & push values of list into vector
    while (temp != nullptr){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head; // place temp at head again
    // Reassign sorted values from vector to list nodes
    for (int i = 0; i < arr.size(); i++){
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}


// (optimal) t.c- O(logn * (n + n\2))  s.c- O(logn) for recursive stack
Node *findMiddle(Node *head){
    if (head == nullptr || head->next == nullptr){ // If list empty or single node
        return head;
    }

    Node *slow = head;
    Node *fast = head->next; //we want prev node of middle for even list & so we placed fast ahead initially

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // return middle node
}

Node *mergeTwoSortedLinkedLists(Node *list1, Node *list2){
    Node *dummyNode = new Node(-1); // Create a dummy node
    Node *temp = dummyNode; // Temp pointer to build merged list

    // Traverse both lists
    while (list1 != nullptr && list2 != nullptr){
        // Choose smaller node
        if (list1->data <= list2->data){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // Attach remaining nodes
    if (list1 != nullptr){
        temp->next = list1;
    }
    else{
        temp->next = list2;
    }

    return dummyNode->next;  // Return head of merged list
}

Node *sortLL(Node *head){
    if (head == nullptr || head->next == nullptr){ // Base case: empty or single node
        return head;
    }

    Node *middle = findMiddle(head); // Find middle node

    // Split into two halves
    Node *right = middle->next; //store head of rightside
    middle->next = nullptr; //break the link betn left & right
    Node *left = head;

    // Recursively sort both halves
    left = sortLL(left);
    right = sortLL(right);

    return mergeTwoSortedLinkedLists(left, right); // Merge sorted halves
}