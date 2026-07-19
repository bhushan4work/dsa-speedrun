// statement- find lowest common ancestor (LCA) node of 2 given nodes. LCA: defined betw 2 nodes p & q as lowest node in T that has both p & q as descendants
//            (where we allow node to be descendant of itself)


//(brute) t.c- O(h)  s.c- O(n)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    if (root == nullptr) return nullptr ;
    
    if (p->val < root->val && q->val < root->val){ // Both nodes lie in left subtree
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val) {// Both nodes lie in right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
    
    return root; // Split point => current node is the LCA
}

//(optimal) t.c- O(h)  s.c- O(1)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    if (root == nullptr) return nullptr ;

    while (root){ // Traverse until LCA is found

        if (p->val < root->val && q->val < root->val){ // Both nodes lie in left subtree
            root = root->left;
        }
        else if (p->val > root->val && q->val > root->val){ // Both nodes lie in right subtree
            root = root->right;
        }
        else{ // Split point => current node is LCA
            return root;
        }
    }

    return nullptr; // Safety check
}