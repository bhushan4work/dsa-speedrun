//statement- Given an undirected graph with V vertices & adjacency list adj. Find all vertices removing which (& edges through it) would increase number of connected components in graph. graph may be initially
//           disconnected.. Return vertices in ascending order. If there are no such vertices then returns a list containing -1. Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in graph


// (brute) t.c- O(v * (v + e))  s.c- O(v + e)
int countComponents(int vertices, const vector<vector<int>>& adjacency, int removedVertex) { // Function to count components while ignoring one vertex.
    vector<bool> visited(vertices, false);
    int components = 0;
    for (int start = 0; start < vertices; start++) { // Start traversal from every remaining unvisited vertex.
        if (start == removedVertex || visited[start]) { 
            continue;
        }
        components++;
        stack<int> pending;
        pending.push(start);
        visited[start] = true;
        while (!pending.empty()) {
            int node = pending.top();
            pending.pop();
            for (int neighbor : adjacency[node]) {
                if (neighbor != removedVertex && !visited[neighbor]) { // Ignore the removed vertex during traversal.
                    visited[neighbor] = true;
                    pending.push(neighbor);
                }
            }
        }
    }
    return components;
}
vector<int> articulationPoints(int vertices, vector<vector<int>>& edges) { // Function to find articulation points by removing every vertex.
    vector<vector<int>> adjacency(vertices);
    for (const auto& edge : edges) { // Build the undirected adjacency list once.
        adjacency[edge[0]].push_back(edge[1]);
        adjacency[edge[1]].push_back(edge[0]);
    }
    int originalComponents = countComponents(vertices, adjacency, -1);
    vector<int> answer;
    for (int removed = 0; removed < vertices; removed++) { // Compare component counts after removing every candidate vertex.
        int remainingComponents = countComponents(vertices, adjacency, removed);
        if (remainingComponents > originalComponents) { // If removing the vertex increases components, it's an articulation point.
            answer.push_back(removed);
        }
    }
    if (answer.empty()) { // Return -1 when no articulation point exists.
        return {-1};
    }
    return answer;
}



// (optimal) -using tarjans algo t.c- O(v + e)  s.c- O(v + e)
struct Frame { // Struct to simulate the recursive call stack for iterative DFS.
    int node;
    int parent;
    int parentEdge;
    int nextIndex;
    int children;
};
vector<int> articulationPoints(int vertices, vector<vector<int>>& edges) { // Function to find articulation points using low-link values.
    vector<vector<pair<int, int>>> adjacency(vertices);
    for (int edgeId = 0; edgeId < static_cast<int>(edges.size()); edgeId++) { // Store a unique id with every undirected edge occurrence.
        int first = edges[edgeId][0];
        int second = edges[edgeId][1];
        adjacency[first].push_back({second, edgeId});
        adjacency[second].push_back({first, edgeId});
    }
    vector<int> discovery(vertices, -1);
    vector<int> low(vertices, -1);
    vector<int> parent(vertices, -1);
    vector<bool> isArticulation(vertices, false);
    int timer = 0;
    for (int start = 0; start < vertices; start++) { // Start a DFS tree from every undiscovered vertex.
        if (discovery[start] != -1) {
            continue;
        }
        discovery[start] = low[start] = timer++;
        stack<Frame> frames;
        frames.push({start, -1, -1, 0, 0});
        while (!frames.empty()) {
            Frame& frame = frames.top();
            int node = frame.node;
            if (frame.nextIndex < static_cast<int>(adjacency[node].size())) { // Process the next adjacent edge from the current frame.
                auto [neighbor, edgeId] = adjacency[node][frame.nextIndex++];
                if (edgeId == frame.parentEdge) {
                    continue;
                }
                if (discovery[neighbor] == -1) {
                    frame.children++;
                    parent[neighbor] = node;
                    discovery[neighbor] = low[neighbor] = timer++;
                    frames.push({neighbor, node, edgeId, 0, 0});
                } else {
                    low[node] = min(low[node], discovery[neighbor]);
                }
                continue;
            }
            Frame finished = frame; // Finish the vertex and apply root or non-root rules.
            frames.pop();
            if (finished.parent == -1) {
                if (finished.children > 1) { // Root of DFS tree is an articulation point if it has more than 1 child.
                    isArticulation[finished.node] = true;
                }
                continue;
            }
            low[finished.parent] = min(low[finished.parent], low[finished.node]);
            if (parent[finished.parent] != -1 && low[finished.node] >= discovery[finished.parent]) { // Articulation point condition for non-root nodes.
                isArticulation[finished.parent] = true;
            }
        }
    }
    vector<int> answer;
    for (int node = 0; node < vertices; node++) {
        if (isArticulation[node]) {
            answer.push_back(node);
        }
    }
    if (answer.empty()) { // Return -1 when no articulation point exists.
        return {-1};
    }
    return answer;
}
