// statement- find and return sqrt of n. If ‘n’ is not a perfect square, then return the floor value of sqrt(n)

// method1(brute) t.c- O(n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int floorSqrt(int n){
    int ans = 0;

    for (long long i = 1; i <= n; i++){
        if (i * i <= n){
            ans = i;
        }
        else{
            break; // Break when i*i > n
        }
    }
    return ans;
}

// method2(optimal) t.c- O(logn)  s.c- O(1)  -bs used here
int floorSqrt(int n){
    if (n == 0 || n == 1) return n;
    int low = 1, high = n;
    int ans = 0;

    while (low <= high){
        int mid = low + (high - low) / 2; // did like this to avoid overflow

        //did like this to avoid overflow
        if (mid <= n / mid) {   //check for mid*mid, returns bool
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}