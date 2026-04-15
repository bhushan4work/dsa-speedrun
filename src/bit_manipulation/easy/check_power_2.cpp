// statement- return true if n is power of 2. Otherwise, return false


//(optimal) t.c- O(1)  s.c- O(1)
bool isPowerOfTwo(int n){
    return n > 0 && (n & (n - 1)) == 0; // Check if n is greater than 0 and has only one bit set
}
