#include <iostream>
using namespace std ;

int main(){
    //method1
    //O( min(n1,n2) ) - T.C
    int n1 , n2 ;
    cin >> n1 ;
    cin >> n2 ;

    for(int i = Math.min(n1,n2); i >=1 ; i--){
        if(n1 % i ==0 && n2 % i ==0){
            cout << i ;
            break ;
        }
    }

    //method2
    //when log is taken in T.C ? whenever there is division,num of iterations is in terms of log
    //also as n1 & n2 changes each time we cant give it a base so take it as a variable
    //T.C - O( log base t min(n1,n2))  where t is variable according to input
        
    //Euclidean algorithm - gcd(n1,n2) = gcd(n1-n2,n2)
    //instead of substracting again n again here , we can use
    // (greater % smaller) to avoid unwanted steps and jump near the ans
    while(n1 > 0 && n2 >0 ){
        if(n1>n2){
            n1 %= n2 ;
        }
        else{
            n2 %= n1 ;
        }

        if(n1 ==0 ){
            cout << n2 ;
        }
        else{
            cout << n1 ;
        }
    }
}