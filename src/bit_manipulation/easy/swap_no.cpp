//statement- 2 integers a, b. swap them in-place using 2 var (i.e without using a 3rd temporary var) 


//method1(optimal) t.c- O(1)  s.c- O(1)  
void swapXOR(int &a, int &b) {
    a = a ^ b; //  XOR a and b, store in a
    b = a ^ b; //  XOR new a with b, result is original a → store in b

    a = a ^ b; // XOR new a with new b, result is original b → store in a
}