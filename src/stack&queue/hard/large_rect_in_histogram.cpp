// statement- Given arr of integers heights representing histogram's bar height where width of each bar is 1 return area of largest rectangle in histogram


// (brute) t.c- O(n ^ 2)  s.c- O(1)
long long largestRectangleArea(vector<int>& heights) { // Finds the largest rectangle by boundary scans.
    int n = heights.size();
    long long maxArea = 0;
    for (int index = 0; index < n; index++) { // Treat every bar as the limiting height.
        int left = index;
        int right = index;
        while (left > 0 && heights[left - 1] >= heights[index]) { // Extend across bars supporting the height.
            left--;
        }
        while (right + 1 < n && heights[right + 1] >= heights[index]) { // Extend across bars supporting the height.
            right++;
        }
        long long width = right - left + 1;
        long long area = 1LL * heights[index] * width; // The current bar limits the rectangle height.
        maxArea = max(maxArea, area); // Preserve the best supported rectangle.
    }
    return maxArea; // Every limiting height has been checked.
}



// (optimal) t.c- O(n)  s.c- O(n)
long long largestRectangleArea(vector<int>& heights) { // Finds the largest rectangle with a stack.
    int n = heights.size();
    stack<int> indices;
    long long maxArea = 0;
    for (int index = 0; index <= n; index++) { // Add a zero sentinel to close remaining bars.
        int currentHeight = index == n ? 0 : heights[index];
        while (!indices.empty() && heights[indices.top()] >= currentHeight) { // A shorter bar closes taller rectangles.
            int height = heights[indices.top()];
            indices.pop();
            int width = indices.empty() ? index : index - indices.top() - 1; // The new top is the smaller left boundary.
            long long area = 1LL * height * width; // The popped bar limits the closed rectangle.
            maxArea = max(maxArea, area); // Preserve the largest closed rectangle.
        }
        if (index < n) { // Only real bar indices belong in the stack.
            indices.push(index);
        }
    }
    return maxArea; // The sentinel has resolved every bar.
}