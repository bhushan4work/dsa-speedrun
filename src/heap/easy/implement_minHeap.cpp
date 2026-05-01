class minHeap {
private:
    vector<int> heap;

    // Moves element at index i upward to restore min-heap property
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;  // parent index

            // If parent is greater than curr node, swap
            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;  // continue moving up
            } else {
                break;  // heap property satisfied
            }
        }
    }

    // Moves element at index i downward to restore min-heap property
    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int left = 2 * i + 1;   // left child index
            int right = 2 * i + 2;  // right child index
            int smallest = i;       // assume curr is smallest

            // Compare with left child
            if (left < n && heap[left] < heap[smallest]) smallest = left;

            // Compare with right child
            if (right < n && heap[right] < heap[smallest]) smallest = right;

            // If smallest is not curr node, swap & continue
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else {
                break;  // heap property restored
            }
        }
    }

public:
    // Insert new element into heap
    void push(int x) {
        heap.push_back(x);                 // add at end
        heapifyUp(heap.size() - 1);        // restore heap property (bottom → up)
    }

    // Remove min element (root of heap)
    void pop() {
        if (heap.empty()) return;

        // Replace root with last element
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property (top → down)
        if (!heap.empty())
            heapifyDown(0);
    }

    // Return min element (root)
    int peek() {
        if (heap.empty()) return -1;  // edge case
        return heap[0];
    }

    // Return no of elements in heap
    int size() {
        return heap.size();
    }
};