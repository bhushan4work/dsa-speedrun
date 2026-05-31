// statement- perform boundary traversal i.e visiting boundary nodes of bt in acw direction, starting from root (can be done in cw direction too)



//(optimal) t.c- O(n)  s.c- O(n)
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node *root){
    return !root->left && !root->right;
}

//this fxn adds left boundary without leaf nodes
void addLeftBoundary(Node *root, vector<int> &res){
    Node *curr = root->left;
    while (curr){
        if (!isLeaf(curr)){ // If curr node is not a leaf, add its value to result
            res.push_back(curr->data);
        }
        if (curr->left){ // Move to left child if it exists,  otherwise move to right child
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

//this fxn adds leaf nodes
void addLeaves(Node *root, vector<int> &res){
    if (isLeaf(root)){ // If curr node is a leaf, add its value to result
        res.push_back(root->data);
        return;
    }
    if (root->left){ // Recursively add leaves of left & right subtrees 
        addLeaves(root->left, res);
    }
    if (root->right){
        addLeaves(root->right, res);
    }
}

//this fxn adds right boundary without leaf nodes in reverse order
void addRightBoundary(Node *root, vector<int> &res){
    Node *curr = root->right;
    vector<int> temp;
    while (curr){
        if (!isLeaf(curr)){ // If curr node is not a leaf, add its value to a temp vector
            temp.push_back(curr->data);
        }
        if (curr->right){ // Move to right child if it exists, otherwise move to the left child
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    // Reverse & add values from temp vector to result
    for (int i = temp.size() - 1; i >= 0; --i){
        res.push_back(temp[i]);
    }
}

vector<int> BoundaryTraversal(Node *root){
    vector<int> res;
    if (!root){
        return res;
    }
    if (!isLeaf(root)){ // If root is not a leaf, add its value to result
        res.push_back(root->data);
    }

    // Add left-boundary -> leaves(inorder traversal) -> right-boundary(in reverse order)
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}
