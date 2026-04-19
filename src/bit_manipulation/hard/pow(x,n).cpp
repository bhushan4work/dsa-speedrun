// statement- Implement pow(x, n), which calculates x raised to power n (i.e., x^n)


//(brute) t.c- O(n)  s.c- O(1)
double myPow(double x, int n){
    if (n == 0 || x == 1.0) return 1;  // Base case: any number to the power of 0 is 1

    long long temp = n; // to avoid integer overflow
    if (n < 0){
        x = 1 / x;
        temp = -1 * 1LL * n;
    }

    double ans = 1;
    for (long long i = 0; i < temp; i++){
        ans *= x; // Multiply ans by x for n times
    }
    return ans;
}


//(optimal) t.c- O(logn)  s.c- O(1)
double myPow(double x, int n) {
    double ans = 1.0;
    long long exp = n; // stores copy of n, prevents overflow
    
    if (exp < 0) { // If exponent is negative
        x = 1 / x; // invert base 
        exp = -exp; //make exponent positive
    }

    // Each iteration processes one bit of exponent
    while (exp > 0) {
        if (exp & 1) { // If current bit is 1 (odd exponent)
            ans *= x; // include current power of x in the answer
        }
        x *= x; // Move to next power in every iteration: x → x^2 → x^4 ...
        exp >>= 1; // Shift exponent right (divide by 2), Moves to next bit   
    }
    return ans;
}