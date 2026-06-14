// statement- Given pair of traversal, return true if its possible to construct unique bt else false. traversal are represented as: preorder-1, inorder-2, postorder-3
// note: A bt can be constructed uniquely if inorder is present with either preorder or postorder i.e (in,pre); (pre,in); (in,pos); (pos,in)

//(optimal) t.c- O(1)  s.c- O(1)
bool isPossible(int a, int b){
    // a != b ensures two different traversals are given
    // (a == 2 || b == 2) checks that one of them is inorder
    // If both conditions hold true then a unique bt can be constructed
    return (a != b) && (a == 2 || b == 2);
}



// statement- Given Pre & In order traversal of bt, construct Unique bt represented by them

//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){  // main given fxn
    map<int, int> inMap; // Map to store index of each value in inorder

    for (int i = 0; i < inorder.size(); i++){ // Fill map with inorder values & their indices
        inMap[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap); // Call recursive helper fxn
}

TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap){ // Recursive fxn to build tree using pre & in order segments

    if (preStart > preEnd || inStart > inEnd) return nullptr; // Base condn

    TreeNode *root = new TreeNode(preorder[preStart]); // first element in preorder is root

    int inRoot = inMap[root->val]; // Find root index in inorder

    int numsLeft = inRoot - inStart; // No of elements in left subtree

    // Recursively build left and right subtrees
    root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}



// statement- Given Post & In order traversal of bt, construct Unique bt represented by them

//(optimal) t.c- O(n)  s.c- O(n)
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
    if (inorder.size() != postorder.size()) return nullptr;

    // Map each value in inorder to its index
    map<int, int> hm;
    for (int i = 0; i < inorder.size(); i++){
        hm[inorder[i]] = i;
    }

    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm); // Call recursive builder
}

TreeNode *build(vector<int> &inorder, int is, int ie,
                vector<int> &postorder, int ps, int pe, map<int, int> &hm){
    if (ps > pe || is > ie) return nullptr;

    // Last element in postorder is root
    TreeNode *root = new TreeNode(postorder[pe]);

    // Find root index in inorder
    int inRoot = hm[postorder[pe]];
    int numsLeft = inRoot - is;

    // Recursively build left and right subtrees
    root->left = build(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);

    root->right = build(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

    return root;
}