#include <iostream> 
#include <climits>  // For INT_MAX and INT_MIN
using namespace std ;

//LeetCode 7. Reverse Integer - Medium

int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
            return 0;
        }
        reversed = reversed * 10 + digit;
    }
    return reversed;
}

int main(){
    int x;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}
