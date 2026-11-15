// statement- Implement class that finds median from datastream. median is middle value. If size is even, median is mean of 2 middle values. Implement MedianFInder class as follows:
//            MedianFinder() initializes MedianFinder obj. void addNum(int num) adds integer num to ds. double findMedian() returns median of all elements so far. ans within 10-5 of actual ans will be accepted


//(brute) t.c- O(nlogn)  s.c- O(n)
vector<int> numbers; // Global storage for the stream values.
void addNum(int value) {
    numbers.push_back(value); // Preserve the newest stream value.
}
double findMedian() {
    vector<int> ordered = numbers; // Copy values so insertion storage stays unchanged.
    sort(ordered.begin(), ordered.end()); // Sort the copy to expose the middle position.
    int size = ordered.size();
    int middle = size / 2;
    if (size % 2 == 1) { // Odd size has one value at the middle index.
        return ordered[middle];
    }
    return ordered[middle - 1] / 2.0 + ordered[middle] / 2.0; // Half-value addition avoids integer overflow.
}



//(better) t.c- O(n)  s.c- O(n)
vector<int> ordered; // Array to maintain the sorted stream of numbers

void addNum(int value) {
    auto position = lower_bound(ordered.begin(), ordered.end(), value); // Find the correct position to maintain sorted order
    ordered.insert(position, value); // Insert the value at the found position (O(N) shifting)
}

double findMedian() {
    int size = ordered.size(); // Get current number of elements
    int middle = size / 2; // Calculate the middle index
    if (size % 2 == 1) { // If size is odd, median is the exact middle element
        return ordered[middle];
    }
    return ordered[middle - 1] / 2.0 + ordered[middle] / 2.0; // Half-value addition to avoid integer overflow for even sizes
}



//(optimal) -using minheap, maxheap t.c- O(logn)  s.c- O(n)
priority_queue<int> lower; // Max-heap storing the smaller half of the numbers
priority_queue<int, vector<int>, greater<int>> upper; // Min-heap storing the larger half of the numbers
void addNum(int value) {
    lower.push(value); // Add the new value to the lower half initially
    upper.push(lower.top()); // Move the largest value from the lower half to the upper half
    lower.pop(); // Remove the moved value from the lower half
    if (upper.size() > lower.size()) { // Maintain size property: lower can have at most 1 more element than upper
        lower.push(upper.top()); // Move the smallest upper value back to lower
        upper.pop(); // Remove it from the upper half
    }
}
double findMedian() {
    if (lower.size() == upper.size()) { // If both halves are equal, median is average of the two middle elements
        return lower.top() / 2.0 + upper.top() / 2.0; // Divided by 2.0 individually to prevent integer overflow
    }
    return lower.top(); // If sizes differ, the lower half holds the extra middle element
}