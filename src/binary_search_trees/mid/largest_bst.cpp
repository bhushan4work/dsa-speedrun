// statement- Given a root of bt, where nodes have integer values. Return size of largest subtree of bt which is also a BST. A bst is a bt ds which has following prop:
//            left subtree of a node contains only nodes with data < node’s data. right subtree of a node contains only nodes with data > node’s data. Both left & right subtrees must also be bst


//(brute) t.c- O(n ^ 2)  s.c- O(h)
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
bool isValidBST(Node* root, long long low, long long high) { // Checks whether the current subtree follows the BST rule inside the allowed value range.
    if (root == nullptr) { // An empty subtree is always valid.
        return true;
    }
    if (root->data <= low || root->data >= high) { // The current value must stay inside its valid BST range.
        return false;
    }
    return isValidBST(root->left, low, root->data) && isValidBST(root->right, root->data, high); // The left and right subtrees get stricter ranges.
}
int countNodes(Node* root) { // Counts all nodes in the current subtree.
    if (root == nullptr) { // Empty subtree contributes zero nodes.
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int largestBst(Node* root) { // Returns the size of the largest subtree that satisfies the BST property.
    if (root == nullptr) { // Empty tree has no BST nodes.
        return 0;
    }
    if (isValidBST(root, LLONG_MIN, LLONG_MAX)) { // If the whole current subtree is BST, its full size is the answer here.
        return countNodes(root);
    }
    return max(largestBst(root->left), largestBst(root->right)); // Otherwise, the answer must be fully inside one child subtree.
}



//(optimal) t.c- O(n)  s.c- O(h)
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class Info {
public:
    long long minValue;
    long long maxValue;
    int size;
    Info(long long minValue, long long maxValue, int size) {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->size = size;
    }
};
Info solve(Node* root) { // Returns subtree boundaries and largest BST size.
    if (root == nullptr) { // Empty subtree is valid; avoids blocking leaf comparisons.
        return Info(LLONG_MAX, LLONG_MIN, 0);
    }
    Info leftInfo = solve(root->left); // Left info needed before checking current root.
    Info rightInfo = solve(root->right); // Right info needed before checking current root.
    if (leftInfo.maxValue < root->data && root->data < rightInfo.minValue) { // Current root joins children if BST bounds fit.
        int currentSize = leftInfo.size + rightInfo.size + 1; // New BST size includes left, right, and current node.
        long long currentMin = min(leftInfo.minValue, (long long)root->data); // Valid BST boundaries.
        long long currentMax = max(rightInfo.maxValue, (long long)root->data);
        return Info(currentMin, currentMax, currentSize);
    }
    return Info(LLONG_MIN, LLONG_MAX, max(leftInfo.size, rightInfo.size)); // Invalid boundaries stop parent from using subtree.
}
int largestBst(Node* root) { // Returns the size of the largest valid BST subtree.
    return solve(root).size; // Helper stores the final answer in its size field.
}