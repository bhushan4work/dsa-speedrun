// statement- Given 2D arr where each row, col is sorted, write an efficient algo to search for a specific integer target


// (brute) t.c- O(n * m)  s.c- O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) { // Returns true if the target exists anywhere in the matrix.
    if (matrix.empty() || matrix[0].empty()) { // Stop early if the matrix has no usable cells.
        return false;
    }

    for (int i = 0; i < (int)matrix.size(); i++) {
        for (int j = 0; j < (int)matrix[i].size(); j++) {
            if (matrix[i][j] == target) { // Return immediately because the target is found here.
                return true;
            }
        }
    }

    return false;
}



// (optimal) t.c- O(m + n)  s.c- O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) { // Returns true if the target exists anywhere in the matrix.
    if (matrix.empty() || matrix[0].empty()) { // Stop early if the matrix has no usable cells.
        return false;
    }
    
    int rows = (int)matrix.size(); // These store the matrix dimensions for boundary checks.
    int cols = (int)matrix[0].size();
    int row = 0; // Start from the top-right corner to remove one row or column each step.
    int col = cols - 1;

    while (row < rows && col >= 0) {
        int current = matrix[row][col]; // Read the current corner value of the remaining search area.
        if (current == target) { // Return immediately because the target is found here.
            return true;
        }

        if (current > target) { // Move left because everything below this value is even larger.
            col--;
        }
        else {
            row++; // Move down because everything left of this value is even smaller.
        }
    }

    return false;
}