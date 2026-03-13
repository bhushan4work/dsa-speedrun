// statement- Given the head of LL, determine length of loop present in LL. If no loop present, return 0


// method1(brute) t.c- O(n * logn)  s.c- O(n)
int lengthOfLoop(Node *head){
    unordered_map<Node *, int> visitedNodes;
    Node *temp = head;

    int cnt = 0; // Timer to track visited nodes

    // Traverse the linked list till temp reaches nullptr
    while (temp != nullptr){
        // If revisiting a node, return the difference of timer values
        if (visitedNodes.find(temp) != visitedNodes.end()){
            int loopLength = cnt - visitedNodes[temp]; 
            return loopLength;
        }
        visitedNodes[temp] = cnt; // else store curr node & its timer value

        temp = temp->next; // Move to the next node
        cnt++;
    }
    return 0; //if no loop exist so we return 0
}


// method2(optimal) -using tortoise & hare algo t.c- O(n)  s.c- O(1)
int countLoopLength(Node* meetingPoint) {
    Node* temp = meetingPoint; // store meeting point in temp node
    int length = 1;

    while (temp->next != meetingPoint){ // Move until we meet again
        temp = temp->next;
        length++;
    }
    return length;
}

int lengthOfLoop(Node *head){
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr){ // Loop until fast and slow meet
        slow = slow->next; // Move slow by one step
        fast = fast->next->next; // Move fast by two steps

        if (slow == fast){ // If slow and fast meet, loop detected
            return countLoopLength(slow);
        }
    }
    return 0; // No loop found
}
