// statement- given matrix consists of 0s and 1s. All rows are sorted. find index of row with max no of 1s.
// note: If 2 rows have same no of 1s, consider one with smaller index. If no row with at least 1 zero exists, return -1


// method1(brute) t.c- O(n * m)  s.c- O(1)  -normal iteration is done i.e bs not used here
int rowWithMax1s(vector<vector<int>> &matrix, int m, int n){  // here m=rows , n=cols
    int cnt_max = 0; // compare with counter & gets max-1s count in matrix
    int index = -1;  // stores index of row with max-1s

    for (int i = 0; i < n; i++){
        int cnt_ones = 0; // counts 1s in current row
        for (int j = 0; j < m; j++){
            cnt_ones += matrix[i][j];
        }

        if (cnt_ones > cnt_max){
            cnt_max = cnt_ones; // update max-1s count if curr row has more 1s
            index = i;
        }
    }
    return index;
}


// method2(optimal) t.c- O(m * logn)  s.c- O(1)  -bs used here
int lowerBound(vector<int> &arr, int sizeOfArr, int one){  // finds 1st occurrence of '1' in each row of matrix
    int low = 0, high = sizeOfArr - 1;
    int ans = sizeOfArr; // Default if one not found

    while (low <= high){
        int mid = low + ((high - low) / 2);
        if (arr[mid] >= one){
            ans = mid;      // Possible answer
            high = mid - 1; // Look for smaller index in left side
        }
        else{
            low = mid + 1; // else search right side
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int m, int n){  // here m=rows , n=cols
    int cnt_max = 0;
    int index = -1; // to manage edge case of -1 we keep index as -1 initially

    for (int i = 0; i < m; i++){
        int cnt_ones = n - lowerBound(matrix[i], n, 1); // 1s = total - index of 1st occurence of 1
        if (cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}