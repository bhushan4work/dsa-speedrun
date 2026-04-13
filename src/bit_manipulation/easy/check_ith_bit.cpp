// statement- 2 integers n, i. return true if ith bit in binary representation of n is set (i.e. equal to 1). Otherwise, return false
// we index binary no from last starting from 0 i.e 1101 - index- 3-2-1-0


// method1(brute) t.c- O(logn)  s.c- O(logn)
bool checkIthBit(int n, int i){
    string binary = "";
    // Convert the no into its binary representation
    while (n > 0){
        binary += (n % 2 == 0 ? '0' : '1'); // Append '0' or '1' depending on least significant bit
        n /= 2;                             // Move to next higher bit
    }

    if (i >= binary.size()) return false; // If bit index > length of binary str, bit is 0

    return binary[i] == '1'; // Return true if i-th bit is 1, otherwise false
}


// method2(optimal) t.c- O(1)  s.c- O(1)
// ex: n = 5 → 101 (binary)
//     i = 2
//     1 << 2 = 100
//    101 & 100 = 100 → non-zero → bit is set
bool checkIthBit(int n, int i){
    // Check if the i-th bit is set using bitwise AND operation
    return (n & (1 << i)) != 0; // If the i-th bit is 1, the result will be non-zero
}