// statement- Given root of bt, value of target node, int k. Return arr of values of all nodes that have distance k from target
//note: here target is node so we need not to traverse and find where target is


//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Main fxn to find all nodes at distance K from target node
vector<int> distanceK(TreeNode *root, TreeNode *target, int k){
    if (!root) return {};

    // Step 1: Build parent mapping for each node using BFS
    unordered_map<TreeNode *, TreeNode *> parentMap;
    mapParentNodes(root, parentMap);

    // Step 2: Perform BFS from target to find nodes at distance K
    return bfsFromTarget(target, parentMap, k);
}

// Builds a mapping from each node to its parent to simulate undirected graph
void mapParentNodes(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap){
    queue<TreeNode *> q;
    q.push(root);

    // Level-order traversal to map parent of each node
    while (!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        // If left child exists, record its parent & add it to queue
        if (node->left){
            parentMap[node->left] = node;
            q.push(node->left);
        }

        // If right child exists, record its parent & add it to queue
        if (node->right){
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }
}

// BFS starting from target node to find all nodes exactly K distance away
vector<int> bfsFromTarget(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parentMap, int k){
    queue<TreeNode *> q;
    unordered_set<TreeNode *> visited;

    // Start BFS from the target node
    q.push(target);
    visited.insert(target);

    int currentLevel = 0;

    // Perform level-order BFS until we reach level K
    while (!q.empty()){
        int size = q.size();

        // If we've reached level k, break out and collect the result
        if (currentLevel++ == k) break;

        // Explore all nodes at curr level
        for (int i = 0; i < size; ++i){
            TreeNode *node = q.front();
            q.pop();

            // Explore left child if not already visited
            if (node->left && visited.find(node->left) == visited.end()){
                visited.insert(node->left);
                q.push(node->left);
            }

            // Explore right child if not already visited
            if (node->right && visited.find(node->right) == visited.end()){
                visited.insert(node->right);
                q.push(node->right);
            }

            // Explore parent from parentMap if not already visited. Only proceed if curr node has parent in map
            // This avoids inserting null parent for root node (which has no parent) & prevents accidental segfaults from accessing nullptr
            if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()){
                visited.insert(parentMap[node]);
                q.push(parentMap[node]);
            }
        }
    }

    // All nodes in queue are now at distance K from target
    vector<int> result;
    while (!q.empty()){
        result.push_back(q.front()->val);
        q.pop();
    }

    return result;
}



//note: here target is int so we need to traverse and find where target is in the bt


// Main fxn to find all nodes at distance K from target node
vector<int> KDistanceNodes(Node *root, int target, int k){
    if (!root) return {};

    Node *targetNode = findTarget(root, target);

    // Step 1: Build parent mapping for each node using BFS
    unordered_map<Node *, Node *> parentMap;
    mapParentNodes(root, parentMap);

    // Step 2: Perform BFS from target to find nodes at distance K
    return bfsFromTarget(targetNode, parentMap, k);
}

// Finds the target node using DFS
Node *findTarget(Node *root, int target){
    if (!root) return NULL;

    if (root->data == target) return root;

    Node *left = findTarget(root->left, target);
    if (left) return left;

    return findTarget(root->right, target);
}

// Builds a mapping from each node to its parent to simulate undirected graph
void mapParentNodes(Node *root, unordered_map<Node *, Node *> &parentMap){
    queue<Node *> q;
    q.push(root);

    // Level-order traversal to map parent of each node
    while (!q.empty()){
        Node *node = q.front();
        q.pop();

        // If left child exists, record its parent & add it to queue
        if (node->left){
            parentMap[node->left] = node;
            q.push(node->left);
        }

        // If right child exists, record its parent & add it to queue
        if (node->right){
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }
}

// BFS starting from target node to find all nodes exactly K distance away
vector<int> bfsFromTarget(Node *target, unordered_map<Node *, Node *> &parentMap, int k){
    queue<Node *> q;
    unordered_set<Node *> visited;

    // Start BFS from the target node
    q.push(target);
    visited.insert(target);

    int currentLevel = 0;

    // Perform level-order BFS until we reach level K
    while (!q.empty()){
        int size = q.size();

        // If we've reached level k, break out and collect the result
        if (currentLevel++ == k) break;

        // Explore all nodes at curr level
        for (int i = 0; i < size; ++i){
            Node *node = q.front();
            q.pop();

            // Explore left child if not already visited
            if (node->left && visited.find(node->left) == visited.end()){
                visited.insert(node->left);
                q.push(node->left);
            }

            // Explore right child if not already visited
            if (node->right && visited.find(node->right) == visited.end()){
                visited.insert(node->right);
                q.push(node->right);
            }

            // Explore parent from parentMap if not already visited. Only proceed if curr node has parent in map
            // This avoids inserting null parent for root node (which has no parent) & prevents accidental segfaults from accessing nullptr
            if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()){
                visited.insert(parentMap[node]);
                q.push(parentMap[node]);
            }
        }
    }

    // All nodes in queue are now at distance K from target
    vector<int> result;
    while (!q.empty()){
        result.push_back(q.front()->data);
        q.pop();
    }

    sort(result.begin(), result.end()); // GFG requires sorted order

    return result;
}