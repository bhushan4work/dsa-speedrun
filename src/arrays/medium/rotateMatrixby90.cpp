// statement- rotate n*n 2D matrix by 90 deg clockwise. Rotation must be done in place i.e input matrix must be modified directly

// method1(brute)  t.c- O(n^2)  s.c- O(n^2)
void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = ans;
}

// method2(optimal)  t.c- O( (n\2 * n\2) + (n * n\2) )  s.c- O(1)
void rotateClockwise(vector<vector<int>> &matrix){
    int n = matrix.size();
    //Transpose the matrix - (diagonal elements remain same while we transpose)
    for (int i = 0; i < n-1; ++i){  //n-1 is done as we need to swap elements above diagonal only
        for (int j = i + 1; j < n; ++j){
            // Swap element at (i, j) with (j, i) to transpose
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row to get the req matrix
    for (int i = 0; i < n; ++i){
        // Reverse the current row to complete clockwise rotation
        reverse(matrix[i].begin(), matrix[i].end());
    }
}