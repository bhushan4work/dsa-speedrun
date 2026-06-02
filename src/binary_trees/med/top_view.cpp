// statement- return Top View. Top View of bt is set of nodes visible when we see the tree from top



//(optimal) t.c- O(n)  s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node *root){
    vector<int> ans;

    if (root == NULL){ // If the tree is empty, return an empty result
        return ans;
    }

    map<int, int> mpp; // Create a map to store vertical level -> node value (only first encountered)
    queue<pair<Node *, int>> q; // Create a queue for BFS that stores {node, vertical_level}

    q.push({root, 0}); // Push root node with vertical level 0

    // Start BFS traversal
    while (!q.empty()){
        auto it = q.front(); // Extract front element of queue
        q.pop();

        // Get node & its vertical position
        Node *node = it.first;
        int line = it.second;

        if (mpp.find(line) == mpp.end()){ // If vertical pos is being visited 1st time, store it, this makes sure we get top view
            mpp[line] = node->data;
        }

        if (node->left != NULL){ // If there is a left child, push it with vertical level - 1
            q.push({node->left, line - 1});
        }

        if (node->right != NULL){ // If there is a right child, push it with vertical level + 1
            q.push({node->right, line + 1});
        }
    }

    // Traverse map & store values in ans, map sorts it so we get elements from left to right i.e -2 -1 0 1 ..
    for (auto it : mpp){
        ans.push_back(it.second);
    }

    return ans;
}