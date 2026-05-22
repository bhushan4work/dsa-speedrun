// Preorder: Visit root node first, then left subtree, then right subtree. Order = Root → Left → Right



// statement- Given root of Binary Tree, return preorder traversal

//(optimal): iterative t.c- O(n), s.c- O(h) h: height of bt
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
vector<int> preOrderTraversal(TreeNode *root){
    stack<TreeNode *> st;  // Initialize a stack to track nodes
    vector<int> preorder;

    if (root == NULL){
        return preorder;
    }

    st.push(root); // Push the root node into the stack

    while (!st.empty()){ // Traverse until the stack becomes empty
        TreeNode *node = st.top(); // Retrieve the top node from the stack
        st.pop();                  // Remove the node from the stack

        preorder.push_back(node->data); // Add the node's value to the preorder traversal list

        if (node->right != NULL){
            st.push(node->right); // Push the right child into the stack
        }

        if (node->left != NULL){
            st.push(node->left); // Push the left child into the stack
        }
    }

    return preorder;
}



//(optimal): recursive t.c- O(n), s.c- O(n)
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
void preorder(TreeNode *root, vector<int> &arr){
    if (root == nullptr){ // base case
        return;
    }

    arr.push_back(root->data); // Push the current TreeNode's value into the vector
    preorder(root->left, arr);  // Recursively traverse the left subtree
    preorder(root->right, arr); // Recursively traverse the right subtree
}
vector<int> preOrderTraversal(TreeNode *root){
    vector<int> arr;
    preorder(root, arr);
    return arr;
}