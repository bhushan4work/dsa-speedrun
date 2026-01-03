//statement- Given an integer N, return true if it is a palindrome else return false
//palindrome- is a number that reads the same backward as forward. For ex: 121, 1331 are palindromes coz they remain the same when their digits are reversed.

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