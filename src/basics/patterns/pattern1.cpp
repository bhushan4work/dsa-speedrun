#include <iostream>

using namespace std ;

void pattern1a(int n){
    for(int i=0; i< n; i++){
        for(int j=0 ; j< n-i-1; j++){
                cout << " ";
        }
        for(int j= 0; j< 2*i +1; j++){
                cout << "*";
        }
        for(int j=0; j< n-i-1; j++){
                cout << " ";
        }
        cout << endl ;
    }
}

void pattern1b(int n){
    for(int i=0; i< n; i++){ //to get a common line in betn put i=1
        for(int j=0 ; j< n+i-n; j++){
                cout << " ";
        }
        for(int j= 0; j< 2*(n-i)-1; j++){
                cout << "*";
        }
        for(int j=0; j< n+i-n; j++){
                cout << " ";
        }
        cout << endl ;
    }
}

int main(){
    int t ;
    cin >> t ;

    for(int i = 0; i < t; i++){
        int n ;
        cin >> n ;
        pattern1a(n);
        pattern1b(n);
    }
}