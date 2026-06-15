// Preorder: Visit root node first, then left subtree, then right subtree. Order = Root → Left → Right


// statement- Given root of Binary Tree, return preorder traversal

//(optimal): iterative using stack t.c- O(n), s.c- O(h) h: height of bt
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
vector<int> preOrderTraversal(TreeNode *root){
    stack<TreeNode *> st; // Initialize a stack to track nodes
    vector<int> preorder;

    if (root == NULL){
        return preorder;
    }

    st.push(root); // Push the root node into the stack

    while (!st.empty()){                             // Traverse until the stack becomes empty
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

//(optimal): recursive dfs t.c- O(n), s.c- O(n)
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

    arr.push_back(root->data);  // Push the current TreeNode's value into the vector
    preorder(root->left, arr);  // Recursively traverse the left subtree
    preorder(root->right, arr); // Recursively traverse the right subtree
}
vector<int> preOrderTraversal(TreeNode *root){
    vector<int> arr;
    preorder(root, arr);
    return arr;
}



// statement- Given a bt, implement Morris Preorder Traversal & return arr containing its preorder seq
// Morris algo: achieves sc of O(1) without recursion\external data structure. algo must visit each node in bt in preorder seq, processing node values as it traverses, without using stack or recursion

//(optimal): t.c- O(2n), s.c- O(1)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> getPreorder(TreeNode *root){
    vector<int> preorder;
    TreeNode *cur = root; // Pointer to current node, starting from root

    while (cur != NULL){

        // If curr node has no left child, visit it & move to right child
        if (cur->left == NULL){
            preorder.push_back(cur->val);

            cur = cur->right;
        }
        else{
            // Curr node has a left child
            // Find inorder predecessor (rightmost node in left subtree)
            TreeNode *prev = cur->left;

            while (prev->right != NULL && prev->right != cur){
                prev = prev->right;
            }

            // If thread is not yet created
            if (prev->right == NULL){

                preorder.push_back(cur->val); // In Preorder, process node BEFORE going left
                
                prev->right = cur; // Create a temporary thread back to current node

                cur = cur->left; // Move to left subtree
            }
            else{
                // Thread already exists, meaning left subtree has been completely processed

                prev->right = NULL; // Remove temporary thread

                cur = cur->right; // Move to right subtree
            }
        }
    }

    return preorder;
}