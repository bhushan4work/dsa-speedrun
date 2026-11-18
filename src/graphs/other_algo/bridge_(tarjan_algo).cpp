//statement- Given undirected connected Graph with V vertices (Numbered from 0 to V-1) & E edges. An edge is represented [ai, bi] denoting that there is an edge from vertex ai to bi .
//           An edge is called a bridge if its removal makes some vertex unable to reach another vertex. return all bridges in the graph in any order.


// (brute) t.c- O(e * (v + e))  s.c- O(v + e)
int reachableCount(int vertices, vector<vector<int>>& edges, int skippedEdge) { // Counts reachable vertices after skipping one edge.
    vector<vector<int>> adjacency(vertices);
    for (int edgeId = 0; edgeId < static_cast<int>(edges.size()); edgeId++) { // Build the graph without the selected edge.
        if (edgeId == skippedEdge) { // Skip only the current edge occurrence.
            continue;
        }
        int first = edges[edgeId][0];
        int second = edges[edgeId][1];
        adjacency[first].push_back(second);
        adjacency[second].push_back(first);
    }
    vector<bool> visited(vertices, false);
    stack<int> pending;
    pending.push(0); // Start traversal from vertex zero.
    visited[0] = true;
    int reached = 0;
    while (!pending.empty()) { // Traverse the remaining graph using DFS.
        int node = pending.top();
        pending.pop();
        reached++; // Count the current reachable vertex.
        for (int neighbor : adjacency[node]) { // Visit all unvisited neighbors.
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                pending.push(neighbor);
            }
        }
    }
    return reached; // Return total reachable vertices.
}
vector<vector<int>> findBridges(int vertices, vector<vector<int>>& edges) { // Finds bridges by removing every edge once.
    vector<vector<int>> bridges;
    for (int edgeId = 0; edgeId < static_cast<int>(edges.size()); edgeId++) { // Remove each edge occurrence and test connectivity.
        if (reachableCount(vertices, edges, edgeId) < vertices) { // If fewer vertices are reachable, the edge is a bridge.
            int first = min(edges[edgeId][0], edges[edgeId][1]);
            int second = max(edges[edgeId][0], edges[edgeId][1]);
            bridges.push_back({first, second});
        }
    }
    sort(bridges.begin(), bridges.end()); // Sort bridge endpoints for deterministic output.
    return bridges;
}



// (optimal) -using tarjans algo t.c- O(v + e)  s.c- O(v + e)
struct Frame {
    int node;
    int parent;
    int parentEdge;
    int nextIndex;
};
vector<vector<int>> findBridges(int vertices, vector<vector<int>>& edges) { // Finds bridges using discovery and low-link times.
    vector<vector<pair<int, int>>> adjacency(vertices);
    for (int edgeId = 0; edgeId < static_cast<int>(edges.size()); edgeId++) { // Store a unique id with every undirected edge occurrence.
        int first = edges[edgeId][0];
        int second = edges[edgeId][1];
        adjacency[first].push_back({second, edgeId});
        adjacency[second].push_back({first, edgeId});
    }
    vector<int> discovery(vertices, -1);
    vector<int> low(vertices, -1);
    vector<vector<int>> bridges;
    int timer = 0;
    for (int start = 0; start < vertices; start++) { // Start a DFS tree from every unvisited vertex.
        if (discovery[start] != -1) { // Skip already discovered components.
            continue;
        }
        stack<Frame> frames;
        discovery[start] = low[start] = timer++; // Assign discovery and low time to the start vertex.
        frames.push({start, -1, -1, 0});
        while (!frames.empty()) {
            Frame& frame = frames.top();
            int node = frame.node;
            if (frame.nextIndex < static_cast<int>(adjacency[node].size())) { // Process the next adjacent edge from the current frame.
                auto [neighbor, edgeId] = adjacency[node][frame.nextIndex++];
                if (edgeId == frame.parentEdge) { // Skip only the exact edge used to enter the vertex.
                    continue;
                }
                if (discovery[neighbor] == -1) { // Tree edge: discover a new vertex.
                    discovery[neighbor] = low[neighbor] = timer++;
                    frames.push({neighbor, node, edgeId, 0});
                } else { // Back edge: update low-link using discovery time.
                    low[node] = min(low[node], discovery[neighbor]);
                }
                continue;
            }
            Frame finished = frame; // Finish the vertex after all edges are processed.
            frames.pop();
            if (finished.parent == -1) { // Root has no parent to update.
                continue;
            }
            low[finished.parent] = min(low[finished.parent], low[finished.node]); // Propagate low-link value upward.
            if (low[finished.node] > discovery[finished.parent]) { // If child cannot reach parent or above, edge is a bridge.
                bridges.push_back({min(finished.parent, finished.node), max(finished.parent, finished.node)});
            }
        }
    }
    sort(bridges.begin(), bridges.end()); // Sort bridge endpoints for deterministic output.
    return bridges;
}