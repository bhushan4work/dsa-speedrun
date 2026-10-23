//statement- Given string s, determine no of distinct substr (including empty substr) of given string. string B is substr of a string A if B can be obtained by deleting several chars (possibly none) from start
//           of A & several chars (possibly none) from end of A. 2 strings X & Y are considered diff if there is at least 1 index i such that char of X at index i is diff from char of Y at index i (X[i] != Y[i])


// (optimal) t.c- O(n ^ 2), s.c- O(n ^ 2)
class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode() {
        children.assign(26, nullptr);
    }
};

int countDistinctSubstrings(string s) { // Counts distinct substrings by inserting all suffix paths into a trie and counting only newly created nodes.
    TrieNode* root = new TrieNode();
    int distinctCount = 0; // Count only non-empty distinct substrings while new trie nodes are created.

    for (int start = 0; start < (int)s.size(); start++) {
        TrieNode* node = root;
        for (int end = start; end < (int)s.size(); end++) {
            int index = s[end] - 'a';

            if (node->children[index] == nullptr) { // A missing child means this substring has not appeared before.
                node->children[index] = new TrieNode();
                distinctCount++; // Increase the count because a new trie node represents a new substring.
            }
            
            node = node->children[index];
        }
    }
    return distinctCount + 1; // Add one more count because the empty substring is also valid.
}