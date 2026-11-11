// statement- Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) & wants to reach at coordinates (n-1, n-1).
//            Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). directions in which rat can move are 'U', 'D', 'L', 'R'.
//            value 0 in grid denotes that cell is blocked & rat cant use that cell for travelling, whereas value 1 represents that rat can travel through cell. 
//            If cell (0, 0) has 0 value, then mouse cant move to any other cell. Note : In a path no cell can be visited more than once. If no possible path, return empty vector.


// (optimal) t.c- O(4 ^ (n ^ 2))  s.c- O(n ^ 2)
void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans, string move, vector<vector<int>>& vis) {
    if (i == n - 1 && j == n - 1) { // Base case: Reached the destination
        ans.push_back(move);
        return;
    }

    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) { // Downward movement
        vis[i][j] = 1;
        solve(i + 1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) { // Left movement
        vis[i][j] = 1;
        solve(i, j - 1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) { // Right movement
        vis[i][j] = 1;
        solve(i, j + 1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) { // Upward movement
        vis[i][j] = 1;
        solve(i - 1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0)); // Keep track of visited cells to avoid loops
    if (m[0][0] == 1) { // Start only if the initial cell is not blocked
        solve(0, 0, m, n, ans, "", vis);
    }

    return ans;
}