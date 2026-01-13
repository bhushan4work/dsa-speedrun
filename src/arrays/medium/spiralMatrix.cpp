// statement- return all elements of m*n matrix in spiral order
// spiral order- traversing & returning all elements in clockwise spiral path,
//              starting from the top-left corner & moving inward, layer by layer, until the center is reached
// note: this problem has only 1 soln & its an implementation bases que

// method1(optimal) t.c- O(m*n) s.c- O(1)
vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> ans;
    int m = matrix.size(); //rows
    int n = matrix[0].size(); //columns

    int top = 0;
    int bottom = m - 1; //is at last row, hence m-1
    int left = 0;
    int right = n - 1;  //is at last col, hence n-1

    while (top <= bottom && left <= right){ //helps in getting all rows & cols from out to inside
        for (int i = left; i <= right; i++){  //go from left to right across the top row
            ans.push_back(matrix[top][i]); //top is const
        }
        top++; // Move top boundary down
        
        for (int i = top; i <= bottom; i++){ //go from top to bottom on the right column
            ans.push_back(matrix[i][right]); //right is const
        }
        right--; // Move right boundary left

        if (top <= bottom){ //Prevents re-traversal when only 1 row remains or exists
            for (int i = right; i >= left; i--){  //go from right to left on the bottom row
                ans.push_back(matrix[bottom][i]);
            }
            bottom--; // Move bottom boundary up
        }

        if (left <= right){ //Prevents re-traversal when only 1 col remains or exists
            for (int i = bottom; i >= top; i--){ //go from bottom to top on the left column
                ans.push_back(matrix[i][left]);
            }
            left++; // Move left boundary right
        }
    }
    return ans;
}