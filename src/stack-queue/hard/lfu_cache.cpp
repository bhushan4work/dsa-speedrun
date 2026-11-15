// statement- Design & implement a data structure for a Least Frequently Used (LFU) cache. Implement LFUCache class with following functions: LFUCache(int capacity): Initialize object with specified capacity.
//            int get(int key): Retrieve value of key if it exists in cache; otherwise, return -1. void put(int key, int value): Update value of key if it is present in cache, or insert key if it is not already present.
//            If cache has reached its capacity, invalidate & remove least frequently used key before inserting a new item. In case of a tie (i.e., two or more keys with same freq), invalidate least recently used key.
//            A use counter is maintained for each key in cache to determine least frequently used key. key with smallest use counter is considered least frequently used. When a key is first inserted into cache,
//            its use counter is set to 1 due to put operation. use counter for a key in cache is incremented whenever a get or put operation is called on it. Ensure that functions get & put run in O(1) avg tc.


// (optimal) t.c- O(1)  s.c- O(capacity)
struct Node {
    int key;
    int value;
    int freq;
    list<int>::const_iterator it;
};
class LFUCache {
public:
    int capacity;
    int minFreq;
    unordered_map<int, Node> keyToNode;
    unordered_map<int, list<int>> freqToList;
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {} // Initialize cache capacity and minimum frequency
    int get(int key) {
        if (!keyToNode.count(key)) { // Return -1 if key is not found
            return -1;
        }
        Node& node = keyToNode[key];
        touch(node); // Update frequency and position of the accessed node
        return node.value;
    }
    void put(int key, int value) {
        if (capacity == 0) { // Do nothing if cache capacity is zero
            return;
        }
        if (keyToNode.count(key)) { // If key exists, update value and touch node
            Node& node = keyToNode[key];
            node.value = value;
            touch(node);
            return;
        }
        if (keyToNode.size() == capacity) { // Evict LRU key from the minFreq list if at capacity
            const int keyToEvict = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            keyToNode.erase(keyToEvict);
        }
        minFreq = 1; // Reset minFreq to 1 for the newly inserted node
        freqToList[1].push_front(key);
        keyToNode[key] = {key, value, 1, cbegin(freqToList[1])}; // Map new key to its node details
    }
    void touch(Node& node) {
        const int prevFreq = node.freq; // Store previous frequency
        const int newFreq = ++node.freq; // Increment and store new frequency
        freqToList[prevFreq].erase(node.it); // Remove the node from its previous frequency list
        if (freqToList[prevFreq].empty()) { // If the previous frequency list becomes empty, remove it
            freqToList.erase(prevFreq);
            if (prevFreq == minFreq) { // Update global minFreq if it was equal to the removed frequency
                ++minFreq;
            }
        }
        freqToList[newFreq].push_front(node.key); // Insert the node into the front of the new frequency list
        node.it = cbegin(freqToList[newFreq]); // Update the node's iterator to its new position
    }
};