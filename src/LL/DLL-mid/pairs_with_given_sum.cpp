// statement- given sorted DLL of +ve distinct elements, task is to find pairs in DLL whose sum = given value target

// (brute) t.c- O(n^2)  s.c- O(1)
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int, int>> ans;
    Node *temp1 = head;

    while (temp1 != nullptr){
        Node *temp2 = temp1->next;

        // we check for target only if sum<=target as list is sorted so theres no need to check further
        while (temp2 != nullptr && (temp1->data + temp2->data <= target) ){
            if (temp1->data + temp2->data == target){
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}


// (optimal) t.c- O(n + n)  s.c- O(1)
Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int, int>> ans ;
    if(head == nullptr) return ans; 
    Node* left = head;
    Node* right = findTail(head);

    while(left->data < right->data){
        if(left->data + right->data == target){ //once target found move both ptr
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < target){ //sum is less so move left ptr
            left = left->next;
        }
        else{ //sum is greater so move right ptr
            right = right->prev;
        }
    }
    return ans;
}