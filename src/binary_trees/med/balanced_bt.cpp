// statement- return true if Balanced bt else return false. bt is balanced if, for all nodes in tree, diff betw left & right subtree height is not more than 1



//(brute) t.c- O(n^2)  s.c- O(h)
struct Node{
    int data;    // Data stored in node
    Node *left;  // Pointer to left child
    Node *right; // Pointer to right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isBalanced(Node *root){
    if (root == nullptr){ // If tree is empty, it's balanced
        return true;
    }

    // Calculate height of left, right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Check if absolute diff in heights of left, right subtrees is <= 1
    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->left) && // Recursively check the left subtree
        isBalanced(root->right)){ // Recursively check the right subtree
        return true;
    }

    return false; // If any condition fails, the tree is unbalanced
}

// Function to calculate the height of a subtree
int getHeight(Node *root){
    if (root == nullptr){ // Base case
        return 0;
    }

    // Recursively calculate height of left, right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1; //gives height of bt in O(n)
}



//(optimal) t.c- O(n)  s.c- O(n)
struct Node{
    int data;    // Data stored in node
    Node *left;  // Pointer to left child
    Node *right; // Pointer to right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isBalanced(Node *root){
    // Check if tree's height diff betw subtrees is < 2
    return dfsHeight(root) != -1; // If not, return false; otherwise, return true
}
int dfsHeight(Node *root){
    if (root == NULL) return 0; // Base case

    int leftHeight = dfsHeight(root->left); // Recursively calculate height of left subtree
    if (leftHeight == -1) return -1; // If left subtree is unbalanced, propagate unbalance status

    int rightHeight = dfsHeight(root->right); // Recursively calculate height of right subtree
    if (rightHeight == -1) return -1; // If right subtree is unbalanced, propagate unbalance status

    // Check if diff in height between left, right subtrees is > 1
    if (abs(leftHeight - rightHeight) > 1) return -1; // If it's greater, tree is unbalanced, return -1 to propagate unbalance status

    return max(leftHeight, rightHeight) + 1; // Return max height of left, right subtrees, adding 1 for curr node
}
