// Postorder: Visit left subtree first, then right subtree, then root node. Order = Left → Right → Root



// statement- Given root of Binary Tree, return postorder traversal

//(optimal): iterative t.c- O(n), s.c- O(h) h: height of bt
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
vector<int> postOrderTraversal(TreeNode *root){
    stack<TreeNode *> st1; // Initialize first stack
    stack<TreeNode *> st2; // Initialize second stack
    vector<int> postorder;

    if (root == NULL){
        return postorder;
    }

    st1.push(root); // Push the root node into the first stack

    while (!st1.empty()){ // Traverse until the first stack becomes empty
        TreeNode *node = st1.top(); // Retrieve the top node from the first stack
        st1.pop();                  // Remove the node from the first stack

        st2.push(node); // Push the node into the second stack

        if (node->left != NULL){
            st1.push(node->left); // Push the left child into the first stack
        }

        if (node->right != NULL){
            st1.push(node->right); // Push the right child into the first stack
        }
    }

    while (!st2.empty()){ // Traverse the second stack
        postorder.push_back(st2.top()->data); // Add the node's value to the postorder traversal list
        st2.pop();                             // Remove the node from the second stack
    }

    return postorder;
}



//(optimal): recursive t.c- O(n), s.c- O(n)
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
void postorder(TreeNode *root, vector<int> &arr){
    if (root == nullptr){ // base case
        return;
    }

    postorder(root->left, arr);  // Recursively traverse the left subtree
    postorder(root->right, arr); // Recursively traverse the right subtree
    arr.push_back(root->data);   // Push the current TreeNode's value into the vector
}
vector<int> postOrderTraversal(TreeNode *root){
    vector<int> arr;
    postorder(root, arr);
    return arr;
}