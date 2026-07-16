// statement- Given root node & key, delete node with given key. Return root node reference (possibly updated) of BST
// note: deletion is divided into 2 stages: 1.Search for node to remove 2.If node is found, delete it


//(optimal) t.c- O(h)  s.c- O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {                                // Tree is empty
        return NULL;
    }

    if (root->val == key) {                            // Node to delete is the root
        return helper(root);
    }

    TreeNode* dummy = root;                            // Store original root to return later

    while (root != NULL) {                             // Traverse the tree to find the node
        if (root->val > key) {                         // Key lies in the left subtree
            if (root->left != NULL && root->left->val == key) {   // Left child is the node to delete
                root->left = helper(root->left);       // Delete and reconnect left subtree
                break;                                 // Deletion complete
            } else {
                root = root->left;                     // Move to left child
            }
        } else {                                       // Key lies in the right subtree
            if (root->right != NULL && root->right->val == key) { // Right child is the node to delete
                root->right = helper(root->right);     // Delete and reconnect right subtree
                break;                                 // Deletion complete
            } else {
                root = root->right;                    // Move to right child
            }
        }
    }

    return dummy;                                      // Return original root of the BST
}

TreeNode* helper(TreeNode* root) {
    if (root->left == NULL) {                          // No left child
        return root->right;                            // Replace with right subtree
    }

    if (root->right == NULL) {                         // No right child
        return root->left;                             // Replace with left subtree
    }

    TreeNode* rightChild = root->right;                // Save right subtree
    TreeNode* lastRight = findLastRight(root->left);   // Find rightmost node in left subtree
    lastRight->right = rightChild;                     // Attach right subtree to it

    return root->left;                                 // Left subtree becomes new root
}

TreeNode* findLastRight(TreeNode* root) {
    if (root->right == NULL) {                         // Rightmost node found
        return root;
    }

    return findLastRight(root->right);                 // Keep moving right
}