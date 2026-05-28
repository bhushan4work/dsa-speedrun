// statement- determine max sum achievable along any path within tree. A path in bt: seq of nodes where each pair of adj nodes is connected by an edge. Nodes can only appear once in seq, & path is not required to start from root
//            Identify & compute max sum possible along any path within given bt



//(optimal) t.c- O(n)  s.c- O(h)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
int dfs(TreeNode *node, int &maxSum){
    if (!node) return 0;

    // Recursively find left, right max path sums
    int left = max(0, dfs(node->left, maxSum));
    int right = max(0, dfs(node->right, maxSum));

    maxSum = max(maxSum, left + right + node->val); // Update global maxsum considering node as turning point
    
    return max(left, right) + node->val; // Return best one-sided pathsum
}
int maxPathSum(TreeNode *root){
    int maxSum = INT_MIN;
    dfs(root, maxSum);
    return maxSum;
}
