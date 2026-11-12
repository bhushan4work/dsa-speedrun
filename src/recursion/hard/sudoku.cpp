// statement- program that fills blank cells in Sudoku puzzle. Every sudoku soln follows this: 1) In every row, numbers 1 through 9 must appear exactly once.
//            2) In every col, numbers 1 through 9 must appear exactly once. 3) In each of grid's nine 3x3 sub-boxes, numbers 1 through 9 must appear exactly once.
//            Empty cells are indicated by '.' char


// (optimal) t.c- O(9 ^ (n^2))  s.c- O(n ^ 2)
bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) { // Check entire row, column, and 3x3 sub-grid.
        if (board[i][col] == c) { // Check if character 'c' is already in current column.
            return false;
        }

        if (board[row][i] == c) { // Check if character 'c' is already in current row.
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) { // Check 3x3 sub-grid for character 'c'.
            return false;
        }
    }

    return true; // Character 'c' is valid to place.
}

bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) { // Iterate through each row of board.
        for (int j = 0; j < board[0].size(); j++) { // Iterate through each column of board.
            if (board[i][j] == '.') { // Find an empty cell.
                for (char c = '1'; c <= '9'; c++) { // Try placing digits '1' through '9'.
                    if (isValid(board, i, j, c)) { // Check if placing 'c' is valid.
                        board[i][j] = c; // Place digit.
                        if (solve(board) == true) { // Recursively try to solve rest of board.
                            return true;
                        }
                        else {
                            board[i][j] = '.'; // Backtrack if placement doesn't lead to a solution.
                        }
                    }
                }

                return false; // Return false if no valid digit can be placed in this cell.
            }
        }
    }

    return true; // Return true if all cells are successfully filled.
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board); // Start backtracking solving process.
}