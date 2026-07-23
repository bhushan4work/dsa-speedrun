// statement- given root of bst & int k, return true if there exist 2 elements in BST such that their sum = k, or false otherwise


//(brute) t.c- O(n + n)  s.c- O(n)
bool findTarget(TreeNode *root, int k){
    vector<int> inorder; // Vector stores inorder traversal of BST
    inorderTraversal(root, inorder); // Call helper to fill vector

    // Initialize two ptr's
    int left = 0;
    int right = inorder.size() - 1;

    while (left < right){
        int sum = inorder[left] + inorder[right]; // Calculate sum of curr pair

        if (sum == k){ // If sum equals k, we found a pair
            return true;
        }
        else if (sum < k){ // If sum smaller than k, move left pointer forward
            left++;
        }
        else{ // If sum larger than k, move right pointer backward
            right--;
        }
    }

    return false; // If no such pair found, return false
}

void inorderTraversal(TreeNode *root, vector<int> &inorder){
    if (!root) return; // If root is null, stop recursion

    inorderTraversal(root->left, inorder); // Traverse left subtree
    inorder.push_back(root->val);           // Add current node value to vector
    inorderTraversal(root->right, inorder); // Traverse right subtree
}



//(optimal) using bst iterator t.c- O(n)  s.c- O(h * 2)
class BSTIterator{
    stack<TreeNode *> myStack; // A stack is used to keep track of nodes while traversing
    bool reverse;              // This flag tells whether we are moving forward (inorder) or backward (reverse inorder)

    // Constructor initializes iterator with root node & traversal direction
    BSTIterator(TreeNode *root, bool isReverse) : reverse(isReverse){
        pushAll(root); // Push all nodes on one side (left or right) into stack
    }

    // This fxn checks if there are more nodes left to visit
    bool hasNext(){
        return !myStack.empty(); // If stack is not empty, there are still nodes left
    }

    // This fxn returns next node’s value in chosen order
    int next(){
        TreeNode *tmpNode = myStack.top(); // Get node on top of stack
        myStack.pop();                     // Remove this node from stack

        if (!reverse){ // If we are not in reverse mode, we need to go right after visiting a node
            pushAll(tmpNode->right);
        }
        else{ // If we are in reverse mode, we need to go left after visiting a node

            pushAll(tmpNode->left);
        }

        return tmpNode->val; // Return the value of the node that was just visited
    }

    // This helper function pushes all nodes from current node down to left/right edge
    void pushAll(TreeNode *node){
        while (node != nullptr){
            myStack.push(node); // Push the node onto the stack

            if (reverse){ // If reverse is true, move to the right child

                node = node->right;
            }
            else{ // Otherwise, move to the left child

                node = node->left;
            }
        }
    }
};

// This fxn checks if two nodes in BST sum to k
bool findTarget(TreeNode *root, int k){
    if (!root)
        return false; // If tree is empty, return false immediately

    // Create two iterators: one for smallest-to-largest order, another for largest-to-smallest
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    // Get first values from both ends
    int i = l.next();
    int j = r.next();

    while (i < j){
        if (i + j == k)
            return true; // If the two numbers add up to k, we found a pair

        else if (i + j < k)
            i = l.next(); // If sum is too small, move left iterator forward

        else
            j = r.next(); // If sum is too large, move right iterator backward
    }

    return false;
}
