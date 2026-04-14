// statement- digit str is considered good if digits at even indices (0-based) are even(0,2,4,6,8) & digits at odd indices are prime(2,3,5,7)
// Given an int n, return total no of good digit str of length n. As result may be large, return it modulo 109 + 7
// A digit str is str consisting only of the digits '0' through '9'. It may contain leading zeros


//(optimal) -recursion using binary exp t.c- O(logn)  s.c- O(1)

const long long MOD = 1e9 + 7; // Modulo value to prevent overflow

long long power(long long base, long long exp) { // Fast exponentiation fxn (Binary Exponentiation)
    long long result = 1; // Stores final result of (base^exp % MOD)

    while (exp > 0) { // Loop until exponent becomes 0
        if (exp % 2 == 1) {  // If current exponent is odd
            result = (result * base) % MOD; // Multiply current base into result
        }
        //else when exp is not odd do this
        base = (base * base) % MOD; // Square the base → move to next power i.e (base^2, base^4, base^8...)
        exp /= 2; // Divide exponent by 2 → shift right in binary
    }
    return result; 
}

int countGoodNumbers(long long n) {
    //cnt even & odd indices
    long long even = (n + 1) / 2; //Each has 5 choices → {0,2,4,6,8}
    long long odd = n / 2; // Each has 4 choices → {2,3,5,7}

    long long evenPart = power(5, even); // Total ways to fill even positions
    long long oddPart = power(4, odd); // Total ways to fill odd positions

    return (evenPart * oddPart) % MOD;
}