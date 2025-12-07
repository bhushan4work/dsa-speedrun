#include <iostream> 
using namespace std ;
//2 inputs needed ,ex: for 3 3
// 3 3 3 3 3 
// 3 2 2 2 3 
// 3 2 1 2 3 
// 3 2 2 2 3 
// 3 3 3 3 3 

void pattern13(int n){
    for(int i=0; i< 2*n-1; i++){
        for(int j=0;j<2*n-1;j++){
            int up= i;
            int down= 2*n-2-i ;
            int right= 2*n-2 -j ;
            int left=j;
            cout << n - min(min(up, down), min(right, left)) << " ";
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
        pattern13(n);
    }
}