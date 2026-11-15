// statement- Given target node data & root of bt. If target is set on fire, determine shortest time needed to burn entire bt.
//            in 1 second all nodes connected to a given node get burned i.e its left child, right child, parent



//(brute) t.c- O(n)  s.c- O(n)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void buildGraph(TreeNode* node, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr) { // Both directions are stored because fire can spread upward and downward.
        graph[node].push_back(node->left);
        graph[node->left].push_back(node);
        buildGraph(node->left, graph);
    }
    if (node->right != nullptr) {
        graph[node].push_back(node->right);
        graph[node->right].push_back(node);
        buildGraph(node->right, graph);
    }
}

int minTime(TreeNode* root, TreeNode* target) {
    if (root == nullptr) {
        return 0;
    }
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    buildGraph(root, graph); // Builds an undirected graph so fire can move between parent and child.
    queue<TreeNode*> nodesQueue;
    unordered_set<TreeNode*> burned;
    nodesQueue.push(target);
    burned.insert(target); // The target starts burning at time 0, so it is marked before BFS begins.
    int time = 0;
    while (!nodesQueue.empty()) {
        int levelSize = nodesQueue.size();
        bool spread = false; // spread records whether at least one new node catches fire this second.
        for (int i = 0; i < levelSize; i++) { // levelSize keeps all nodes burning during the same second together.
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            for (TreeNode* neighbor : graph[node]) {
                if (burned.find(neighbor) == burned.end()) {
                    burned.insert(neighbor);
                    nodesQueue.push(neighbor);
                    spread = true;
                }
            }
        }
        if (spread) { // Time advances only when the fire actually spreads to another node.
            time++;
        }
    }
    return time;
}



//(better) t.c- O(n)  s.c- O(n)
void buildParentTrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack) { // Builds child-to-parent links so fire can also spread upward.
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    parentTrack[root] = nullptr; // The root has no parent, so nullptr marks the end of upward movement.
    while (!nodesQueue.empty()) {
        TreeNode* node = nodesQueue.front();
        nodesQueue.pop();
        if (node->left != nullptr) {
            parentTrack[node->left] = node;
            nodesQueue.push(node->left);
        }
        if (node->right != nullptr) {
            parentTrack[node->right] = node;
            nodesQueue.push(node->right);
        }
    }
}

int minTime(TreeNode* root, TreeNode* target) { // Simulates the fire using left, right, and parent connections.
    if (root == nullptr) {
        return 0;
    }
    unordered_map<TreeNode*, TreeNode*> parentTrack;
    buildParentTrack(root, parentTrack);
    queue<TreeNode*> nodesQueue;
    unordered_set<TreeNode*> burned;
    nodesQueue.push(target);
    burned.insert(target);
    int time = 0;
    while (!nodesQueue.empty()) {
        int levelSize = nodesQueue.size();
        bool spread = false; // spread tells whether fire moved to at least one new node.
        for (int i = 0; i < levelSize; i++) { // levelSize represents all nodes burning during the current second.
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            if (node->left != nullptr && burned.find(node->left) == burned.end()) {
                burned.insert(node->left);
                nodesQueue.push(node->left);
                spread = true;
            }
            if (node->right != nullptr && burned.find(node->right) == burned.end()) {
                burned.insert(node->right);
                nodesQueue.push(node->right);
                spread = true;
            }
            TreeNode* parent = parentTrack[node];
            if (parent != nullptr && burned.find(parent) == burned.end()) { // parentTrack supplies the upward connection missing from the tree.
                burned.insert(parent);
                nodesQueue.push(parent);
                spread = true;
            }
        }
        if (spread) { // One second is counted only if at least one new node burns.
            time++;
        }
    }
    return time;
}



//(optimal) t.c- O(n)  s.c- O(h)
struct Info {
    int height;
    int distanceFromTarget;
};

Info dfs(TreeNode* node, TreeNode* target, int& maxTime) { // Returns subtree height and distance from current node to target.
    if (node == nullptr) {
        return {-1, -1};
    }
    Info left = dfs(node->left, target, maxTime);
    Info right = dfs(node->right, target, maxTime);
    int height = 1 + max(left.height, right.height);
    
    if (node == target) { // When target is reached, its subtree height gives the farthest downward burn.
        maxTime = max(maxTime, height);
        return {height, 0};
    }
    
    if (left.distanceFromTarget != -1) {
        int distanceFromTarget = left.distanceFromTarget + 1;
        maxTime = max(maxTime, distanceFromTarget + 1 + right.height); // Route moves from target to ancestor, then to opposite subtree's deepest node.
        return {height, distanceFromTarget};
    }
    
    if (right.distanceFromTarget != -1) {
        int distanceFromTarget = right.distanceFromTarget + 1;
        maxTime = max(maxTime, distanceFromTarget + 1 + left.height); // Left subtree is the opposite branch when target lies on the right.
        return {height, distanceFromTarget};
    }
    
    return {height, -1};
}

int minTime(TreeNode* root, TreeNode* target) { // Finds the maximum distance from target without storing explicit parent links.
    if (root == nullptr) {
        return 0;
    }
    int maxTime = 0;
    dfs(root, target, maxTime);
    return maxTime;
}
