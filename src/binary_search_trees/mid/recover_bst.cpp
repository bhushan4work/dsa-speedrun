// statement- You are given root of bst, where values of exactly 2 nodes of tree were swapped by mistake. Recover tree without changing its structure


//(brute) t.c- O(2n + nlogn)  s.c- O(n)
void inorder(TreeNode *root, vector<int> &arr){
    if (!root) return; // Base case

    inorder(root->left, arr);  // Left subtree
    arr.push_back(root->val);  // Store value
    inorder(root->right, arr); // Right subtree
}

void fill(TreeNode *root, vector<int> &arr, int &idx){
    if (!root) return; // Base case

    fill(root->left, arr, idx);  // Fill left
    root->val = arr[idx++];      // Replace value
    fill(root->right, arr, idx); // Fill right
}

void recoverTree(TreeNode *root){
    vector<int> arr; // Stores inorder values

    inorder(root, arr); // Get inorder
    sort(arr.begin(), arr.end()); // Sort inorder

    int idx = 0; // Current index

    fill(root, arr, idx); // Rewrite BST
}



//(optimal) t.c- O(n)  s.c- O(h)
TreeNode *first = nullptr;  // First wrong node
TreeNode *second = nullptr; // Second wrong node
TreeNode *prev = nullptr;   // Previous inorder node

void inorder(TreeNode *root){
    if (!root) return; // Base case

    inorder(root->left); // Left subtree

    if (prev != nullptr && prev->val > root->val){ // Inorder violation

        if (!first)       // First violation
            first = prev; // Larger node

        second = root; // Smaller node
    }

    prev = root; // Update previous
    inorder(root->right); // Right subtree
}

void recoverTree(TreeNode *root){
    inorder(root); // Detect nodes
    swap(first->val, second->val); // Restore BST
}