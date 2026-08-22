//statement- Given start, end, arr of n nos. At each step, start is multiplied by any num in arr & then a mod operation with 100000 is done to get new start. Your task is to find min steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1


//(optimal) -dijkstras using q t.c- O(10^5 * n)  s.c- O(10^5 * n)
int minimumMultiplications(vector<int> &arr, int start, int end) {
    queue<pair<int, int>> q; // Create a queue for storing numbers as a result of multiplication of numbers in array & start number.
    q.push({start, 0});
    vector<int> dist(100000, 1e9); // Create a dist array to store no. of multiplications to reach a particular number from start number.
    dist[start] = 0;
    int mod = 100000;

    while (!q.empty()) { // Multiply start no. with each of numbers in arr until we get end no.
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr) {
            int num = (it * node) % mod;

            if (steps + 1 < dist[num]) { // If no. of multiplications are less than before in order to reach a number, we update dist array.
                dist[num] = steps + 1;

                if (num == end) // Whenever we reach end number return calculated steps
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1; // If end no. is unattainable.
}