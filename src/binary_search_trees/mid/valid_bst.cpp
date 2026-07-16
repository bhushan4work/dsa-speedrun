// statement- Given root of bt, determine if it is valid bst. valid bst is defined as follows: left < curr node < right for all bt & sub-bt's


//(optimal) t.c- O(n)  s.c- O(h)
bool isValid(TreeNode *root, long long low, long long high){
    if (root == NULL) // Empty tree is always a valid BST
        return true;

    if (root->val <= low || root->val >= high) // Current node violates BST property
        return false;

    return isValid(root->left, low, root->val) && // Left subtree must be < root and
           isValid(root->right, root->val, high); // Right subtree must be > root
}

bool isValidBST(TreeNode *root){
    return isValid(root, LLONG_MIN, LLONG_MAX); // Initial valid range
}