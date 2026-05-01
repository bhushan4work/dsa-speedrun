// Heapify func to maintain max-heap property
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest]) largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest]) largest = right;

    // If root is not largest, swap & continue heapifying
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N){
    // Start from last non-leaf node & heapify each node
    for (int i = (N / 2) - 1; i >= 0; i--){
        heapify(arr, N, i);
    }
}