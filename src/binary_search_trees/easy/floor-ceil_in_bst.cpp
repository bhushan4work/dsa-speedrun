// statement- Given root of bst & number k, find greatest no in bst that is <= k
//(optimal) t.c- O(logn)  s.c- O(1)
int floorInBST(TreeNode *root, int key){
    int floor = -1;

    while (root != nullptr){
        if (root->val == key){ // If key is == curr node value then it is floor
            floor = root->val;
            return floor;
        }

        if (key > root->val){ // If key is > curr node value ,move right & update floor
            floor = root->val;
            root = root->right;
        }
        else{
            root = root->left; // If key is smaller, move left
        }
    }
    return floor;
}



// statement- Given root of bst & number k, find smallest no in bst that is >= k
//(optimal) t.c- O(logn)  s.c- O(1)
int ceilInBST(TreeNode *root, int key){
    int ceil = -1;

    while (root != nullptr){
        if (root->val == key){ // If key is == curr node value then it is ceil
            ceil = root->val;
            return ceil;
        }

        if (key < root->val){ // If key is < curr node value ,move left & update ceil
            ceil = root->val;
            root = root->left;
        }
        else{
            root = root->right; // If key is greater, move right
        }
    }
    return ceil;
}
