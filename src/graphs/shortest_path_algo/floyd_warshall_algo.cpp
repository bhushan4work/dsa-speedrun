//statement- Given graph of V vertices numbered from 0 to V-1. Find shortest dist betw every pair of vertices in given edge-weighted directed graph. graph is represented as adjacency matrix of size n x n.
//           Matrix[i][j] denotes weight of edge from i to j. If matrix[i][j]=-1, it means there is no edge from i to j


//(optimal) t.c- O(v ^ 3)  s.c- O(v ^ 2)
void shortest_distance(vector<vector<int>> &matrix) {
    int n = matrix.size(); // Getting no of nodes

    for(int k=0; k<n; k++) { // For each intermediate node k

        for(int i=0; i<n; i++) { // Check for every (i, j) pair of nodes

            for(int j=0; j<n; j++) {
                if(matrix[i][k] == -1 || matrix[k][j] == -1) continue; // If k is not an intermediate node, skip iteration
                if(matrix[i][j] == -1) { // If no direct edge from i to j is present
                    matrix[i][j] = matrix[i][k] + matrix[k][j]; // Update dist
                }
                else { // Else update dist to min of both paths
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
}
