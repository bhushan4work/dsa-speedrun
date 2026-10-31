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