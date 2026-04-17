// statement- 2 integers start, goal. Flip min no of bits of start int to convert it into goal int


//(optimal) t.c- O(1)  s.c- O(1)
int minBitsFlip(int start, int goal){
    int num = start ^ goal; // Variable to store bits that are diff in both nos
    int count = 0; // Variable to count no of set bits

    for (int i = 0; i < 32; i++){
        count += (num & 1); // Update count if rightmost bit is set
        num = num >> 1; // Shift no every time by 1 place
    }
    return count;
}