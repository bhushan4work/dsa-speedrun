// statement- 2 integers n, i. return true if ith bit in binary representation of n is set (i.e. equal to 1). Otherwise, return false
// we index binary no from last starting from 0 i.e 1101 - index- 3-2-1-0
// (brute) t.c- O(logn)  s.c- O(logn)
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
// (optimal) t.c- O(1)  s.c- O(1)
// ex: n = 5 → 101 (binary) , i = 2, 1 << 2 = 100, 101 & 100 = 100 → non-zero → bit is set
bool checkIthBit(int n, int i){
    // Check if the i-th bit is set using bitwise AND operation
    return (n & (1 << i)) != 0; // If the i-th bit is 1, the result will be non-zero
}



// statement- set ith bit i.e if ith bit is 0 turn it to 1
// (optimal) t.c- O(1)  s.c- O(1)
int setIthBit(int n, int i){
    return n | (1 << i); // left shift 1 by i places, apply OR operator
}



// statement- set the rightmost unset (i.e 0) bit of its binary representation to 1 & return resulting integer. If all bits are already set, return number as it is
// (optimal) t.c- O(1)  s.c- O(1)
int setBit(int n){
    // n + 1 flips the rightmost 0 to 1 & turns all trailing 1s into 0s
    return n | (n + 1); // OR operation ensures that bit becomes set in final ans
}



// statement- clear last set bit (i.e rightmost) i.e if ith bit is 1 turn it to 0 else keep it as it is
// (optimal) t.c- O(1)  s.c- O(1)
int removeLastSetBit(int n){
    return n & (n - 1); // substract 1 from n, apply AND operator
}



// statement- clear ith bit i.e if ith bit is 1 turn it to 0 else keep it as it is
//(optimal) t.c- O(1)  s.c- O(1)
int clearIthBit(int n, int i){
    return n & ~(1 << i); // left shift 1 by i places, apply NOT operator to it, apply AND operator
}



// statement- toggle ith bit i.e if ith bit is 1 turn it 0 & vise versa
// (optimal) t.c- O(1)  s.c- O(1)
int toggleIthBit(int n, int i){
    return n ^ (1 << i); // left shift 1 by i places, apply XOR operator
}