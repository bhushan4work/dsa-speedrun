//statement- given heights, 2D arr of size rows * columns, where heights[row][col] represents height of cell (row, col). src is (0, 0), destination is (rows-1, columns-1) (i.e.,0-indexed).
//           You can move in 4 direc, find route with min effort. route's effort is max absolute diff in heights betw 2 consecutive cells of route


//(optimal) t.c- O(4 * n * m * log(n * m))  s.c- O(n * m)
int MinimumEffort(vector<vector<int>> &heights) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // min-heap: effort, row, col
    int n = heights.size(); // number of rows
    int m = heights[0].size(); // number of columns

    vector<vector<int>> dist(n, vector<int>(m, 1e9)); // minimum effort to reach each cell
    dist[0][0] = 0; // source cell
    pq.push({0, {0, 0}}); // push source

    int dr[] = {-1, 0, 1, 0}; // row directions
    int dc[] = {0, 1, 0, -1}; // column directions

    while (!pq.empty()) {
        auto it = pq.top(); // get minimum effort cell
        pq.pop();
        int diff = it.first; // current effort
        int row = it.second.first; // current row
        int col = it.second.second; // current column

        if (row == n - 1 && col == m - 1) return diff; // destination reached

        for (int i = 0; i < 4; i++) {
            int newr = row + dr[i]; // next row
            int newc = col + dc[i]; // next column

            if (newr >= 0 && newc >= 0 && newr < n && newc < m) { // check bounds
                int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff); // effort for this path

                if (newEffort < dist[newr][newc]) { // found a better effort
                    dist[newr][newc] = newEffort; // update minimum effort
                    pq.push({newEffort, {newr, newc}}); // push updated cell
                }
            }
        }
    }

    return 0; // unreachable case
}