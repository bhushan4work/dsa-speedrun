//statement- Given string arr. string is calle complete if every prefix of this string is also present in arr. Find longest complete string in arr.
//           If there are multiple strings with same length, return lexicographically smallest one & if no string exists, return none


// (optimal) t.c- o(n * l), s.c- O(n * l)
struct Node {
    Node* links[26];                                  // stores links to child nodes
    bool flag = false;                                // marks end of a word

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;               // check if character exists
    }

    Node* get(char ch) {
        return links[ch - 'a'];                       // return next node
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;                       // connect new node
    }

    void setEnd() {
        flag = true;                                  // mark end of word
    }

    bool isEnd() {
        return flag;                                  // check end of word
    }
};

class Trie {
private:
    Node* root;                                       // trie root

public:
    Trie() {
        root = new Node();                            // create root node
    }

    void insert(string word) {
        Node* node = root;                            // start from root

        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))          // if character is missing
                node->put(word[i], new Node());       // create a new node

            node = node->get(word[i]);                // move to next node
        }

        node->setEnd();                               // mark complete word
    }

    bool checkIfPrefixExists(string word) {
        Node* node = root;                            // start from root

        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                return false;                         // prefix path does not exist

            node = node->get(word[i]);                // move to next node

            if (!node->isEnd())
                return false;                         // prefix is not a complete word
        }

        return true;                                  // all prefixes exist
    }
};

string completeString(int n, vector<string>& a) {
    Trie trie;                                        // create trie

    for (auto& it : a)
        trie.insert(it);                              // insert all words

    string longest = "";                              // store answer

    for (auto& it : a) {
        if (trie.checkIfPrefixExists(it)) {           // check all prefixes
            if (it.length() > longest.length())
                longest = it;                         // choose longer word
            else if (it.length() == longest.length() && it < longest)
                longest = it;                         // choose lexicographically smaller word
        }
    }

    if (longest == "")
        return "None";                                // no valid word exists

    return longest;                                   // return answer
}