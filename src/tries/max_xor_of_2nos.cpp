//statement- Given an integer arr, return max result of nums[i] XOR nums[j], where 0 <= i <= j < n


// (optimal) t.c- O(n * b), s.c- O(n * b * 2)
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() { // Creates one trie node with no bit paths yet.
        children[0] = children[1] = nullptr; // Both bit directions start as empty.
    }
};

int getMaxBit(const vector<int>& nums) { // Returns the highest set bit position among all numbers.
    int maxNum = 0; // Stores the largest number because its highest bit is enough for the search.
    for (int num : nums) { // Scan all numbers to find the one with the highest useful bit.
        if (num > maxNum) {
            maxNum = num;
        }
    }

    if (maxNum == 0) { // If every number is zero, bit position zero is enough.
        return 0;
    }

    return (int)log2(maxNum);
}

void insertNumber(TrieNode* root, int num, int maxBit) { // Inserts one number into the bit trie.
    TrieNode* node = root; // Start insertion from the trie root.
    for (int bit = maxBit; bit >= 0; bit--) { // Insert the number from the most significant useful bit to the lowest bit.
        int currentBit = (num >> bit) & 1; // Extract the current bit so the correct trie path can be chosen.
        if (node->children[currentBit] == nullptr) { // Create a new node only when this bit path appears for the first time.
            node->children[currentBit] = new TrieNode();
        }

        node = node->children[currentBit]; // Move deeper for the next lower bit.
    }
}

int getBestXor(TrieNode* root, int num, int maxBit) { // Finds the best XOR value that the current number can make with the trie.
    TrieNode* node = root; // Start searching from the trie root.
    int currentXor = 0; // Builds the XOR value bit by bit.
    for (int bit = maxBit; bit >= 0; bit--) { // Match the current number against the trie from high bit to low bit.
        int currentBit = (num >> bit) & 1; // Extract the current bit of the number.
        int toggledBit = currentBit ^ 1; // The opposite bit is preferred because it creates XOR bit 1.

        if (node->children[toggledBit] != nullptr) { // Take the opposite path when it exists.
            currentXor |= (1 << bit);
            node = node->children[toggledBit];
        }
        else { // Otherwise only the same-bit path is available.
            node = node->children[currentBit];
        }
    }

    return currentXor;
}

int findMaximumXOR(vector<int>& nums) { // Returns the maximum XOR value by matching each number against a binary trie.
    int maxBit = getMaxBit(nums); // The trie works only across useful bits.
    TrieNode* root = new TrieNode(); // Root of the binary trie.
    for (int num : nums) { // Insert every number first so all partner paths become available.
        insertNumber(root, num, maxBit);
    }

    int answer = 0; // Stores the best XOR value seen across all numbers.
    for (int num : nums) { // Check the best partner value for every number in the array.
        int currentXor = getBestXor(root, num, maxBit);
        if (currentXor > answer) {
            answer = currentXor;
        }
    }
    
    return answer;
}