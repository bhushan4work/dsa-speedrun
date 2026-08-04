//statement- given N x M binary matrix grid, where 0 represents sea cell & 1 represents land cell. a move consists of walking from 1 land cell to another adj (4-directionally) land cell or walking off boundary of grid.
//           Find no of land cells in grid for which we cant walk off boundary of grid in any no of moves.


//(optimal) -using dfs t.c- O(n * m * 4 + n)  s.c- O(n * m)
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &mat){
    vis[row][col] = 1; // mark current cell visited
    int n = mat.size(), m = mat[0].size();

    // direction arr for 4-neighbors
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    

    // try 4 directions
    for (int k = 0; k < 4; k++){
        int nrow = row + dx[k] ;
        int ncol = col + dy[k] ;
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){ // check bounds and unvisited 'O'
            dfs(nrow, ncol, vis, mat); // continue DFS
        }
    }
}

int numEnclaves(vector<vector<int>> mat){
    // handle empty matrix
    int n = mat.size() ;
    if (n == 0 ) return mat ;
    int m = mat[0].size() ;
    if (m == 0 ) return mat ;
    
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0)); // visited matrix

    // traverse 1st & last row
    for (int j = 0; j < m; j++){
        if (!vis[0][j] && mat[0][j] == 1) { // start DFS from unvisited boundary 'O' (top row)
            dfs(0, j, vis, mat);
        }
        if (!vis[n - 1][j] && mat[n - 1][j] == 1) { // start DFS from unvisited boundary 'O' (bottom row)
            dfs(n - 1, j, vis, mat);
        }
    }

    // traverse 1st & last col
    for (int i = 0; i < n; i++){
        if (!vis[i][0] && mat[i][0] == 1) { // start DFS from unvisited boundary 'O' (left col)
            dfs(i, 0, vis, mat);
        }
        if (!vis[i][m - 1] && mat[i][m - 1] == 1) { // start DFS from unvisited boundary 'O' (right col)
            dfs(i, m - 1, vis, mat);
        }
    }

    // flip all unvisited 'O' to 'X'
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // convert enclosed 'O' to 'X'
            if (!vis[i][j] && mat[i][j] == 1) {
                cnt++ ;
            }
        }
    }

    return cnt; // return updated board
}
