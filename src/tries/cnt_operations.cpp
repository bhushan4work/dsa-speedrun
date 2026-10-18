//statement- implement a trie supporting 4 operations: insert(word) to add word, countWordsEndsWith(word) to count exact occurrences,
//           countWordsStartingWith(prefix) to count words with given prefix, erase(word) to remove 1 occurrence of a word


// (optimal) t.c- insert = o(l), cnt operations = o(l), erase = o(l), s.c- O(n * l)
struct TrieNode {
    TrieNode* links[26];                          // children for a-z
    int cntEndWith = 0;                            // count of words ending here
    int cntPrefix = 0;                             // count of words passing here

    TrieNode() {
        fill(links, links + 26, nullptr);          // initialize children
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;        // check child exists
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;                   // connect child node
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];                   // return child node
    }
};

class Trie {
    TrieNode* root;                               // root node

public:
    Trie() {
        root = new TrieNode();                    // create root
    }

    void insert(string word) {
        TrieNode* node = root;                    // start at root

        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new TrieNode());    // create missing node

            node = node->get(ch);                 // move to child
            node->cntPrefix++;                    // increment prefix count
        }

        node->cntEndWith++;                        // increment word count
    }

    int countWordEndsWith(string word) {
        TrieNode* node = root;                    // start at root

        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;                         // word path does not exist

            node = node->get(ch);                 // move to child
        }

        return node->cntEndWith;                  // count exact word matches
    }

    int countWordStartWith(string prefix) {
        TrieNode* node = root;                    // start at root

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return 0;                         // prefix does not exist

            node = node->get(ch);                 // move to child
        }

        return node->cntPrefix;                   // count words with this prefix
    }

    void erase(string word) {
        TrieNode* node = root;                    // start at root

        for (char ch : word) {
            if (!node->containsKey(ch))
                return;                           // word does not exist

            node = node->get(ch);                 // move to child
        }

        if (node->cntEndWith == 0)
            return;                               // word was never inserted or already erased

        node = root;                              // restart from root

        for (char ch : word) {
            node = node->get(ch);                 // move to child
            node->cntPrefix--;                    // decrement prefix count
        }

        node->cntEndWith--;                        // decrement exact word count
    }
};