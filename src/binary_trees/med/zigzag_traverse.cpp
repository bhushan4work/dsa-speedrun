// statement- print zigzag traversal of bt. Zigzag traversal: alternating between left-to-right and right-to-left at each level of tree
//(optimal) t.c- O(n)  s.c- O(n)



struct TreeNode{
    int val;         // Value of the node
    TreeNode *left;  // Pointer to left child
    TreeNode *right; // Pointer to right child
    // Constructor to initialize node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root){
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode *> q; // Queue to store nodes level by level (BFS)
    q.push(root);

    bool flag = true; // Bool flag to control traversal direction: true for l-to-r, false for r-to-l

    while (!q.empty()){
        int size = q.size(); // Get no of nodes at curr level
        vector<int> level(size); // Temp vector to store curr level's values in correct zigzag order
    
        for (int i = 0; i < size; i++){
            TreeNode *node = q.front(); // Get front node from queue
            q.pop();

            // Determine index where this node's value should be placed based on traversal direction
            int index = flag ? i : size - 1 - i;
            level[index] = node->val;

            if (node->left) q.push(node->left); // If left child exists, add it to queue
            if (node->right) q.push(node->right); // If right child exists, add it to queue
        }

        flag = !flag;  // After finishing each level, toggle direction for next level
        result.push_back(level);    // Add this level's data to final result
    }
    
    return result;
}