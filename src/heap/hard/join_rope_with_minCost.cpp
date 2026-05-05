//statement- Given arr[] of rope lengths, connect all ropes into single rope with min total cost. cost to connect 2 ropes is sum ofir lengths 


//(brute) t.c- O(n^2 * logn)  s.c- O(n)
int minCost(vector<int>& arr) {
    int totalCost = 0;

    while (arr.size() > 1) {
        sort(arr.begin(), arr.end()); // Sort ropes to get 2 smallest lengths

        // Pick two smallest ropes
        int first = arr[0];
        int second = arr[1];

        // Remove two ropes from array
        arr.erase(arr.begin());
        arr.erase(arr.begin());

        int cost = first + second; // Cost of connecting 2 ropes
        totalCost += cost; 

        arr.push_back(cost); // Push new rope back into array
    }

    return totalCost;
}


//(optimal) t.c- O(nlogn)  s.c- O(n)
int minCost(vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end()); // Create min priority queue
    int ans = 0;

    while (pq.size() > 1) {

        // Extract shortest two ropes from pq
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a + b ;

        ans += sum; // Connect ropes: update result
        pq.push(sum); // insert new rope to pq
    }

    return ans;
}