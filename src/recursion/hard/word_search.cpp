// statement- Given a grid, string word. word can be created by assembling letters of successively surrounding cells, whether they are next to each other vertically
//            or horizontally. u cant use same letter cell more than once. Return true if word exists in grid otherwise false


// (optimal) t.c- O(m * n * 3^l)  s.c- O(l)
int l, m, n;
vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
    if (idx >= l) { // All characters matched successfully.
        return true;
    }

    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) { // Out of bounds or character mismatch.
        return false;
    }

    char temp = board[i][j]; // Store original character.
    board[i][j] = '$'; // Mark current cell as visited.
    for (auto& dir : directions) { // Explore all 4 adjacent directions.
        int i_ = i + dir[0];
        int j_ = j + dir[1];
        if (find(board, i_, j_, word, idx + 1)) {
            return true;
        }
    }

    board[i][j] = temp; // Backtrack and restore the original character.
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();
    l = word.length();

    if (m * n < l) { // Board is too small to contain the word.
        return false;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0] && find(board, i, j, word, 0)) { // Start DFS search if the first character matches.
                return true;
            }
        }
    }
    
    return false;
}