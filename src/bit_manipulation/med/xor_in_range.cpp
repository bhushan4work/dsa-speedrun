// statement- Given 2 integers L and R. Find XOR of elements in range [L , R] 

//(brute) t.c- O(n)  s.c- O(1)
int findRangeXOR(int l, int r){
    int ans = 0; // To store XOR of nos
    for (int i = l; i <= r; i++){ // XOR all nos from l to r
        ans ^= i;
    }
    return ans;
}


//(optimal) t.c- O(1)  s.c- O(1)
int XORtillN(int n){
    //below pattern is observed after xor-ring every 4 nos 
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    if (n % 4 == 3) return 0;
    return n;
}
int findRangeXOR(int l, int r){
    //ex: we want 4 to 7, so we do (xor till 3) ^ (xor till 7) = (xor of l to r) as xor of same no will get cancelled
    return XORtillN(l - 1) ^ XORtillN(r); 
}

