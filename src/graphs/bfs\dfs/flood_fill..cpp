// statement- given img represented by m x n grid of integers img, where image[i][j] represents pixel value of img. also given 3 integers sr, sc, color. task is to perform flood fill on img starting from pixel image[sr][sc].

// To perform a flood fill :
// Begin with starting pixel & change its color to color. Perform same process for each pixel that is directly adj (pixels that share side with original pixel, either horizontally or vertically) & shares same color as starting pixel.
// Keep repeating this process by checking neighboring pixels of updated pixels & modifying their color if it matches original color of starting pixel. process stops when there are no more adjacent pixels of original color to update.
// Return modified img after performing flood fill


//(optimal) t.c- O(n * m)  s.c- O(n * m)
void dfs(vector<vector<int>> &image, int r, int c,
         int oldColor, int newColor) {

    // Boundary check
    if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
        return; // Outside grid

    // Stop if color doesn't match original
    if (image[r][c] != oldColor)
        return; // Different color

    // Color curr pixel
    image[r][c] = newColor; // Fill curr cell

    // Visit all 4 directions
    dfs(image, r + 1, c, oldColor, newColor); // Down
    dfs(image, r - 1, c, oldColor, newColor); // Up
    dfs(image, r, c + 1, oldColor, newColor); // Right
    dfs(image, r, c - 1, oldColor, newColor); // Left
}

vector<vector<int>> floodFill(vector<vector<int>> &image,
                              int sr, int sc, int color) {

    int oldColor = image[sr][sc]; // Original color

    // If new color is same as original, nothing to do
    if (oldColor == color)
        return image;

    dfs(image, sr, sc, oldColor, color); // Start DFS

    return image; // Return modified image
}