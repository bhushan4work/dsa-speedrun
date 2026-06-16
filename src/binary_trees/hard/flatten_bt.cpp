// statement- convert bt to LL where LL's nodes follow same order as pre-order traversal of bt
// Use right ptr of bt as ‘next’ ptr for LL & set left ptr to null. Do this in place & dont create extra nodes


//(brute) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *prev = nullptr; // prev node ptr for reverse preorder linking
void flatten(TreeNode *root){
    if (root == nullptr) return;           // return if node is null
    flatten(root->right); // flatten right subtree first
    flatten(root->left);  // flatten left subtree next
    root->right = prev;   // connect curr node's right to previously processed node
    root->left = nullptr; // nullify left ptr
    prev = root;          // update prev to curr
}


//(better) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *prev = nullptr; // keep same field as original (unused in iterative version)
void flatten(TreeNode *root){
    if (root == nullptr) return;
    stack<TreeNode *> st; // create stack for DFS

    st.push(root); // push root to start traversal

    // process while stack has nodes
    while (!st.empty()){
        TreeNode *cur = st.top(); // take top node
        st.pop();
        if (cur->right != nullptr) st.push(cur->right); // push right child first (so left is processed first)
        if (cur->left != nullptr) st.push(cur->left); // push left child next
        if (!st.empty()) cur->right = st.top(); // if stack not empty, link current's right to next node
        cur->left = nullptr;       // nullify left to form right-only chain
    }
}


//(optimal) t.c- O(2n)  s.c- O(1)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void flatten(TreeNode *root){
    TreeNode *curr = root; // Initialize ptr 'curr' to root of tree

    // Iterate until 'curr' becomes NULL
    while (curr){

        if (curr->left){ // Check if curr node has left child

            TreeNode *pre = curr->left; // If yes, find rightmost node in left subtree
            while (pre->right){
                pre = pre->right;
            }

            pre->right = curr->right; // Connect rightmost node in left subtree to curr node's right child

            curr->right = curr->left; // Move entire left subtree to right child of curr node

            curr->left = NULL; // Set left child of curr node to NULL
        }

        curr = curr->right; // Move to next node on right side
    }
}