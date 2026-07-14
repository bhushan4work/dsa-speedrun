// statement- given root node & value to insert into tree. Return root node of BST after insertion. guaranteed that new value doesnt exist in original BST
// note: there may exist multiple valid ways for insertion, as long as tree remains BST after insertion. You can return any of them


//(optimal) t.c- O(logn)  s.c- O(1)
TreeNode *insertIntoBST(TreeNode *root, int val){
    if (root == nullptr) return new TreeNode(val); // If the tree is empty, create & return new root node

    TreeNode *curr = root;
    while (true){ // Keep traversing until correct insertion spot is found

        if (curr->val <= val){ // If curr node's val <= val, go right

            if (curr->right != nullptr) { // Right child exists, so continue traversal
                curr = curr->right;
            }
            else{
                curr->right = new TreeNode(val); // Found empty spot on right;so insert new node
                break; // Insertion complete
            }
        }
        else{ // curr node's val > val, so go left

            if (curr->left != nullptr){ // Left child exists, so continue traversal
                curr = curr->left;
            }
            else{
                curr->left = new TreeNode(val); // Found empty spot on left; so insert new node
                break; // Insertion complete.
            }
        }
    }

    return root; // Return original root of BST
}