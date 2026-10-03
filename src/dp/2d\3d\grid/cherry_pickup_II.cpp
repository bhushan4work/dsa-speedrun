// statement - given an N * M grid. Every cell has some cherries. Initially, Alice is standing on cell (0,0), & Bob is standing on cell (0, M-1).
//            Both can move only to cells below them in 3 direc: (↓), (↘), (↙). When Alice & Bob visit a cell, they collect all cherries in that cell.
//            If they visit same cell, cherries are counted only once. They cannot go outside the boundary of given grid.
//            Return max no of cherries that Alice & Bob can collect together


// (optimal) - memoization t.c - O(n * m * m * 9)  s.c - O(n * m * m + n)
int solve(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) { // Out of boundary check
        return -1e9;
    }

    if (i == n - 1) { // Base case: last row
        if (j1 == j2) {
            return grid[i][j1];
        }
        else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1) { // If already computed return it
        return dp[i][j1][j2];
    }

    int maxi = -1e9; // Take cherries from current cell(s)
    int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

    for (int dj1 = -1; dj1 <= 1; dj1++) { // Try all 9 moves
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int ans = curr + solve(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            maxi = max(maxi, ans);
        }
    }

    return dp[i][j1][j2] = maxi; // Store result
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return solve(0, 0, m - 1, n, m, grid, dp);
}



// (optimal) - tabulation t.c - O(n * m * m * 9)  s.c - O(n * m * m)
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0))); // 3D DP table

    for (int j1 = 0; j1 < m; j1++) { // Base case: last row
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) {
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else {
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) { // Fill DP table bottom-up
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = -1e9;
                int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

                for (int dj1 = -1; dj1 <= 1; dj1++) { // Try all 9 moves
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int newJ1 = j1 + dj1;
                        int newJ2 = j2 + dj2;

                        if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m) {
                            maxi = max(maxi, curr + dp[i+1][newJ1][newJ2]);
                        }
                        else {
                            maxi = max(maxi, (int)-1e9);
                        }
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}