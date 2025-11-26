#include <iostream> 
using namespace std ;

//LeetCode 9. Palindrome Number - Easy
bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }

    int reversed = 0;
    int original = x;

    while (x > 0) {
        int lastdigit = x % 10; 
        reversed = reversed * 10 + lastdigit; 
        x /= 10; //removes lastdigit & returns rest of the num
    }
    return original == reversed; //returns true if palindrome, else false
}

int main(){
    cout << isPalindrome(121) << endl;
    return 0;
}