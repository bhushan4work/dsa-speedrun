//statement- Given head of a special LL of n nodes where each node contains an additional ptr called 'random' which can point to any node in list or null. Construct a deep copy of LL where, n new nodes are created
//           with corresponding values as original LL. random ptrs point to corresponding new nodes as per their arrangement in original list. Return head of newly constructed LL.
// Note: For custom input, n x 2 matrix is taken with each row having 2 values:[ val, random_ind] where val: an int representing ListNode.val, random_ind: index of node (0 - n-1) that random ptr points to else -1


//(brute) t.c- O(n)  s.c- O(n)
class Node {
public:
    int data;
    Node* next;
    Node* random;
    Node(int value) { // Constructor initializes the node value and both pointers.
        data = value;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) { // An empty list has no nodes to clone.
        return nullptr;
    }

    unordered_map<Node*, Node*> nodeMap;
    Node* current = head;
    while (current != nullptr) { // Create one cloned node for every original node. The map keeps the original-to-clone relationship.
        nodeMap[current] = new Node(current->data);
        current = current->next;
    }

    current = head;
    while (current != nullptr) { // Connect the next and random pointers of each cloned node using the mapping.
        nodeMap[current]->next = nodeMap[current->next];
        nodeMap[current]->random = nodeMap[current->random];
        current = current->next;
    }

    return nodeMap[head]; // The clone corresponding to the original head becomes the head of the copied list.
}



//(optimal) t.c- O(n)  s.c- O(1)
class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int value) { // Constructor initializes the node value and both pointers.
        data = value;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) { // Function to clone a linked list using interleaved nodes.
    if (head == nullptr) { // An empty list has no nodes to clone.
        return nullptr;
    }

    Node* current = head;
    while (current != nullptr) { // Insert each cloned node immediately after its original node.
        Node* clonedNode = new Node(current->data);
        clonedNode->next = current->next;
        current->next = clonedNode;
        current = clonedNode->next; // Move to the next original node, skipping the clone.
    }

    current = head;
    while (current != nullptr) { // Set the random pointer of every cloned node.
        if (current->random != nullptr) {
            current->next->random = current->random->next;
        }
        current = current->next->next; // Move to the next original node.
    }

    current = head;
    Node* clonedHead = head->next;
    while (current != nullptr) { // Separate the interleaved structure back into the original and cloned linked lists while restoring the original links.
        Node* clonedNode = current->next;
        current->next = clonedNode->next; // Restore the original node's next pointer.
        if (clonedNode->next != nullptr) { // Connect the clone to the next clone, if one exists.
            clonedNode->next = clonedNode->next->next;
        }
        
        current = current->next; // Move to the next original node.
    }

    return clonedHead; // The first cloned node is the head of the copied list.
}