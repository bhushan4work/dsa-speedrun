// statement- Given root of Binary Tree, return height of tree. The height of tree is equal to no of nodes on longest path from root to leaf



//(optimal) t.c- O(n)  s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int maxDepth(Node *root){
    if (root == NULL){ //base case
        return 0;
    }

    int lh = maxDepth(root->left); // Recursive call to find max depth of left subtree
    int rh = maxDepth(root->right); // Recursive call to find max depth of right subtree

    return 1 + max(lh, rh); // Return max depth of tree, adding 1 for curr node
}