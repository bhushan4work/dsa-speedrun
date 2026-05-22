// Inorder: Visit left subtree first, then root node, then right subtree. Order = Left → Root → Right



// statement- Given root of Binary Tree, return inorder traversal

//(optimal): iterative t.c- O(n), s.c- O(h) h: height of bt
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
vector<int> inOrderTraversal(TreeNode *root){
    stack<TreeNode *> st;  // Initialize a stack to track nodes
    TreeNode *node = root; // Start from the root node
    vector<int> inorder;

    while (true){ // Start an infinite loop for traversal
        if (node != NULL){
            st.push(node);     // Push the current node to the stack
            node = node->left; // Move to the left child of the current node
        }
        else{
            if (st.empty()){
                break;
            }
            node = st.top();               // Retrieve a node from the stack
            st.pop();                      // Remove the node from the stack
            inorder.push_back(node->data); // Add the node's value to the inorder traversal list
            node = node->right;            // Move to the right child of the current node
        }
    }

    return inorder;
}



//(optimal): recursive t.c- O(n), s.c- O(n)
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
void inorder(TreeNode *root, vector<int> &arr){
    if (root == nullptr){ // base case
        return;
    }
    inorder(root->left, arr);  // Recursively traverse the left subtree
    arr.push_back(root->data);                   // Push the current TreeNode's value into the vector
    inorder(root->right, arr); // Recursively traverse the right subtree
}
vector<int> inOrderTraversal(TreeNode *root){
    vector<int> arr;
    inorder(root, arr);
    return arr;
}