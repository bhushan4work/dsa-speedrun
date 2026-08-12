// statement- There are total of n courses you have to take, labeled from 0 to n-1. given an arr prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//             For example, pair [0, 1], indicates that to take course 0 you have to first take course 1. Return ordering of courses you should take to finish all. If there are many ans, return any of them. If impossible to finish all courses, return empty arr


//(optimal) using bfs t.c- O(v + e)  s.c- O(v + e)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses); // Build adjacency list
    vector<int> inDegree(numCourses, 0); // Build in-degree array

    for (auto& pre : prerequisites) { // Fill adjacency and in-degree
        int a = pre[0], b = pre[1];
        adj[b].push_back(a);
        inDegree[a]++;
    }

    queue<int> q; // Initialize queue with zero in-degree nodes
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order; // Create result list

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int nei : adj[node]) { // Reduce in-degree of neighbors
            inDegree[nei]--;
            if (inDegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if ((int)order.size() == numCourses) { // Return order if valid, else empty
        return order;
    }
    return {};
}