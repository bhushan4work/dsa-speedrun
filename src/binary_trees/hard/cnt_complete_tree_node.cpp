//statement-  Given Complete bt, count & return no of nodes in given tree. Complete bt is binary tree in which all levels are completely filled, except possibly for last level, & all nodes are as left as possible
//note: 2^h-1 gives total nodes in perfect bt (used in optimal approach)  

//(brute) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *root, int &count){
    if (root == NULL){ // If current node is NULL, stop processing
        return;
    }
    count++;                     // Increment count for current node
    inorder(root->left, count);  // Recursively count nodes in left subtree
    inorder(root->right, count); // Recursively count nodes in right subtree
}

int countNodes(TreeNode *root){
    if (root == NULL){
        return 0;
    }
    int count = 0;
    inorder(root, count); // Perform inorder traversal to count nodes
    return count;
}



//(optimal) t.c- O(logn * logn)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode *root){
    if (root == NULL){ // If tree is empty, return 0
        return 0;
    }
    int lh = findHeightLeft(root); // Get height from left side
    int rh = findHeightRight(root); // Get height from right side
    if (lh == rh){ // If heights are equal, it's a perfect bt
        return (1 << lh) - 1; // Use formula: 2^h - 1
    }
    return 1 + countNodes(root->left) + countNodes(root->right); // Otherwise, recursively count left & right subtrees
}

int findHeightLeft(TreeNode *node){ // Helper fxn to find height of leftmost path
    int height = 0;
    while (node){
        height++;
        node = node->left;
    }
    return height;
}

int findHeightRight(TreeNode *node){ // Helper function to find height of rightmost path
    int height = 0;
    while (node){
        height++;
        node = node->right;
    }
    return height;
}