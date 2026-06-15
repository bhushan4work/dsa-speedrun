// Inorder: Visit left subtree first, then root node, then right subtree. Order = Left → Root → Right


// statement- Given root of Binary Tree, return inorder traversal

//(optimal): iterative using stack t.c- O(n), s.c- O(h) h: height of bt
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

//(optimal): recursive dfs t.c- O(n), s.c- O(n)
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
    arr.push_back(root->data); // Push the current TreeNode's value into the vector
    inorder(root->right, arr); // Recursively traverse the right subtree
}
vector<int> inOrderTraversal(TreeNode *root){
    vector<int> arr;
    inorder(root, arr);
    return arr;
}



// statement- Given a bt, implement Morris Inorder Traversal & return arr containing its inorder seq
// Morris algo: achieves sc of O(1) without recursion\external data structure. algo must visit each node in bt in inorder seq, processing node values as it traverses, without using stack or recursion

//(optimal): t.c- O(2n), s.c- O(1)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> getInorder(TreeNode *root){
    vector<int> inorder;
    TreeNode *cur = root; // Pointer to curr node, starting from root

    while (cur != NULL){
        if (cur->left == NULL){ // If curr node's left child is NULL
            inorder.push_back(cur->val); // Add value of curr node to inorder vector
            cur = cur->right; // Move to right child
        }
        else{
            // If left child is not NULL,
            // find predecessor (rightmost node in left subtree)
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur){
                prev = prev->right;
            }

            // If predecessor's right child is NULL, establish temp link & move to left child
            if (prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                // If predecessor's right child is already linked, remove link,
                // add curr node to inorder vector, & move to right child
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    return inorder;
}
