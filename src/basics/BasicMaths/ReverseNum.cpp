#include <bits/stdc++.h>
#include <climits>  // For INT_MAX and INT_MIN
using namespace std ;

//LeetCode 7. Reverse Integer - Medium
int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int lastdigit = x % 10;
        x /= 10; //removes lastdigit & returns rest of the num

        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) { //avoids overflow
            return 0;
        }
        reversed = reversed * 10 + lastdigit;
    }
    return reversed;
}

int main(){
    int x;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}
