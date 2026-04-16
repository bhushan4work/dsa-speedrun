// statement- Given dividend & divisor. Divide without using mod, division, or multiplication operators & return the quotient


//(optimal) t.c- O(logn ^ 2)  s.c- O(1)
int divide(int dividend, int divisor){
    if (dividend == divisor) return 1; // If both are equal, result is always 1

    bool sign = true; 

    // If signs are different → result should be negative as +ve -ve gives -ve
    if (dividend >= 0 && divisor < 0) sign = false;
    else if (dividend < 0 && divisor > 0) sign = false;

    // Convert both numbers to positive (use long to avoid overflow)
    long n = abs((long) dividend); // dividend
    long d = abs((long) divisor);  // divisor

    long quotient = 0;

    // Main loop: keep subtracting largest possible multiples
    while (n >= d){
        int cnt = 0;

        // This finds largest multiple of divisor we can subtract
        while (n >= (d << (cnt + 1))){  // Find max power such that (d << (cnt + 1)) <= n
            cnt += 1;
        }

        // Add corresponding power of 2 to quotient
        quotient += (1LL << cnt); // (1 << cnt) = 2^cnt
    
        n -= (d << cnt); // Subtract that multiple from n
    }

    // Handle overflow case:
    if (quotient == (1LL << 31) && sign) return INT_MAX; // quotient == 2^31 → exceeds INT_MAX when +ve
    if (quotient == (1LL << 31) && !sign) return INT_MIN; // If negative, minimum allowed is INT_MIN

    return sign ? quotient : -quotient;
}