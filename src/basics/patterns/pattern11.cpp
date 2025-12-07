#include <iostream>
using namespace std ;
//2 inputs needed ,ex: for 3 3
// *    *
// **  **
// ******
// **  **
// *    *

void pattern11a(int n){
    for(int i=0; i< n; i++){
        for(int j=0;j<=i;j++){
            cout << "*" ;
        }
            for(int j=0;j<2*(n-i)-2;j++){
            cout << " " ;
        }
        for(int j=0;j<=i;j++){
                cout << "*" ;
        }
        cout << endl ; 
    }
}

void pattern11b(int n){
    for(int i=1; i< n; i++){
        for(int j=1;j<=n-i;j++){
            cout << "*" ;
        }
        for(int j=1;j<=2*i;j++){
            cout << " " ;
        }
        for(int j=1;j<=n-i;j++){
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
        pattern11a(n);
        pattern11b(n);
    }
}