//statement- Given an integer n, return the number of prime numbers that are <= n


//(brute) t.c- O(nlogn)  s.c- O(n)
int countPrimes(int n) {
    vector<int> prime(n + 1, 1); // Create arr to mark primes (1 = prime, 0 = not prime)

    // 0 and 1 are not prime numbers
    if (n >= 0) prime[0] = 0;
    if (n >= 1) prime[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {  // if i is prime
            // Mark all multiples of i as non-prime
            for (int j = 2 * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    int count = 0;  // to store no of primes
    // Count all prime numbers
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            count++;  // increment count if prime
        }
    }
    return count;
}


//(optimal) t.c- O(nlog(logn))  s.c- O(n)
int countPrimes(int n) {
    vector<int> prime(n + 1, 1); // Create arr to mark primes (1 = prime, 0 = not prime)

    // 0 and 1 are not prime numbers
    if (n >= 0) prime[0] = 0;
    if (n >= 1) prime[1] = 0;

    for (int i = 2; i*i <= n; i++) {
        if (prime[i] == 1) {  // if i is prime
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    int count = 0;  // to store no of primes
    // Count all prime numbers
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            count++;  // increment count if prime
        }
    }
    return count;
}

