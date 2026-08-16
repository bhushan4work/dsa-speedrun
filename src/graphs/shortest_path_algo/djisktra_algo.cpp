//statement- Given weighted, undirected, & connected graph of V vertices & adj list adj where adj[i] is list of lists containing 2 integers where first integer of each list j denotes there is an edge betw i & j, 2nd integers corresponds to wt of that edge. 
//           given source vertex S & have to Find shortest dist of all vertex from source vertex S. return list of integers denoting shortest dist betw each node & Source vertex S
// Note: Graph doesn’t contain any negative weight cycle


//(optimal) -using set t.c- O(elogv)  s.c- O(v + e)
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Create a set ds for storing nodes as a pair {dist,node} where dist is distance from source to node.
    // set stores nodes in ascending order of distances.
    set<pair<int, int>> st;

    // Initialising dist list with a large number to indicate nodes are unvisited initially.
    // This list contains distance from source to nodes.
    vector<int> dist(V, 1e9);           

    st.insert({0, S});                      // Insert source node with a distance of 0.
    dist[S] = 0;                            // Source initialised with dist = 0

    while(!st.empty()) {                    // Traverse graph until set is empty
        auto it = *(st.begin());            // Extract node with minimum distance
        int node = it.second; 
        int dis = it.first; 
        st.erase(it); 

        for(auto it : adj[node]) {          // Check for all adjacent nodes of extracted node
            int adjNode = it[0];            // Adjacent node
            int edgW = it[1];               // Weight of edge

            if(dis + edgW < dist[adjNode]) {// If new distance is smaller, update it
                if(dist[adjNode] != 1e9)    // Erase previous entry of adjacent node if it was visited previously with a larger cost.
                    st.erase({dist[adjNode], adjNode}); 
                
                dist[adjNode] = dis + edgW; // Update distance for adjacent node
                st.insert({dist[adjNode], adjNode}); // Insert adjacent node with updated distance into set
            }
        }
    }
    return dist;                            // Return list containing shortest distances from source to all nodes.
}



//(optimal) -using pq(min heap) t.c- O((v + e)logv)  s.c- O(v + e)
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, 1e9);                                   // Distance array initialized to large value
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Min-heap storing {distance, node}
    dist[src] = 0;                                              // Distance to source is 0
    pq.push({0, src});                                          // Push source into heap

    while (!pq.empty()) {                                       // Process nodes until heap is empty
        int d = pq.top().first;                                 // Extract node with minimum distance
        int node = pq.top().second;
        pq.pop();
        if (d > dist[node]) continue;                           // Skip if this distance is outdated
        
        for (auto it : adj[node]) {                             // Traverse all adjacent neighbors
            int next = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[next]) {                 // Relaxation check
                dist[next] = dist[node] + wt;                   // Update distance
                pq.push({dist[next], next});                    // Push updated distance into heap
            }
        }
    }
    return dist;
}