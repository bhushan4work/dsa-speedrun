// statement- Given bt & ref to root belonging to it. Return path from root node to given leaf node
//            Note: No 2 nodes in tree have same data value & its assured that given node is present & path always exists

//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val; // Value of node
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool getPath(TreeNode *root, vector<int> &arr, int x){
    // If curr node is NULL, return false
    if (!root){
        return false;
    }

    arr.push_back(root->val); // Add curr node's value to path

    if (root->val == x){ // If curr node's value is equal to x, return true
        return true;
    }

    if (getPath(root->left, arr, x) || 
        getPath(root->right, arr, x)){ // Recursively search in left or right subtree
        return true;
    }

    // If not found, backtrack & remove curr node
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode *A, int B){
    vector<int> arr; // Vector to store the path

    // If root is NULL, return empty path
    if (A == NULL){
        return arr;
    }

    getPath(A, arr, B); // Call helper fxn to fill path

    return arr;
}



//statement- Given bt, you need to find all possible paths from root node to all leaf nodes of bt
//           Note: paths should be returned such that paths from left subtree of any node are listed first, followed by paths from right subtree

//(optimal) t.c- O(n)  s.c- O(n)
void getPaths(Node* root, vector<int>& path, vector<vector<int>>& ans){

    // If curr node is NULL, return
    if (!root){
        return;
    }

    path.push_back(root->data); // Add curr node's value to path

    // If curr node is a leaf node
    if (!root->left && !root->right){
        ans.push_back(path); // Store complete path
    }
    else{
        // Recursively search in left subtree
        getPaths(root->left, path, ans);

        // Recursively search in right subtree
        getPaths(root->right, path, ans);
    }

    // Backtrack & remove curr node
    path.pop_back();
}

vector<vector<int>> Paths(Node* root){
    vector<vector<int>> ans; // Stores all paths
    vector<int> path;        // Current path

    // If root is NULL, return empty answer
    if (root == NULL){
        return ans;
    }

    getPaths(root, path, ans);

    return ans;
}