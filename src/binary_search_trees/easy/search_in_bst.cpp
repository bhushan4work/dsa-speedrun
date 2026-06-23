//statement- Given bst & key value, return node in BST having data = ‘key’ otherwise return nullptr

//(optimal) t.c- O(logn)  s.c- O(1)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};
TreeNode* searchBST(TreeNode* root, int target) {
    while (root != nullptr && root->val != target) { // Traverse until we reach a null node or the target is found
        if (target < root->val) { // If target is less than curr node, go left
            root = root->left;
        }
        else{ // If target is greater than curr node, go right
            root = root->right;
        }
    }
    return root;
}