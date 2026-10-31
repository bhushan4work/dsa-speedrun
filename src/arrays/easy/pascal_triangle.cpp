//statement- Given an integer numRows, return 1st numRows of Pascal's triangle. In Pascal's triangle, each number is sum of 2 numbers which are directly above it

// (optimal) t.c- O(n ^ 2)  s.c- O(n ^ 2)
vector<vector<int>> generate(int numRows) {   // Returns first numRows rows of Pascal's Triangle.
    vector<vector<int>> triangle;             // 2D vector to store final Pascal's triangle

    for (int row = 0; row < numRows; row++) {  // Build each row from top to bottom.
        vector<int> current(row + 1, 1);       // Initialize current row with size 'row+1', all filled with 1s.

        for (int col = 1; col < row; col++) {  // Fill only interior positions from previous row.
            current[col] = triangle[row - 1][col - 1] + triangle[row - 1][col]; // Sum 2 elements directly above
        }
        
        triangle.push_back(current);           // Append fully constructed current row to final ans array
    }

    return triangle;               
}



//statement- Given an integer rowIndex, return rowIndexth (0-indexed) row of Pascal's triangle. In Pascal's triangle, each number is sum of 2 numbers directly above it 

// (optimal) t.c- O(rowindex)  s.c- O(rowindex)
vector<int> getRow(int rowIndex) { // Returns requested row of Pascal's Triangle.
    vector<int> result;
    long long current = 1; 
    result.push_back(1); 

    for (int col = 1; col <= rowIndex; col++) {  // Generate each next coefficient from previous coefficient.
        current = current * (rowIndex - col + 1) / col;
        result.push_back(current);   // Final values fit in int under given constraints.
    }

    return result;
}



//statement- Given 2 0-indexed integers r & c, return corresponding element at r-th row & c-th column of Pascal's Triangle

// (optimal) t.c- O(min(c,r-c))  s.c- O(1)
int getElement(int r, int c) {
    if (c > r - c) {                       // Optimization using symmetry: C(r, c) == C(r, r-c)
        c = r - c;                         // Reduces the no of iterations needed ex: [1 3 3 1] here instead of running loop 2nd ind, we'll loop till 1st ind
    }

    long long res = 1;                     // Initialize result
    for (int i = 0; i < c; i++) {          // Iteratively calculate nCr
        res = res * (r - i) / (i + 1);     // Multiply by numerator term, divide by denominator term
    }

    return res;                            // Return final calculated element
}