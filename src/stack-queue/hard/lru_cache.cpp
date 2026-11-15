// statement- Design ds that follows constraints of Least Recently Used (LRU) cache. Implement LRUCache class: LRUCache(int capacity): initialize LRU cache with +ve size capacity.
//            int get(int key): Returns value of key if key exists else -1. void put(int key,int value): Update value of key if key exists. Otherwise, add key-value pair to cache.
//            If no of keys exceeds capacity from this operation, evict least recently used key. functions get and put must each run in O(1) average time complexity.
// Note : In Input is provided in 2D arr format where first no in each arr denotes operation (1-put, 2-get) to perform. next integers are values used for operation


// (optimal) t.c- O(1)  s.c- O(capacity)
class LRUCache {
public:
    class Node { // Doubly linked list node to store key and value
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    Node* head = new Node(-1, -1); // Dummy head representing the Most Recently Used (MRU) end
    Node* tail = new Node(-1, -1); // Dummy tail representing the Least Recently Used (LRU) end
    int cap;
    unordered_map<int, Node*> m; // Hash map for O(1) node lookup
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail; // Initially connect dummy head and tail
        tail->prev = head;
    }
    void addNode(Node* newnode) { // Inserts a node right after the head (MRU position)
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deleteNode(Node* delnode) { // Removes a specific node from the linked list
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    int get(int key) {
        if (m.find(key) != m.end()) { // If key exists in cache
            Node* resNode = m[key];
            int ans = resNode->val;
            m.erase(key);
            deleteNode(resNode); 
            addNode(resNode); // Move the accessed node to the MRU position
            m[key] = head->next; // Update map with the new node pointer
            return ans;
        }
        return -1; // Key not found
    }
    void put(int key, int value) {
        if (m.find(key) != m.end()) { // If key already exists, remove the old node
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }
        if (m.size() == cap) { // If capacity is reached, evict the LRU node
            m.erase(tail->prev->key); // Erase LRU key from map
            deleteNode(tail->prev); // Remove node just before tail
        }
        addNode(new Node(key, value)); // Insert the new key-value pair at MRU position
        m[key] = head->next; // Store the new node pointer in the map
    }
};