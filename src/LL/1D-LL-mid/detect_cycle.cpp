//statement- given a LL, determine whether the LL contains a cycle or not
//cycle: cycle in a LL if there is some node in the list that can be reached again by continuously following the nextptr


//method1(brute) t.c- O(n * logn)  s.c- O(n) 
bool detectLoop(Node *head){
    Node *temp = head;
    
    unordered_map<Node *, int> nodeMap; // Create a map to keep track of visited nodes
    
    while (temp != nullptr){
        if (nodeMap.find(temp) != nodeMap.end()){  // If node already exists in map, loop detected
            return true;
        }
        nodeMap[temp] = 1; // Store the current node in the map
        temp = temp->next;  // Move to the next node
    }
    return false;
}


//method2(optimal) t.c- O(n)  s.c- O(1)  
bool detectLoop(Node *head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr || fast->next != nullptr){
        slow = slow-> next;  //move slowptr by 1
        fast = fast->next->next;  //move fastptr by 2
        if(slow == fast) return true;  // when both are found at same place we can say that cycle exist
    }
    return false;
}