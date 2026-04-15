// statement- return no of set bits (1s) in its binary representation


//(brute) t.c- O(logn)  s.c- O(1)
int countSetBits(int n){
    int count = 0;
    while (n > 0){
        count += (n & 1); // Check if least significant bit is set (1)
        n >>= 1;          // Right shift n by 1 to process next bit
    }
    return count;
}


//(optimal) t.c- O(k)  s.c- O(1) k: no of set bits
int countSetBits(int n){
    int count = 0;
    while (n != 0){
        n &= (n - 1); // Turn off the rightmost set bit i.e make it 0
        count++;      // Increment the count
    }
    return count;
}
