#include <iostream>
using namespace std ;
//2 inputs needed ,ex: for 3 3
// ******
// **  **
// *    *
// *    *
// **  **
// ******

void pattern10a(int n){
    for(int i=0; i< n; i++){
        for(int j=0;j<n-i;j++){
            cout << "*" ;
        }
        for(int j=0;j<2*i;j++){
            cout << " " ;
        }
        for(int j=0;j<n-i;j++){
            cout << "*" ;
        }
        cout << endl ;
    }
}

void pattern10b(int n){
    for(int i=0; i< n; i++){
        for(int j=0;j<=i;j++){
            cout << "*" ;
        }
        for(int j=0;j<2*(n-i)-2;j++){ //or can write 2*(n-i-1)
            cout << " " ;
        }
        for(int j=0;j<=i;j++){
            cout << "*" ;
        }
        cout << endl ;
    }
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        pattern10a(n);
        pattern10b(n);
    }
}