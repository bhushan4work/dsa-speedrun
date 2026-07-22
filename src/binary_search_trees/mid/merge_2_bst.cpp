//statement-  Given 2 BSTs, return elements of merged BSTs in sorted form


//(brute) t.c- O(n)  s.c- O(n)
class BSTIterator {
public:
    vector<int> inorderArr;
    int idx = 0;

    void inorder(TreeNode* root) {
        if (!root) return;                  // Base case

        inorder(root->left);               // Traverse left subtree
        inorderArr.push_back(root->val);   // Store current node
        inorder(root->right);              // Traverse right subtree
    }

    BSTIterator(TreeNode* root) {
        inorder(root);                     // Store complete inorder traversal
    }

    int next() {
        return inorderArr[idx++];          // Return current element and move index
    }

    bool hasNext() {
        return idx < inorderArr.size();    // Check if elements remain
    }
};



//(optimal) t.c- O(n)  s.c- O(h)
class BSTIterator {
    stack<TreeNode*> myStack;                      // Stores path to next smallest node

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);                             // Push left boundary of tree
    }

    bool hasNext() {
        return !myStack.empty();                   // Check if next element exists
    }

    int next() {
        TreeNode* tmpNode = myStack.top();         // Get next smallest node
        myStack.pop();                            // Remove it from stack
        pushAll(tmpNode->right);                  // Push left boundary of right subtree
        return tmpNode->val;                      // Return current value
    }

private:
    void pushAll(TreeNode* node) {
        for (; node != NULL;                      // Traverse till leftmost node
             myStack.push(node),                  // Push current node
             node = node->left);                  // Move to left child
    }
};