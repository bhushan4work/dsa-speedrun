// statement- determine whether given tree is symmetric or not. bt is Symmetric when its mirror image is exactly same as original tree



//(optimal) t.c- O(n)  s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isSymmetricUtil(Node *root1, Node *root2){ // helper fxn
    if (root1 == NULL || root2 == NULL){ // Check if either subtree is NULL
        return root1 == root2; // If one subtree is NULL, other must also be NULL for symmetry , return true
    }
    // Check if data in curr nodes is equal & recursively check for symmetry in subtrees
    return (root1->data == root2->data) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left); 
}

bool isSymmetric(Node *root){
    if (!root){
        return true; // empty tree is considered symmetric
    }
    return isSymmetricUtil(root->left, root->right); // Call utility fxn to check symmetry of subtrees
}