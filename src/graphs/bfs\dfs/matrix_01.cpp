// statement- Given binary grid of N * M. Find distance of nearest 0 in grid for each cell


//(optimal) using bfs t.c- O(m * n * + n * m )  s.c- O(m * n)
vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
    int m = mat.size(), n = mat[0].size(); // Get matrix dimensions

    vector<vector<int>> dist(m, vector<int>(n, -1)); // Store shortest distance for each cell
    queue<pair<int, int>> q;                         // Multi-source BFS queue

    for (int i = 0; i < m; i++){ // Traverse every cell
        for (int j = 0; j < n; j++){
            if (mat[i][j] == 0){                   // Start BFS from every 0
                dist[i][j] = 0; // Distance of 0 from itself
                q.push({i, j}); // Push all 0s into queue
            }
        }
    }

    int dr[] = {-1, 1, 0, 0}; // Row directions
    int dc[] = {0, 0, -1, 1}; // Column directions

    while (!q.empty()){                           // Process all reachable cells
        auto [r, c] = q.front(); // Current cell
        q.pop();                 // Remove it from queue

        for (int k = 0; k < 4; k++){ // Visit all 4 neighbors
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                dist[nr][nc] == -1) { // Visit only unprocessed cells

                dist[nr][nc] = dist[r][c] + 1; // Update shortest distance
                q.push({nr, nc});              // Continue BFS from this cell
            }
        }
    }
    return dist; // Return answer matrix
}