// statement- Assuming standing on right\left side of bt & given its root, return values of nodes visible, arranged from top to bottom

//(brute)- iteration t.c- O(n) s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrder(Node *root){
    vector<vector<int>> ans; // Initialize final 2D vector

    if (!root) return ans; // If tree is empty, return empty vector

    queue<Node *> q; // Create queue to hold tree nodes
    q.push(root);    // Start with root node

    while (!q.empty()){
        int size = q.size(); // Get no of nodes at curr level
        vector<int> level;   // Vector to store curr level nodes

        for (int i = 0; i < size; i++){
            // Get the front node from the queue
            Node *node = q.front();
            q.pop();

            level.push_back(node->data); // Add its data to level vector

            if (node->left) q.push(node->left); // Enqueue left child if exists
            if (node->right) q.push(node->right); // Enqueue right child if exists
        }

        ans.push_back(level); // Add curr level to ans
    }

    return ans;
}

vector<int> leftView(Node *root){
    vector<vector<int>> levels = levelOrder(root); // Get level order traversal
    vector<int> left;

    // Pick first element of each level
    for (auto &level : levels){
        left.push_back(level[0]);
    }

    return left;
}

vector<int> rightView(Node *root){
    vector<vector<int>> levels = levelOrder(root); // Get level order traversal
    vector<int> right;

    // Pick last element of each level
    for (auto &level : levels){
        right.push_back(level.back());
    }

    return right;
}


//(optimal) - recursive t.c- O(n)  s.c- O(h)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};
    
void leftDFS(TreeNode *node, int level, vector<int> &res){
    if (!node) return;  // Base case: null node

    if (res.size() == level) res.push_back(node->val); // If this level is being visited 1st time, store its curr node's value

    leftDFS(node->left, level + 1, res); // Explore left subtree first
    leftDFS(node->right, level + 1, res); // Then explore right subtree
}

void rightDFS(TreeNode *node, int level, vector<int> &res){
    if (!node) return;

    if (res.size() == level) res.push_back(node->val); // If this level is being visited 1st time, store its curr node's value

    rightDFS(node->right, level + 1, res); // Explore right subtree first
    rightDFS(node->left, level + 1, res); // Then explore left subtree
}

vector<int> leftView(TreeNode *root){
    vector<int> res;
    leftDFS(root, 0, res);
    return res;
}

vector<int> rightView(TreeNode *root){
    vector<int> res;
    rightDFS(root, 0, res);
    return res;
}