// Preorder: Visit root node first, then left subtree, then right subtree. Order = Root → Left → Right
// Inorder: Visit left subtree first, then root node, then right subtree. Order = Left → Root → Right
// Postorder: Visit left subtree first, then right subtree, then root node. Order = Left → Right → Root


// statement- Given root of Binary Tree, return pre/in/post-order traversal sequence of given tree by making just one traversal

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
     
    stack<pair<Node *, int>> st;  // Stack to maintain nodes, their traversal state

    st.push({root, 1}); // Start with root node, state 1 (preorder)

    while (!st.empty()){
        auto it = st.top();
        st.pop();

        // this is part of preorder
        if (it.second == 1){
            pre.push_back(it.first->data); // Store node's data in preorder traversal
            it.second = 2; // Move to state 2 (inorder) for this node
            st.push(it); // Push updated state back onto stack i.e {1,2} here

            if (it.first->left != NULL){
                st.push({it.first->left, 1}); // Push left child onto stack for processing
            }
        }

        // this is a part of inorder
        else if (it.second == 2){
            in.push_back(it.first->data); // Store node's data in inorder traversal
            it.second = 3; // Move to state 3 (postorder) for this node
            st.push(it); // Push updated state back onto stack

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
