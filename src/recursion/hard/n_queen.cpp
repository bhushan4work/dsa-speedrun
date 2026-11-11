// statement- challenge of arranging n queens on a n × n chessboard so that no 2 queens attack one another is known as "n-queens puzzle."
//            Return every unique soln to n-queens puzzle given an integer n. ans in any seq.
//            Every soln has a unique board arrangement for placement of n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.
//            Here are attack rules for N-Queens: Same Row - No 2 queens can be in same row. Same col - No 2 queens can be in same col.
//            Same Diagonal (top-left to bottom-right) - No 2 queens can share same diagonal where (row - col) is equal.
//            Same Anti-Diagonal (top-right to bottom-left) - No 2 queens can share same anti-diagonal where (row + col) is equal.


// (optimal) t.c- O(n!)  s.c- O(n ^ 2)
bool isSafe1(int row, int col, vector<string>& board, int n) {
    int duprow = row; // Store original row index.
    int dupcol = col; // Store original col index.
    while (row >= 0 && col >= 0) { // Check upper-left diagonal for attacking queens.
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }
    
    row = duprow; // Restore original row index.
    col = dupcol; // Restore original col index.
    while (col >= 0) { // Check left side of current row for attacking queens.
        if (board[row][col] == 'Q') {
            return false;
        }
        col--;
    }

    row = duprow; // Restore original row index.
    col = dupcol; // Restore original col index.
    while (row < n && col >= 0) { // Check lower-left diagonal for attacking queens.
        if (board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }

    return true; // Return true if it is safe to place queen.
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) { // Base case: If all cols are successfully filled, a valid configuration is found.
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) { // Try placing a queen in every row of current col.
        if (isSafe1(row, col, board, n)) { // Check if placing queen here is safe.
            board[row][col] = 'Q'; // Place queen.
            solve(col + 1, board, ans, n); // Recur to place queens in remaining cols.
            board[row][col] = '.'; // Backtrack: Remove queen to explore other possibilities.
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans; // Store all valid board configurations.
    vector<string> board(n); // Represents current state of board.
    string s(n, '.'); // Create an empty row with 'n' dots.
    for (int i = 0; i < n; i++) { // Initialize entire board with dots (empty cells).
        board[i] = s;
    }

    solve(0, board, ans, n); // Start backtracking process from 0th col.
    return ans; // Return final list of valid configurations.
}