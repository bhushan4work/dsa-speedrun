// statement- if element in matrix is 0 then set its entire column & row to 0 & then return the matrix

// method1(brute) t.c- O(m*n * (m+n) ) s.c- O(1)
void setZeroes(vector<vector<int>> &matrix){
    int m = matrix.size();    // number of rows
    int n = matrix[0].size(); // number of cols (each row have equal no of col & hence [0] is done)
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 0){
                // Mark all elements in this row as -1 (except existing zeros)
                for (int col = 0; col < n; col++){
                    if (matrix[i][col] != 0)
                        matrix[i][col] = -1;
                }
                // Mark all elements in this column as -1 (except existing zeros)
                for (int row = 0; row < m; row++){
                    if (matrix[row][j] != 0)
                        matrix[row][j] = -1;
                }
            }
        }
    }
    // replace all -1 markers with 0
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// method2(better) t.c- O(2 * m*n) s.c- O(m + n)
void setZeroes(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, 0);   // Create row marker array
    vector<int> col(n, 0);   // Create column marker array
    //mark rows and columns that need to be zeroed
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    //set cells to zero based on markers in row & col vectors
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // If the row or column is marked, set that cell to zero
            if (row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
}

// method3(optimal) t.c- O(2 * m*n) s.c- O(1)
void setZeroes(vector<vector<int>> &matrix){
    int m = matrix.size();  
    int n = matrix[0].size(); 
    boolean firstRow = false, firstCol = false;
    // Set markers in first row and first col of original matrix
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0){
                if (i == 0)
                    firstRow = true;
                if (j == 0)
                    firstCol = true;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
    // Replace inner matrix (i.e ignoring 1st row & col)
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    // Last remaining checks for 1st row & col
    if (firstRow)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;

    if (firstCol)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
}