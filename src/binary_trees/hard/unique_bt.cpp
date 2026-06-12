//statement- Given pair of traversal, return true if its possible to construct unique bt else false. traversal are represented as: preorder-1, inorder-2, postorder-3
//note: A bt can be constructed uniquely if inorder is present with either preorder or postorder i.e (in,pre); (pre,in); (in,pos); (pos,in)


//(optimal) t.c- O(1)  s.c- O(1)
bool isPossible(int a, int b) {
    // a != b ensures two different traversals are given
    // (a == 2 || b == 2) checks that one of them is inorder
    // If both conditions hold true then a unique bt can be constructed
    return (a != b) && (a == 2 || b == 2);
}