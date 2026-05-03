// statement- arr is sorted in way that every element is at max k distance away from its sorted position.
//            It means if we completely sort arr,n index of element can go from i - k to i + k where i is index in given arr. task is to completely sort arr


//(optimal) t.c- O(nlogk)  s.c- O(k)
vector<int> sortNearlySortedArray(vector<int> &arr, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap; // Create minheap using priority_queue with greater comparator
    vector<int> result; // Store final sorted result

    for (int i = 0; i <= k && i < arr.size(); i++){ // Push first k+1 elements into heap
        minHeap.push(arr[i]);
    }

    // add remaining elements of array
    for (int i = k + 1; i < arr.size(); i++){
        // Push smallest element from heap to result
        result.push_back(minHeap.top());
        minHeap.pop();

        minHeap.push(arr[i]); // Push curr element into heap
    }

    // Pop remaining elements from heap
    while (!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return result;
}