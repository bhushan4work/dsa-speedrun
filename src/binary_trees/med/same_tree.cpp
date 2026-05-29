// statement- Given 2 bt, return true if these 2 bt are identical, otherwise return false



//(optimal) t.c- O(n)  s.c- O(h)
struct Node{
    int data;    // Data stored in the node
    Node *left;  // Pointer to the left child
    Node *right; // Pointer to the right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isIdentical(Node *node1, Node *node2){
    if (node1 == NULL && node2 == NULL){ // If both nodes are NULL, they are identical
        return true;
    }

    if (node1 == NULL || node2 == NULL){ // If only one of nodes is NULL, they are not identical
        return false;
    }

    // Check if curr nodes have same data & recursively check their left, right subtrees
    return ((node1->data == node2->data) 
    && isIdentical(node1->left, node2->left) 
    && isIdentical(node1->right, node2->right));
}
