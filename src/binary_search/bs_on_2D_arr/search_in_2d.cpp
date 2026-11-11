// statement- Given 2-D arr where elements of each row are sorted, 1st element of a row is greater than last element of previous row, given an integer target, determine if target exists


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



// (optimal) t.c- O(log(m * n))  s.c- O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) { // Returns true if the target exists anywhere in the matrix.
    if (matrix.empty() || matrix[0].empty()) { // Stop early if the matrix has no usable cells.
        return false;
    }

    int rows = (int)matrix.size(); // These store the matrix dimensions for index mapping.
    int cols = (int)matrix[0].size();
    int low = 0; // Search boundaries of the virtual 1D sorted array.
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Pick the middle position of the current search space.
        int row = mid / cols; // Convert the virtual 1D index into the real matrix position.
        int col = mid % cols; // This gives the column inside the chosen row.
        int current = matrix[row][col]; // Read the actual value stored at the mapped position.

        if (current == target) { // Return immediately because the target is found here.
            return true;
        }

        if (current < target) { // Move right because the target must be after this smaller value.
            low = mid + 1;
        }
        else { // Move left because this value and everything after it are too large.
            high = mid - 1;
        }
    }

    return false;
}