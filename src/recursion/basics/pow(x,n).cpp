// statement- Implement power fxn pow(x, n) , which calculates x raised to n


// method1(brute) t.c- O(n)  s.c- O(1)
double myPow(double x, int n){
    if (n == 0 || x == 1.0) return 1; // Base case: any number to the power of 0 is 1

    long long temp = n; // to avoid integer overflow

    if (n < 0){ // Handle negative exponents
        x = 1 / x;
        temp = -1 * 1LL * n;
    }

    double ans = 1;
    for (long long i = 0; i < temp; i++){
        ans *= x; // Multiply ans by x for n times
    }
    return ans;
}


// method2(optimal) -using recursion t.c- O(n)  s.c- O(n)

// Function to calculate power of x^n
double power(double x, long n){
    if (n == 0) return 1.0; // Base case: anything raised to 0 is 1
    if (n == 1) return x; // Base case: anything raised to 1 is itself

    double half = power(x, n / 2);

    if (n % 2 == 0){ // If 'n' is even
        return half * half; // Recursive call: x * x, n / 2 ex: (2*2)^4
    }
    // else when 'n' is odd
    return x * half * half; // Recursive call: x * power(x, n-1) ex: 2*(2)^4
}

// Function to calculate final ans i.e x^n
double myPow(double x, int n){
    long long num = n; // Store the value of n in a separate variable

    if (num < 0){ // If n is negative
        return (1.0 / power(x, -1 * num)); // Calculate power of -n & take reciprocal
    }
    return power(x, num); // If n is non-negative
}