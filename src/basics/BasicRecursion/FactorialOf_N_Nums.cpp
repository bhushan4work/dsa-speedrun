#include <iostream> 
using namespace std ;

int fact(int n){
    if(n==0){
        return 1;  //we return 1 as in '*' if we return 0,whole eqn will get zero after base condn gets true
    }
    else{
        return n * fact(n-1) ;
    }
}

int main(){
    int n ;
    cin >> n ;
    cout << fact(n) ;
}