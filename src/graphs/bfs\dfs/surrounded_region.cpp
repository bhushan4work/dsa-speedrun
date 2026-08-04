// statement- Given m x n matrix containing 'X' & '0', capture all regions that are 4-directionally surrounded by 'X'. region is captured by flipping all '0's into 'X's in that surrounded region. region is connected if any '0' is adjacent to another '0' horizontally or vertically.
//            '0' is on boundary if its in 1st row, last row, 1st col, or last col of matrix. Any '0' that is on boundary or connected to boundary-touching '0' will not be flipped. All other '0's (the ones completely surrounded, meaning no cell in connected component touches border) will be flipped to 'X'


//(optimal) -using dfs t.c- O(n * m * 4 + n)  s.c- O(n * m)
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat){
    vis[row][col] = 1; // mark current cell visited
    int n = mat.size(), m = mat[0].size();

    // direction arr for 4-neighbors
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    

    // try 4 directions
    for (int k = 0; k < 4; k++){
        int nrow = row + dx[k] ;
        int ncol = col + dy[k] ;
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){ // check bounds and unvisited 'O'
            dfs(nrow, ncol, vis, mat); // continue DFS
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat){
    if (n == 0 || m == 0) return mat; // handle empty matrix
    vector<vector<int>> vis(n, vector<int>(m, 0)); // visited matrix

    // traverse 1st & last row
    for (int j = 0; j < m; j++){
        if (!vis[0][j] && mat[0][j] == 'O') { // start DFS from unvisited boundary 'O' (top row)
            dfs(0, j, vis, mat);
        }
        if (!vis[n - 1][j] && mat[n - 1][j] == 'O') { // start DFS from unvisited boundary 'O' (bottom row)
            dfs(n - 1, j, vis, mat);
        }
    }

    // traverse 1st and last col
    for (int i = 0; i < n; i++){
        if (!vis[i][0] && mat[i][0] == 'O') { // start DFS from unvisited boundary 'O' (left col)
            dfs(i, 0, vis, mat);
        }
        if (!vis[i][m - 1] && mat[i][m - 1] == 'O') { // start DFS from unvisited boundary 'O' (right col)
            dfs(i, m - 1, vis, mat);
        }
    }

    // flip all unvisited 'O' to 'X'
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // convert enclosed 'O' to 'X'
            if (!vis[i][j] && mat[i][j] == 'O') {
                mat[i][j] = 'X';
            }
        }
    }

    return mat; // return updated board
}