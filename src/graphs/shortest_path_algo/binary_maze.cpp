//statement- Given n * m matrix grid where each element can either be 0 or 1. find shortest dist betw given source cell to destination cell. 
//           path can only be created out of cell if its value is 1. If path is not possible betw source cell & destination cell, then return -1
// Note: You can move into an adj cell if that adjacent cell is filled with element 1. 2 cells are adj if they share a side. In other words, you can move in one of 4 directions, Up, Down, Left, & Right
// Note: We used queue instead of priority-queue coz every move has same cost i.e 1, so BFS always processes cells in incr order of dist. so no need of minheap pq


//(optimal) t.c- O(4 * n * m)  s.c- O(n * m)
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    if (source.first == destination.first && source.second == destination.second)
        return 0;  // source & destination are the same

    int n = grid.size();
    int m = grid[0].size();

    // add below 2 lines if src {0,0} to desti {n-1,n-1} is asked
    // pair<int, int> source = {0, 0};
    // pair<int, int> destination = {n - 1, m - 1};

    queue<pair<int, pair<int, int>>> q;  // stores {distance, {row, col}}
    vector<vector<int>> dist(n, vector<int>(m, 1e9));  // distance of each cell from source

    dist[source.first][source.second] = 0;  // distance of source is 0
    q.push({0, {source.first, source.second}});  // push source into the queue

    int dr[] = {-1, 0, 1, 0};  // row changes: up, right, down, left
    int dc[] = {0, 1, 0, -1};  // column changes: up, right, down, left

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int dis = it.first;  // current distance
        int r = it.second.first;  // current row
        int c = it.second.second;  // current column

        for (int i = 0; i < 4; i++) {
            int newr = r + dr[i];  // new row
            int newc = c + dc[i];  // new column

            if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {  // valid cell with shorter distance
                dist[newr][newc] = dis + 1;  // update shortest distance

                if (newr == destination.first && newc == destination.second)
                    return dis + 1;  // destination reached

                q.push({dis + 1, {newr, newc}});  // add cell to the queue
            }
        }
    }

    return -1;  // no path exists
}