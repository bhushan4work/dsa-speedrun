#include <iostream>
using namespace std;

int countdigits(int n){
    int count = 0;
    int temp = n;
    while (temp > 0){
        count++;
        temp /= 10; // removes lastdigit & returns rest of the num
    }
    return count;

    // another meth: int count = (int) (log10(n) + 1) ;
    // T.C is O(log10(n) ) as it is divided by 10 , base changes by the num it is divided with
}

int main(){
    int n;
    cin >> n;
    int digitcount = countdigits(n);
    cout << digitcount;
}