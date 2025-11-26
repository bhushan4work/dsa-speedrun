#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n ; 
    cin >> n ;
    // T.C - O( sqrt(n) )
    int count =0 ;
    for(int i =1;i*i<=n ;i++){ //we loop till root(n) as after that divisors repeat
        if(n%i==0){
            count++ ;
            if(n/i != i){ //counts divisor in pair, ex: for n=36 - 2*18
                count++ ;
            }
        }
    }
    if(count ==2){
        cout << "yes .Its a primeNum" ;
    }
    else{
        cout << "no. Its not a primeNum" ;
    }
}