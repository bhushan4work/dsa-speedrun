//statement- implement a trie data structure that supports 3 operations: insert(word) to add word, search(word) to check if complete word exists,
//           startsWith(prefix) to check if any inserted word begins with given prefix.


// (optimal) t.c- insert = o(l), search = o(l), startswith = o(l), s.c- O(n * l)
struct TrieNode {
    TrieNode* links[26];                            // children for a-z
    bool flag = false;                              // marks end of word

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;          // check character exists
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;                     // insert child node
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];                     // return child node
    }

    void setEnd() {
        flag = true;                                // mark end of word
    }

    bool isEnd() {
        return flag;                                // check end of word
    }

    TrieNode() {
        fill(links, links + 26, nullptr);           // initialize children
    }
};

class Trie {
    TrieNode* root;                                 // root node

public:
    Trie() {
        root = new TrieNode();                      // create root
    }

    void insert(string word) {
        TrieNode* node = root;                      // start at root

        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new TrieNode());      // create missing node

            node = node->get(ch);                   // move to child
        }

        node->setEnd();                             // mark complete word
    }

    bool search(string word) {
        TrieNode* node = root;                      // start at root

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;                       // character not found

            node = node->get(ch);                   // move to child
        }

        return node->isEnd();                       // check complete word
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;                      // start at root

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return false;                       // prefix not found

            node = node->get(ch);                   // move to child
        }

        return true;                                // entire prefix exists
    }
};