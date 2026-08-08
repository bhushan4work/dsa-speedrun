// statement- given an undirected graph with n nodes, numbered from 0 to n - 1. graph is represented as adj list graph, where graph[i] contains all nodes directly connected to node i.
//            graph is bipartite if u can divide all its nodes into 2 grps such that no 2 directly connected nodes belong to same group. Return true if given graph is bipartite otherwise return false


//(optimal) using dfs t.c- O(v + edges)  s.c- O(edges)
bool dfs(int node, int curr_col, vector<int>& color, vector<vector<int>>& graph) {
    color[node] = curr_col;                                      // assign color to current node

    for (auto it : graph[node]) {                           // visit all adjacent nodes
        if (color[it] == -1) {                              // if adjacent node is uncolored
            if (!dfs(it, !curr_col, color, graph))           // color it with opposite color
                return false;                               // conflict found
        }
        else if (color[it] == curr_col) {                 // adjacent node has same color
            return false;                                 // graph is not bipartite
        }
    }

    return true;                                            // no conflict found
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();                                   // number of nodes
    vector<int> color(n, -1);                               // -1 means uncolored

    for (int i = 0; i < n; i++) {                           // handle all components
        if (color[i] == -1) {                               // if node is uncolored
            if (!dfs(i, 0, color, graph))                   // start DFS with color 0
                return false;                               // conflict found
        }
    }

    return true;                                            // graph is bipartite
}