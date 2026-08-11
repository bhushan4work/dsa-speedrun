// statement- There are total of n courses you have to take, labeled from 0 to n-1. given an arr prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//            For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. Return true if you can finish all courses. Otherwise, return false


//(optimal) using bfs t.c- O(v + e)  s.c- O(v + e)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);  // Build adjacency list
    vector<int> inDegree(numCourses, 0);  // Build in-degree arr

     // Fill adjacency and in-degree
    for (auto& pre : prerequisites) {
        int a = pre[0], b = pre[1];
        adj[b].push_back(a);
        inDegree[a]++;
    }

     // Initialize queue & add nodes having indegree = 0
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // Count processed nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (int nei : adj[node]) {
            inDegree[nei]--; // Reduce in-degree of neighbors
            if (inDegree[nei] == 0) {
                q.push(nei);
            }
        } 
    }
    return count == numCourses;  // Return true if all nodes processed
}