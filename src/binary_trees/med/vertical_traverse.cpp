// statement- return Vertical-Traversal starting from Leftmost-level to Rightmost-level. If multiple nodes passing through vertical line, then it should be printed as they appear in level-order traversal



//(optimal) t.c- O(nlogn)  s.c- O(n+n)
struct Node{
    int data;                                                   // This stores the value of the node
    Node *left;                                                 // Pointer to the left child
    Node *right;                                                // Pointer to the right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {} // Constructor initializes node with value
};

vector<vector<int>> findVertical(Node *root){
    map<int, map<int, multiset<int>>> nodes;  // mp<vertical,mp<level,elements at a level>> map is used to store nodes grouped by vertical & level
    queue<pair<Node *, pair<int, int>>> todo; // queue is used for BFS, storing node & its coordinates

    todo.push({root, {0, 0}}); // Push root node with vertical = 0 , level = 0

    // Perform BFS traversal
    while (!todo.empty()){
        auto p = todo.front(); // Get front element in queue
        todo.pop();

        Node *temp = p.first;    // Extract node
        int x = p.second.first;  // Extract vertical (x)
        int y = p.second.second; // Extract level (y)

        nodes[x][y].insert(temp->data); // Insert the node into map by vertical and level

        if (temp->left){ // If left child exists, push with updated coordinates
            todo.push({temp->left, {x - 1, y + 1}});
        }

        if (temp->right){ // If right child exists, push with updated coordinates
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    for (auto &vertical : nodes){
        vector<int> col;
        for (auto &level : vertical.second){ // Collect all nodes in order of levels
            for (int node : level.second){
                col.push_back(node);
            }
        }
        ans.push_back(col); // Push the column into result
    }

    return ans ;

}