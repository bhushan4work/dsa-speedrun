//statement- Given bst & ‘key’ val. Return inorder successor of given node in BST

//(brute) t.c- O(n)  s.c- O(n) 
void inorder(Node* root, vector<Node*>& arr) {
    if (root == NULL)
        return;                                     // Base case

    inorder(root->left, arr);                       // Traverse left subtree
    arr.push_back(root);                            // Store current node
    inorder(root->right, arr);                      // Traverse right subtree
}

Node* inorderSuccessor(Node* root, int key) {
    vector<Node*> arr;                              // Stores inorder traversal
    inorder(root, arr);                             // Generate sorted inorder

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->data == key) {                  // Key found
            if (i + 1 < arr.size())                 // Check if successor exists
                return arr[i + 1];

            return NULL;                            // No successor exists
        }
    }
    return NULL;                                    // Key not present
}


//(optimal) t.c- O(h)  s.c- O(1)
Node* inorderSuccessor(Node* root, int key) {
    Node* succ = NULL;                          // Stores successor

    while (root != NULL) {
        if (key < root->data) {
            succ = root;                        // Current node can be successor
            root = root->left;                  // Move left to find a smaller successor
        }
        else {
            root = root->right;                 // Move right
        }
    }
    return succ;                                // Return successor
}



//statement- Given bst & ‘key’ val. Return inorder predecessor of given node in BST

//(brute) t.c- O(n)  s.c- O(n)
void inorder(Node* root, vector<Node*>& arr) {
    if (root == NULL)
        return;                                     // Base case

    inorder(root->left, arr);                       // Traverse left subtree
    arr.push_back(root);                            // Store current node
    inorder(root->right, arr);                      // Traverse right subtree
}

Node* inorderPredecessor(Node* root, int key) {
    vector<Node*> arr;                              // Stores inorder traversal
    inorder(root, arr);                             // Generate sorted inorder

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->data == key) {                  // Key found
            if (i - 1 >= 0)                         // Check if predecessor exists
                return arr[i - 1];

            return NULL;                            // No predecessor exists
        }
    }
    return NULL;                                    // Key not present
}


//(optimal) t.c- O(h)  s.c- O(1)
Node* inorderPredecessor(Node* root, int key) {
    Node* pred = NULL;                          // Stores predecessor

    while (root != NULL) {
        if (key > root->data) {
            pred = root;                        // Current node can be predecessor
            root = root->right;                 // Move right to find a larger predecessor
        }
        else {
            root = root->left;                  // Move left
        }
    }
    return pred;                                // Return predecessor
}










