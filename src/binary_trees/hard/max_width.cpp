// statement- return max width. max width: max diameter among all its levels. width of level is no of nodes possible betw left-&-right-most nodes


//(optimal) t.c- O(n)  s.c- O(n)
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int widthOfBinaryTree(TreeNode *root){
    if (!root) return 0;

    long long maxWidth = 0;

    queue<pair<TreeNode *, long long>> q; // Queue to perform level-order traversal, Each element is pair of {node, index}

    q.push({root, 0}); // Push root node with index 0

    // Continue BFS until queue becomes empty
    while (!q.empty()){
        int size = q.size(); // Get no of nodes at curr level

        long long minIndex = q.front().second; // Store index of 1st node at this level

        // Initialize variables to track first, last index
        long long first = 0;
        long long last = 0;

        // Traverse all nodes at curr level
        for (int i = 0; i < size; i++){
            // Get curr node & its relative index
            long long currIndex = q.front().second - minIndex;
            TreeNode *node = q.front().first;

            q.pop(); // Pop curr node from queue

            if (i == 0) first = currIndex; // Update first index if it's first node

            if (i == size - 1) last = currIndex; // Update last index if it's last node

            if (node->left) q.push({node->left, 2 * currIndex + 1}); // If left child exists, push it with calculated index

            if (node->right) q.push({node->right, 2 * currIndex + 2}); // If right child exists, push it with calculated index
        }

        maxWidth = max(maxWidth, (long long)last - first + 1); // Update max width if needed
    }

    return (int)maxWidth;
}



// statement- find max width. Maximum width here is defined as max number of nodes present at any level

//(optimal) t.c- O(n)  s.c- O(w) w- no of nodes present
int maxWidth(Node *root){
    if (!root) return 0;

    queue<Node *> q; // Queue used for level-order traversal (BFS)
    q.push(root);

    int ans = 0;

    // Traverse the tree level by level
    while (!q.empty()){

        int levelSize = q.size(); // No of nodes present at curr level

        ans = max(ans, levelSize); // Update max width if curr level has more nodes

        // Process all nodes of curr level
        for (int i = 0; i < levelSize; i++){

            Node *curr = q.front();     // Get front node from queue
            q.pop();

            if (curr->left) q.push(curr->left); // Add left child to queue for next level

            if (curr->right) q.push(curr->right); // Add right child to queue for next level
        }
    }

    return ans;
}
