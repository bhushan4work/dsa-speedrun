#include <iostream>
using namespace std ;

//T.C - O(n) , S.C - O(n)
//recursion happens in 2 ways namely parameterised & functional

//method1 : parameterised way
void sum(int i, int s, int n){
    if(i>n){
        cout << s ;
        return;
    }
    sum(i+1,s+i, n);
}

//method2 : functional
//it keeps on calling same fxn until base condn is true , thereafter the fxn returns
int summ(int n){
    if(n==0) return 0;
    return n + summ(n-1);
}

int main(){
    int n ;
    cin >> n ;
    sum(1,0, n);

    cout << summ(n) ;
}