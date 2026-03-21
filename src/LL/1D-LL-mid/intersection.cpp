//statement- given the heads of 2 LL, return node at which 2 lists intersect. If the 2 LL have no intersection at all, return null


//method1(brute) t.c- O(n1 + n2)  s.c- O(n1) 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> st;
    
    //store all nodes of list A
    ListNode* temp1 = headA;
    while (temp1 != nullptr){
        st.insert(temp1);
        temp1 = temp1->next;
    }
    
    //check in list B
    ListNode* temp2 = headB;
    while (temp2 != NULL) {
        if (st.find(temp2) != st.end()) { //checks whether curr node ptr already exists in set 
            return temp2;  // intersection found
        }
        temp2 = temp2->next;
    }        
    return nullptr; // no intersection
}


//method2(brute) - same like nested forLoop approach t.c- O(n1 * n2)  s.c- O(1) 
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    while (headA != nullptr) {
        ListNode* temp = headB;
        while (temp != nullptr) {
            // If both nodes are the same (intersection point)
            if (temp == headA)
                    return headA;
                temp = temp->next;
            }
            headA = headA->next;
        }
        // Intersection is not present between the lists, return NULL
        return nullptr;
    }


//method3(optimal) t.c- O(n1 + n2)  s.c- O(1)
int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //get lenght of both lists
    int lenA = getLength(headA);
    int lenB = getLength(headB);
        
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
        
    // Align both lists
    if (lenA > lenB){ 
        int diff = lenA - lenB;
        while (diff != 0){
            temp1 = temp1->next;
            diff--;
        }
    }
    else{
        int diff = lenB - lenA;
        while (diff != 0) {
            temp2 = temp2->next;
            diff--;
        }
    }
        
    //here len1 == len2 & so we move together
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}


//method4(optimal) t.c- O(n1 + n2)  s.c- O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr) return nullptr;

    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while(temp1 != temp2){ //if heads of both are = initially we directly return null w'out traversing
        //both ptr's moves by 1
        temp1 = temp1->next;
        temp2 = temp2->next;

        //handles the case if list1 size == list2 size
        //also handles case when intersection doesnt exist, so both will show null as temp1 == temp2 == null
        if(temp1 == temp2 ) return temp1; 

        //else we relocate both temps after reaching null to the head of opposite list
        //now again both ptr's moves by 1 & they meet if intersection exist
        if(temp1 == nullptr) temp1 = headB;
        if(temp2 == nullptr) temp2 = headA;
    }
    return temp1;
}
