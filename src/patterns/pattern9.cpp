#include <iostream>

using namespace std ;

void pattern9(int n){
    for(int i=0; i< n; i++){
        for(char ch=(char)('A'+ (n-i-1) ) ; ch<= 'A'+ n-1; ch++){ //or put ch='e'-i;ch<='e'
            cout << ch ; 
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
        pattern9(n);
    }
}