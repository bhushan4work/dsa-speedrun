// Preorder: Visit root node first, then left subtree, then right subtree. Order = Root → Left → Right
// Inorder: Visit left subtree first, then root node, then right subtree. Order = Left → Root → Right
// Postorder: Visit left subtree first, then right subtree, then root node. Order = Left → Right → Root



// statement- Given root of Binary Tree, return pre/in/post-order traversal seq of given tree by making just one traversal
//(optimal) t.c- O(3n) each node processed 3 times, s.c- O(3n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<vector<int>> preInPostTraversal(Node *root){
    vector<int> pre, in, post; // Vectors to store traversals
    if (root == NULL){
        return {};
    }

    stack<pair<Node *, int>> st; // Stack to maintain nodes, their traversal state
    st.push({root, 1}); // Start with root node, state 1 (preorder)

    while (!st.empty()){
        auto it = st.top();
        st.pop();

        // this is part of preorder
        if (it.second == 1){
            pre.push_back(it.first->data); // Store node's data in preorder traversal
            it.second = 2;                 // Move to state 2 (inorder) for this node
            st.push(it);                   // Push updated state back onto stack i.e {1,2} here

            if (it.first->left != NULL){
                st.push({it.first->left, 1}); // Push left child onto stack for processing
            }
        }

        // this is a part of inorder
        else if (it.second == 2){
            in.push_back(it.first->data); // Store node's data in inorder traversal
            it.second = 3;                // Move to state 3 (postorder) for this node
            st.push(it);                  // Push updated state back onto stack

            if (it.first->right != NULL){
                st.push({it.first->right, 1}); // Push right child onto stack for processing
            }
        }

        // this is part of postorder
        else{
            post.push_back(it.first->data); // Store node's data in postorder traversal
        }
    }

    // Returning traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}



// statement- Given root of Binary Tree, return preorder traversal 
//(optimal) t.c- O(n), s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void preorder(Node *root, vector<int> &arr){
    if (root == nullptr){ // base case
        return;
    }
    arr.push_back(root->data);  // Push the current node's value into the vector
    preorder(root->left, arr);  // Recursively traverse the left subtree
    preorder(root->right, arr); // Recursively traverse the right subtree
}
vector<int> preOrderTraversal(Node *root){
    vector<int> arr;
    preorder(root, arr);
    return arr;
}



// statement- Given root of Binary Tree, return postorder traversal
//(optimal) t.c- O(n), s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void postOrder(Node *root, vector<int> &arr){
    if (root == nullptr){ // base case
        return;
    }

    postOrder(root->left, arr);  // Recursively traverse the left subtree
    postOrder(root->right, arr); // Recursively traverse the right subtree
    arr.push_back(root->data); // Push the current node's value into the vector
}
vector<int> postOrderTraversal(Node *root){
    vector<int> arr;
    postOrder(root, arr);
    return arr;
}



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



// statement- Given root of Binary Tree, return inorder traversal
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