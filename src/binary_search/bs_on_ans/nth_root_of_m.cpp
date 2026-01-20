//statement- find the nth root of m. If nth root is not an integer, return -1

//method1(brute) t.c- O(m)  s.c- O(1)  -normal iteration is done i.e bs not used here
int nthRoot(int n, int m) {
    for (int i = 1; i <= m; i++) {
        long long power = pow(i, n);

        if (power == m) return i; 

        if (power > m) break;
    }
    return -1;
}

//method2(optimal) t.c- O(logm)  s.c- O(1)  -bs used here
int power(int mid, int n, int m) { //this fxn avoids full power calculation and overflow
    //we made this fxn to get pointers for =m\<m\>m
    long long ans = 1;

    for (int i = 0; i < n; i++) {
        ans = ans * mid;
        if (ans > m) return 2; //if > m get pointer 2
    }
    if (ans == m) return 1;   // exact match get pointer 1
    return 0;                    // else get pointer 0 when < m
}

int nthRoot(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2; 
        int midN = power(mid, n, m);  //gives pointer to move left\right & return the exact match

        if (midN == 1) return mid; //exact match
        else if (midN == 0) low = mid + 1;  //move right coz ans < m
        else high = mid - 1; //move left coz ans > m
    }
    return -1;
}
