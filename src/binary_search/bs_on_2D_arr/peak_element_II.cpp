// statement- Given 0-indexed n x m matrix where no 2 adjacent cells are equal, find any peak element & return arr [i, j]. peak element in 2D is strictly greater
// than all of its adjacent neighbours to left, right, top, bottom. As there can be many peak values, 1 is given as output if returned index is peak number, otherwise 0


// (brute) t.c- O(n * m)  s.c- O(1)
vector<int> findPeakGrid(vector<vector<int>>& mat) { // Returns position of any valid peak element.
    int rows = (int)mat.size();
    int cols = (int)mat[0].size();

    for (int i = 0; i < rows; i++) { // Traverse each cell in grid
        for (int j = 0; j < cols; j++) {
            int up = -1; // Initialize top neighbor; defaults to -1 if out of boundary
            if (i > 0) {
                up = mat[i - 1][j]; // Current cell is not in top row, so fetch upper neighbor
            }

            int down = -1; // Initialize bottom neighbor; defaults to -1 if out of boundary
            if (i + 1 < rows) {
                down = mat[i + 1][j]; // Current cell is not in bottom row, so fetch lower neighbor
            }

            int left = -1; // Initialize left neighbor; defaults to -1 if out of boundary
            if (j > 0) {
                left = mat[i][j - 1]; // Current cell is not in leftmost column, so fetch left neighbor
            }

            int right = -1; // Initialize right neighbor; defaults to -1 if out of boundary
            if (j + 1 < cols) {
                right = mat[i][j + 1]; // Current cell is not in rightmost column, so fetch right neighbor
            }

            if (mat[i][j] > up && mat[i][j] > down && mat[i][j] > left && mat[i][j] > right) { // Check if current cell is strictly greater than all valid neighbors
                return {i, j}; // Found a valid peak, return its coordinates immediately
            }
        }
    }

    return {-1, -1}; // Return {-1, -1} if no peak element is found
}



// (optimal) t.c- O(nlogm)  s.c- O(1)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = (int)mat.size();
    int cols = (int)mat[0].size();
    int low = 0;
    int high = rows - 1;

    while (low < high) {
        int mid = low + (high - low) / 2; // Pick middle row of current search space.
        int bestCol = 0; // This stores column of largest value in middle row.

        for (int col = 1; col < cols; col++) {
            if (mat[mid][col] > mat[mid][bestCol]) { // Keep column where current row has its maximum value.
                bestCol = col;
            }
        }

        if (mat[mid][bestCol] > mat[mid + 1][bestCol]) { // Move upward if current row already beats row below here.
            high = mid;
        }
        else {
            low = mid + 1; // Move downward because a larger value exists below in this column.
        }
    }

    int bestCol = 0; // Find largest element again in final answer row.
    for (int col = 1; col < cols; col++) {
        if (mat[low][col] > mat[low][bestCol]) { // Keep column where final row has its maximum value.
            bestCol = col;
        }
    }

    return {low, bestCol}; // Returns position of any valid peak element.
}