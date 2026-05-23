// Postorder: Visit left subtree first, then right subtree, then root node. Order = Left → Right → Root



// statement- Given root of Binary Tree, return postorder traversal

//(optimal): iterative using 2 stack t.c- O(n), s.c- O(n)
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
        st2.pop();                            // Remove the node from the second stack
    }

    return postorder;
}



//(optimal): recursive dfs t.c- O(n), s.c- O(n)
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



//(optimal): iterative using 1 stack t.c- O(n), s.c- O(n)
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<int> postOrderTraversal(TreeNode *root){
    vector<int> postorder;

    if (root == NULL){
        return postorder;
    }

    stack<TreeNode *> st; // Initialize stack
    TreeNode *curr = root;
    TreeNode *lastVisited = NULL;

    while (curr != NULL || !st.empty()){ // Traverse until current becomes NULL and stack becomes empty

        if (curr != NULL){
            st.push(curr);      // Push the current node into the stack
            curr = curr->left;  // Move to the left subtree
        }
        else{
            TreeNode *temp = st.top()->right; // Get the right child of the top node

            if (temp == NULL){
                temp = st.top();
                st.pop(); // Remove the node from the stack

                postorder.push_back(temp->data); // Add the node's value to the postorder traversal list
                lastVisited = temp;

                while (!st.empty() && lastVisited == st.top()->right){
                    lastVisited = st.top();

                    postorder.push_back(lastVisited->data); // Add the node's value to the postorder traversal list
                    st.pop();                               // Remove the node from the stack
                }
            }
            else{
                curr = temp; // Move to the right subtree
            }
        }
    }

    return postorder;
}