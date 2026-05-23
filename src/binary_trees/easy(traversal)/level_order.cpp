// statement-  Given root of binary tree, return level order traversal of its nodes values (i.e., from left to right, level by level)



//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> ans;     // Create a 2D vector to store levels
    if (root == nullptr){
        return ans; // If tree is empty, return an empty vector
    }

    queue<TreeNode *> q; // Create queue to store nodes for level-order traversal
    q.push(root); // Push root node to queue

    while (!q.empty()){
        int size = q.size();         // Get size of current level
        vector<int> level;          // Create vector to store nodes at curr level

        for (int i = 0; i < size; i++){
            TreeNode *node = q.front();   // Get front node in queue
            q.pop();              // Remove front node from queue
            level.push_back(node->data); // Store node value in curr level vector

            // add child nodes if they exist
            if (node->left != nullptr){
                q.push(node->left);
            }
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
        ans.push_back(level); // Store curr level in ans vector
    }

    return ans;
}
