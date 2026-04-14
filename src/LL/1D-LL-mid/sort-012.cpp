//statement- given a LL containing only 0's, 1's, & 2's, sort LL by rearranging the links


//(brute) t.c- O(2n)  s.c- O(1) 
void sortZeroOneTwo(Node* head) {
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    while(temp != nullptr){
        if(temp->data == 0){
            cnt0++;
        }
        else if(temp->data == 1){
            cnt1++;
            
        }
        else if(temp->data == 2){
            cnt2++;
            
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr){
        if(cnt0 > 0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1 > 0){
            temp->data = 1;
            cnt1--;
        }
        else if(cnt2 > 0){
            temp->data = 2;
            cnt2--;
        }
    }
    return head; 
}


//(optimal) t.c- O(n)  s.c- O(1)
void sortZeroOneTwo(Node* head) {
    if(head == nullptr || head->next == nullptr) return __head; //edge case of list size <= 1 

    // Create dummy nodes for three lists: 0s, 1s, and 2s
    Node* zeroDummy = new Node(-1);
    Node* oneDummy = new Node(-1);
    Node* twoDummy = new Node(-1);

    // Tail pointers to build each of the lists
    Node* zero = zeroDummy;
    Node* one = oneDummy;
    Node* two = twoDummy;

    // Traverse original list and distribute nodes into 0s, 1s, or 2s list
    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr; //link dummy node head with current found node
            zero = zero->next; //move the dummy head to next node founded
        }else if (curr->data == 1) {
            one->next = curr; 
            one = one->next; 
        }else{
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // Connect the three lists: zero -> oneDummy.next -> twoDummy.next
    zero->next = oneDummy->next ? oneDummy->next : twoDummy->next; // Handle edge cases if 0s or 1s list is empty
    one->next = twoDummy->next;
    two->next = nullptr;  // end the list
        
    head = zeroDummy->next; // Update head to new sorted list

    // Delete dummy nodes (they were placeholders)
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;

    return head;
}