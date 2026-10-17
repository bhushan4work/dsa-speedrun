//statement- Given rows x cols binary matrix filled with 0's & 1's, find largest rectangle containing only 1's & return its area


// (optimal) -using histogram approach t.c- O(n * (m + n))  s.c- O(n)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        int curr = (i == n) ? 0 : heights[i];               // sentinel to process remaining bars

        while (!st.empty() && heights[st.top()] > curr) {
            int h = heights[st.top()];                      // height of rectangle
            st.pop();

            int w = st.empty() ? i : i - st.top() - 1;      // maximum width
            ans = max(ans, h * w);                          // update maximum area
        }

        if (i < n) st.push(i);                              // store bar index
    }

    return ans;                                             // largest histogram area
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;

    int m = matrix[0].size();
    vector<int> heights(m, 0);                              // histogram heights
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1')
                heights[j]++;                              // extend histogram bar
            else
                heights[j] = 0;                            // reset on zero
        }

        ans = max(ans, largestRectangleArea(heights));      // largest rectangle for this row
    }

    return ans;                                             // maximum rectangle in matrix
}