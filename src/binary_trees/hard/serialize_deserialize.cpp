// statement- serialize and deserialize a bt. no restriction on how your serialization/deserialization algo should work. a bt can be serialized to a string, &
//            this string can be deserialized to original tree structure. encoded string should be as compact as possible


//(optimal) -using preorder traversal t.c- O(n)  s.c- O(n)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void serializeHelper(TreeNode* root, string& data) {
    if (root == nullptr) { // Record a marker "#" when the current child is missing.
        data += "#,";
        return;
    }
    data += to_string(root->val) + ","; // Append the current node's value followed by a comma.
    serializeHelper(root->left, data); // Recursively serialize the left subtree.
    serializeHelper(root->right, data); // Recursively serialize the right subtree.
}
TreeNode* deserializeHelper(vector<string>& tokens, int& index) {
    if (tokens[index] == "#") { // A null marker means this child does not exist.
        index++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(tokens[index++])); // Create the node and advance the token index.
    root->left = deserializeHelper(tokens, index); // Preorder stores the left subtree before the right subtree.
    root->right = deserializeHelper(tokens, index); // Recursively build the right subtree.
    return root;
}
string serialize(TreeNode* root) {
    string data;
    serializeHelper(root, data); // Start the preorder traversal to build the string.
    return data;
}
TreeNode* deserialize(string data) {
    vector<string> tokens;
    string token;
    stringstream ss(data);
    while (getline(ss, token, ',')) { // Separate the comma-delimited serialized string into individual tokens.
        tokens.push_back(token);
    }
    int index = 0; // Pointer to track the current token during reconstruction.
    return deserializeHelper(tokens, index);
}



//(optimal) -using bfs t.c- O(n)  s.c- O(n)
string serialize(TreeNode* root) {
    if (root == nullptr) { // An empty tree is represented by a single null marker.
        return "#";
    }
    string data;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) { // Process every tree position needed to preserve its structure.
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) { // Preserve the position of a missing child.
            data += "#,";
            continue;
        }
        data += to_string(node->val) + ","; // Append node value with a delimiter.
        q.push(node->left);
        q.push(node->right);
    }
    return data;
}

TreeNode* deserialize(string data) {
    if (data == "#") { // A null marker represents an empty tree.
        return nullptr;
    }
    vector<string> tokens;
    string token;
    stringstream ss(data);
    while (getline(ss, token, ',')) { // Separate the serialized string into individual tokens.
        tokens.push_back(token);
    }
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;
    while (!q.empty() && index < tokens.size()) { // Attach the next two tokens as children of each queued node.
        TreeNode* node = q.front();
        q.pop();
        if (tokens[index] != "#") { // Create the left child only when its token is not null.
            node->left = new TreeNode(stoi(tokens[index]));
            q.push(node->left);
        }
        index++;
        if (index < tokens.size() && tokens[index] != "#") { // Create the right child only when its token is not null.
            node->right = new TreeNode(stoi(tokens[index]));
            q.push(node->right);
        }
        index++;
    }
    return root;
}