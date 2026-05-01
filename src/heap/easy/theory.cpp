class BinaryHeap{
public:
    int capacity; // Max elements that can be stored in heap
    int size; // Curr no of elements in heap
    int *arr; // Arr for storing keys

    BinaryHeap(int cap){
        capacity = cap; // Assigning capacity
        size = 0; // Initially size of heap is zero
        arr = new int[capacity]; // Creating an arr
    }

    int parent(int i){ 
        return (i - 1) / 2; // Returns parent of ith Node
    }

    int left(int i){
        return 2 * i + 1; // Returns left child of ith Node
    }

    int right(int i){
        return 2 * i + 2;  // Returns right child of ith Node
    }

    // Insert new key x
    void Insert(int x){
        if (size == capacity){
            cout << "Binary Heap Overflow" << endl;
            return;
        }

        arr[size] = x; // Insert new element at end

        int k = size; // Store index, for checking heap property
        size++; // Increase size

        // Fix min heap property
        while (k != 0 && arr[parent(k)] > arr[k]){
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    void Heapify(int ind){
        int ri = right(ind); // Right child
        int li = left(ind); // Left child

        int smallest = ind; // Initially assume violated value is min

        if (li < size && arr[li] < arr[smallest]) smallest = li;
        if (ri < size && arr[ri] < arr[smallest]) smallest = ri;

        // If Min among 3 nodes is not parent itself,
        //n swap and call Heapify recursively
        if (smallest != ind){
            swap(&arr[ind], &arr[smallest]);
            Heapify(smallest);
        }
    }

    int getMin(){
        return arr[0];
    }

    int ExtractMin(){
        if (size <= 0) return INT_MAX;

        if (size == 1) {
            size--;
            return arr[0];
        }

        int mini = arr[0];

        arr[0] = arr[size - 1]; // Copy last Node value to root Node

        size--;

        Heapify(0); // Call heapify on root node

        return mini;
    }

    void Decreasekey(int i, int val){
        arr[i] = val; // Updating new value

        // Fixing Min heap
        while (i != 0 && arr[parent(i)] > arr[i]){
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i){
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " " << endl;
        }
    }
};
