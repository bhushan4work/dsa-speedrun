// statement- Given arr which represents preorder traversal of BST, construct tree & return its root


//(brute) t.c- O(n * n)  s.c- O(h)
TreeNode *insert(TreeNode *root, int val){
    if (root == nullptr) {// If tree is empty, create node
        return new TreeNode(val);
    }
    if (val < root->val){ // Smaller value goes left
        root->left = insert(root->left, val);
    }
    else{ // Greater value goes right
        root->right = insert(root->right, val);
    }
    return root; // Return updated root
}

TreeNode *bstFromPreorder(vector<int> &preorder){
    TreeNode *root = nullptr; // Initially empty BST

    for (int x : preorder) {// Insert every value
        root = insert(root, x);
    }

    return root;
}


//(optimal) - upper bound method t.c- O(n)  s.c- O(h)
TreeNode *build(vector<int> &preorder, int &i, int upperbound){
    if (i == preorder.size()) {// All nodes processed
        return nullptr;
    }

    if (preorder[i] > upperbound) { // Doesn't belong here
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[i++]); // Create curr node

    root->left = build(preorder, i, root->val); // Left values < root
    root->right = build(preorder, i, upperbound); // Right values < upperbound

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder){
    int i = 0;
    return build(preorder, i, INT_MAX);
}