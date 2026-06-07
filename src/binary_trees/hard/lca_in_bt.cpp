// statement- Given root of bt, find lowest common ancestor (LCA) of 2 given nodes (p, q) in tree
//            LCA is defined between 2 nodes p & q as lowest node in T that has both p & q as descendants (where we allow node to be descendant of itself)



//(optimal) -using recursive dfs t.c- O(n)  s.c- O(h)
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    if (root == NULL || root == p || root == q){ // Base case
        return root;
    }

    // Search in left & right subtrees
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // Result
    if (left == NULL){
        return right;
    }
    else if (right == NULL){
        return left;
    }
    else{ // Both left and right are not null, we found our result
        return root;
    }
}
