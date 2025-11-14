#include <iostream> ;

using namespace std ;

void pattern7(int n){
    for(int i=0;i<n;i++){
        char ch = (char)('A' + i) ;
        for(int j=0; j<=i ; j++){
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
        pattern7(n);
    }
}