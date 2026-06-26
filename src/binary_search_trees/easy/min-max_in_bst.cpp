// statement- Given root of bst, find min element in given BST
//(optimal) t.c- O(h)  s.c- O(1)
int minValue(Node *root){
    if (root == nullptr){ // Base case: if tree is empty
        return -1;
    }

    // Traverse to leftmost leaf
    Node *current = root;
    while (current->left != nullptr){
        current = current->left;
    }

    return current->data; // leftmost node contains min value
}



// statement- Given root of bst, find max element in given BST
//(optimal) t.c- O(h)  s.c- O(1)
int maxValue(Node *root){
    if (root == nullptr){ // Base case: if tree is empty
        return -1;
    }

    // Traverse to rightmost leaf
    Node *current = root;
    while (current->right != nullptr){
        current = current->right;
    }

    return current->data; // rightmost node contains max value
}