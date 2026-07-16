// statement- Given root, integer k, return kth smallest value (1-indexed) of all values of nodes in tree

//(optimal) t.c- O(n)  s.c- O(h)

int cnt = 0;  // Counts visited nodes
int ans = -1; // Stores kth smallest value

void inorder(TreeNode *root, int k){
    if (root == NULL || cnt >= k) // Stop if tree ends or answer is found
        return;

    inorder(root->left, k); // Visit left subtree

    cnt++; // Process current node
    if (cnt == k){                    // If current node is kth smallest
        ans = root->val; // Store the answer
        return;          // Stop further processing
    }

    inorder(root->right, k); // Visit right subtree
}

int kthSmallest(TreeNode *root, int k){
    inorder(root, k); // Perform inorder traversal
    return ans;       // Return kth smallest element
}





// statement- Given root, integer k, return kth largest value (1-indexed) of all values of nodes in tree

//(optimal) t.c- O(n)  s.c- O(h)

int cnt = 0;  // Counts visited nodes
int ans = -1; // Stores kth largest value

void reverseInorder(TreeNode *root, int k){
    if (root == NULL || cnt >= k) // Stop if tree ends or answer is found
        return;

    reverseInorder(root->right, k); // Visit right subtree first

    cnt++; // Process current node
    if (cnt == k){                    // If current node is kth largest
        ans = root->val; // Store the answer
        return;          // Stop further processing
    }

    reverseInorder(root->left, k); // Visit left subtree
}

int kthLargest(TreeNode *root, int k){
    reverseInorder(root, k); // Perform reverse inorder traversal
    return ans;              // Return kth largest element
}
