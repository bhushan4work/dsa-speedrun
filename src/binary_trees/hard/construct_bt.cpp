// statement- Given Pre & In order traversal of bt, construct Unique bt represented by them


//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){ //main given fxn
    map<int, int> inMap; // Map to store index of each value in inorder

    for (int i = 0; i < inorder.size(); i++){ // Fill map with inorder values & their indices
        inMap[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap); // Call recursive helper fxn
}

TreeNode *build(vector<int> &preorder, int preStart, int preEnd, 
                vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap){ // Recursive fxn to build tree using pre & in order segments

    if (preStart > preEnd || inStart > inEnd) return nullptr; // Base condn

    TreeNode *root = new TreeNode(preorder[preStart]); // first element in preorder is root

    int inRoot = inMap[root->val]; // Find root index in inorder

    int numsLeft = inRoot - inStart; // No of elements in left subtree

    // Recursively build left and right subtrees
    root->left = build(preorder, preStart + 1, preStart + numsLeft,inorder, inStart, inRoot - 1, inMap);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd,inorder, inRoot + 1, inEnd, inMap);

    return root;
}
