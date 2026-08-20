//statement- given a network of n nodes, labeled from 1 to n. also given times[i] = (ui, vi, wi), where ui is src, vi is target, wi is time it takes for signal to travel from src to target
//           We'll send signal from given node k. Return min time it takes for all the n nodes to receive signal. If its impossible for all n nodes to receive signal, return -1


//(optimal) t.c- O( (v + e)logv )  s.c- O(v + e)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1); // Create adjacency list

    for (auto& time : times) {
        int u = time[0], v = time[1], w = time[2];
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Initialize min-heap
    pq.push({0, k});
    vector<int> dist(n + 1, INT_MAX); // Initialize distance array
    dist[k] = 0;

    while (!pq.empty()) { // Process nodes
        int time = pq.top().first; // Get the node with the smallest time
        int node = pq.top().second;
        pq.pop();

        for (auto& [nbr, wt] : adj[node]) { // Traverse all neighbors of the current node
            if (dist[nbr] > time + wt) { // If shorter path is found to neighbor
                dist[nbr] = time + wt; // Update distance
                pq.push({dist[nbr], nbr}); // Push updated time to the priority queue
            }
        }
    }
    
    int ans = *max_element(dist.begin() + 1, dist.end()); // Get maximum time
    return ans == INT_MAX ? -1 : ans;
}