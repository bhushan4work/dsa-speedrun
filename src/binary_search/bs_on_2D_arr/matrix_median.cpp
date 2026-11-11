// statement- Given 2D arr that is row-wise sorted. task is to find median of given matrix


// (brute) t.c- O(n * m * log(m * n))  s.c- O(m * n)
int median(vector<vector<int>>& mat) { // Returns median value of row-wise sorted matrix.
    vector<int> values;
    for (int i = 0; i < (int)mat.size(); i++) {
        for (int j = 0; j < (int)mat[i].size(); j++) {
            values.push_back(mat[i][j]);
        }
    }

    sort(values.begin(), values.end()); // Sort all values because median depends on global sorted order.

    int middleIndex = (int)values.size() / 2; // This points to exact middle because total count is odd.
    return values[middleIndex];
}



// (optimal) t.c- O(m + n * logn)  s.c- O(1)
int median(vector<vector<int>>& mat) { // Returns median value of row-wise sorted matrix.
    int rows = (int)mat.size();
    int cols = (int)mat[0].size();
    int low = mat[0][0]; // These store smallest and largest possible median values.
    int high = mat[0][cols - 1];

    for (int i = 1; i < rows; i++) {
        low = min(low, mat[i][0]); // first element of a sorted row can improve global minimum.
        high = max(high, mat[i][cols - 1]); // last element of a sorted row can improve global maximum.
    }

    int required = (rows * cols) / 2; // This is how many elements may stay before median.
    while (low < high) {
        int mid = low + (high - low) / 2; // This is current guessed median value.
        int count = 0;
        for (int i = 0; i < rows; i++) {
            count += (int)(upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin()); // Count how many values in this row are less than or equal to mid.
        }

        if (count <= required) { // Move right because too few elements are still less than or equal to mid.
            low = mid + 1;
        }
        else {
            high = mid; // Keep mid in answer range because it may already be median.
        }
    }

    return low;
}