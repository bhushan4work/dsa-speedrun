//statement- given an arr of flights where flights[i] = [fromi, toi, pricei]. given 3 integers src, dst, k.
//           return cheapest price from src to desti with at most k stops. If there is no such route, return -1


//(optimal) -dijkstras algo using queue t.c- O(e)  s.c- O(v + e)
int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K){
    vector<pair<int, int>> adj[n]; // Create the adjacency list to represent airports and flights as a graph

    for (auto it : flights){
        adj[it[0]].push_back({it[1], it[2]});  // Add an edge from source to destination with the weight (cost)
    }

    queue<pair<int, pair<int, int>>> q; // Create a queue to store the node, its distance from the source, and the number of stops
    q.push({0, {src, 0}});  // Push the source node with 0 stops and 0 cost
    vector<int> dist(n, 1e9); // Create a distance array to store the minimum cost to reach each node
    dist[src] = 0;  // The distance from source to itself is 0

    while (!q.empty()){ // BFS traversal with a queue to process the nodes
        auto it = q.front();
        q.pop();
        int stops = it.first;  // Number of stops so far
        int node = it.second.first;  // Current node
        int cost = it.second.second;  // Cost to reach the current node

        if (stops > K) // If the number of stops exceeds K, continue to the next iteration
            continue;

        for (auto iter : adj[node]) { // Iterate over all the adjacent nodes (next destinations)
            int adjNode = iter.first;  // Next destination node
            int edW = iter.second;  // Cost of the flight to the next destination

            if (cost + edW < dist[adjNode] && stops <= K) { // If a shorter path to the adjacent node is found, update the dist
                dist[adjNode] = cost + edW;  // Update the distance
                q.push({stops + 1, {adjNode, cost + edW}});  // Push the new node with updated stops and cost
            }
        }
    }
    if (dist[dst] == 1e9) // If destination node is unreachable, return -1
        return -1;

    return dist[dst];  // Return the minimum cost to reach the destination
}