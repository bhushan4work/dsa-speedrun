// statement- return Bottom View. Bottom View of bt is set of nodes visible when we see tree from bottom



//(optimal) t.c- O(n)  s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(Node *root){
    vector<int> ans;

    if (root == NULL){
        return ans;
    }
     
    map<int, int> mpp; // Map to store bottom view nodes based on their vertical positions i.e <vertical pos, node>
    queue<pair<Node *, int>> q; // Queue for BFS traversal, each element is pair containing node & its vertical position

    q.push({root, 0}); // Push root node with its vertical position (0) into queue

    // BFS traversal
    while (!q.empty()){
        // Retrieve node & its vertical position from front of queue
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;

        mpp[line] = node->data; // Overwrite previous node at this vertical line; BFS ensures deeper nodes replace higher ones

        if (node->left != NULL){ // Process left child
            q.push({node->left, line - 1}); // Push left child with decreased vertical position into queue
        }

        if (node->right != NULL){ // Process right child
            q.push({node->right, line + 1}); // Push right child with an increased vertical position into queue
        }
    }

    for (auto it : mpp){ // Transfer values from map to result vector
        ans.push_back(it.second);
    }

    return ans;
}