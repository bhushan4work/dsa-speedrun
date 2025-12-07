#include <iostream> 
using namespace std ;
//2 inputs needed ,ex: for 3 3
// 123
// 12
// 1

void pattern2(int n){
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= n - i; j++){  
            cout << j ;  // for upward put j<=i
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
        pattern2(n);
    }
}