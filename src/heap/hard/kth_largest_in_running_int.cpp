// statement- Implement class KthLargest to find kth largest no in stream. It should have following methods:
//               KthLargest(int k, int [] nums) Initializes obj with int k & initial stream of no in nums
//               int add(int val) Appends integer val to stream & returns kth largest element in stream
//               Note that it is kth largest element in sorted order, not kth distinct element


//(optimal) t.c- O(logk)  s.c- O(k)
priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the top k largest elements
int size;

KthLargest(int k, vector<int> &nums){  // adds all initial elements from given arr in heap maintaining k-size
    size = k;
    for (int num : nums){
        minHeap.push(num);

        if (minHeap.size() > k){ // If heap exceeds size k, remove smallest element
            minHeap.pop();
        }
    }
}

int add(int val){ // Adds a new value to stream & returns k-th largest for each
    minHeap.push(val); // Insert new element

    if (minHeap.size() > size){ // If size exceeds k, remove smallest (to maintain top k largest)
        minHeap.pop();
    }

    return minHeap.top(); // top of min-heap is k-th largest
}
