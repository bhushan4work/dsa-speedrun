//statement- Given an arr consisting of non-negative integers, queries arr, where queries[i] = [xi, mi]. ans to ith query is max bitwise XOR value of xi & any element
//           of nums that doesnt exceed mi. ans is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then ans is -1.
//           Return an integer arr ans where ans.length == queries.length & ans[i] is ans to ith query


// (optimal) t.c- O(nlogn + qlogq), s.c- O(n + q)
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() { // Create an empty trie node with no bit paths yet.
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;
public:
    BinaryTrie() { // Create one empty trie.
        root = new TrieNode();
    }

    void insert(int num) { // Insert one number into the trie from bit 30 down to bit 0.
        TrieNode* node = root;
        for (int bit = 30; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1; // Extract the current bit so the correct trie path can be used.
            if (node->children[currentBit] == nullptr) { // Create the path only when this bit branch does not exist yet.
                node->children[currentBit] = new TrieNode();
            }

            node = node->children[currentBit]; // Move to the next lower bit.
        }
    }

    int getMaxXor(int num) { // Find the largest XOR value possible with the given number.
        TrieNode* node = root;
        int maxXor = 0; // Build the answer bit by bit.
        for (int bit = 30; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1; // Extract the current bit of the query number.
            int oppositeBit = currentBit ^ 1; // The opposite bit is preferred because it would produce XOR bit 1.
            if (node->children[oppositeBit] != nullptr) { // Take the opposite path when it exists to improve the XOR result.
                maxXor |= (1 << bit);
                node = node->children[oppositeBit];
            }
            else { // If the better path does not exist, continue with the available same-bit path.
                node = node->children[currentBit];
            }
        }

        return maxXor;
    }
};

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) { // Returns max XOR ans for each query using offline sorting & a binary trie.
    sort(nums.begin(), nums.end()); // Sort numbers so valid values can be inserted gradually as limits grow.

    vector<int> answer(queries.size(), -1); // Store answers in original query order.
    vector<array<int, 3>> offlineQueries; // Store each query as {m, x, originalIndex} so sorting by limit becomes easy.
    for (int i = 0; i < (int)queries.size(); i++) {
        offlineQueries.push_back({queries[i][1], queries[i][0], i});
    }

    sort(offlineQueries.begin(), offlineQueries.end()); // Process smaller limits first so inserted numbers never need to be removed.

    BinaryTrie trie;
    int index = 0; // Point to the next number in nums that has not been inserted yet.
    for (const auto& query : offlineQueries) {
        int m = query[0];
        int x = query[1];
        int originalIndex = query[2];
        while (index < (int)nums.size() && nums[index] <= m) { // Insert every number that becomes valid for the current limit.
            trie.insert(nums[index]);
            index++;
        }

        if (index == 0) { // If no number has been inserted, this query has no valid answer.
            answer[originalIndex] = -1;
        }
        else { // Search only among valid inserted numbers and store the answer at the original position.
            answer[originalIndex] = trie.getMaxXor(x);
        }
    }
    
    return answer;
}