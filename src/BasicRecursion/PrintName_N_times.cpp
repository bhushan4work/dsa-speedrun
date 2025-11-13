#include <iostream>
using namespace std ;

//T.C - O(n) , S.C - O(n) ;

void func(int i,int n){
    if(i > n) return;  //base condition ,if this is absent stack overflow takes place
    cout << "hello world" ;
    func(i+1,n);
}

int main(){
    int n ;
    cin >> n ;
    func(1,n) ;
}