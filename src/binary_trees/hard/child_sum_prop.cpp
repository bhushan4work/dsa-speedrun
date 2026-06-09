// statement- convert value of nodes to follow Children Sum Property. Child Sum Prop: for every node sum of its child values should be = node's value. A NULL child value is 0
// Note: node values can be increased by any +ve integer any number of times, but decrementing any node value is not allowed
//       A value for a NULL node can be assumed as 0
//       We cant change structure of given bt

//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void changeTree(TreeNode *root){
    if (root == NULL){ // Base case: If curr node is NULL, return & do nothing
        return;
    }

    // Calculate sum of values of left & right children, if they exist
    int child = 0;
    if (root->left){
        child += root->left->val;
    }
    if (root->right){
        child += root->right->val;
    }

    if (child >= root->val){ // Compare sum of children with curr node's value & update
        root->val = child;
    }
    else{
        // If sum is smaller, update child with curr node's value
        if (root->left){
            root->left->val = root->val;
        }
        else if (root->right){
            root->right->val = root->val;
        }
    }

    // Recursively call fxn on left & right children
    changeTree(root->left);
    changeTree(root->right);

    // Calculate total sum of values of left & right children, if they exist
    int tot = 0;
    if (root->left){
        tot += root->left->val;
    }
    if (root->right){
        tot += root->right->val;
    }

    // If either left or right child exists, update curr node's value with total sum
    if (root->left or root->right){
        root->val = tot;
    }
}



// statement- determine whether tree satisfies Children Sum Property. each non-leaf node must have value = sum of its left & right children's. A NULL child value is 0
//            Return true if every node in tree satisfies this condition, otherwise return false

//(optimal) t.c- O(n)  s.c- O(n)
bool isSumProperty(Node *root){
    if (root == NULL) return true; // Empty node is valid

    // Leaf node is always valid
    if (root->left == NULL && root->right == NULL) return true;

    // Get left child's value (0 if child doesn't exist)
    int left = 0;
    if (root->left != NULL) left = root->left->data;

    // Get right child's value (0 if child doesn't exist)
    int right = 0;
    if (root->right != NULL) right = root->right->data;

    // Current node must equal sum of its children
    if (root->data != left + right) return false;

    // Check the same property for left and right subtrees
    return isSumProperty(root->left) && isSumProperty(root->right);
}