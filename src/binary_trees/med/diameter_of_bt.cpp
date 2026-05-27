// statement- return length of diameter. Diameter of bt is longest distance betw any 2 nodes of that tree. This path may or may not pass through root



//(brute) t.c- O(n^2)  s.c- O(1)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int calculateHeight(Node *node){
    if(node == nullptr){
        return 0;
    }

    int lh = calculateHeight(node->left) ;
    int rh = calculateHeight(node->right) ;

    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *root){
    if(node == nullptr){
        return 0;
    }

    int lh = calculateHeight(node->left) ; 
    int rh = calculateHeight(node->right) ; 

    int currDiameter = lh + rh ;
    
    int lhDiameter = diameterOfBinaryTree(root->left);
    int rhDiameter = diameterOfBinaryTree(root->right);

    return max(currDiameter, max(lhDiameter, rhDiameter));
}



//(optimal) t.c- O(n)  s.c- O(1)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int height(Node *node, int &diameter){
    if (!node){ // Base case
        return 0;
    }

    // Recursively calculate height of left, right subtrees
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    diameter = max(diameter, lh + rh); // Update diameter with max of curr diameter or sum of left, right heights

    return 1 + max(lh, rh); // Return height of curr node's subtree
}
int diameterOfBinaryTree(Node *root){
    int diameter = 0;
    height(root, diameter); // Call height fxn to traverse tree, calculate diameter
    return diameter; // Return calculated diameter 
}