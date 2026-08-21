//statement- You are in city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads betw some intersections. inputs are generated such that you can reach any intersection from any other intersection & that there is at most 1 road betw any 2 intersections. 
//           given integer n & 2D integer arr ‘roads’ where roads[i] = [ui, vi, timei] means that there is road betw intersections ui & vi that takes timei min to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in shortest amt of time.
//           Return no of ways you can arrive at your destination in shortest amt of time. Since ans may be large, return it modulo 109 + 7


//(optimal) t.c- O(elogv)  s.c- O(n)
int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n]; // Create the adjacency list to represent intersections and roads

    for (auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // Create a priority queue for Dijkstra's algorithm
    vector<long long> dist(n, LLONG_MAX); // Initialize distance array with long long to avoid overflow
    vector<int> ways(n, 0); // Initialize ways array to count shortest paths
    dist[0] = 0; // Distance for the source node (0) is 0
    ways[0] = 1; // There's 1 way to reach the source (itself)
    pq.push({0, 0}); // Push the source node with distance 0
    int mod = (int)(1e9 + 7); // Define the modulo value for large numbers

    while (!pq.empty()) { // Perform Dijkstra's algorithm
        long long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) { // Iterate through adjacent nodes
            int adjNode = it.first; // Next intersection
            long long edW = it.second; // Time taken to travel the road

            if (dis + edW < dist[adjNode]) { // If a strictly shorter path is found
                dist[adjNode] = dis + edW; // Update the minimum distance
                pq.push({dist[adjNode], adjNode}); // Push the new node with updated distance
                ways[adjNode] = ways[node]; // Reset ways to the current node's ways
            }
            else if (dis + edW == dist[adjNode]) { // If another path with the same shortest distance is found
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Add to the number of ways
            }
        }
    }
    return ways[n - 1] % mod; // Return the number of ways to reach destination (n-1)
}