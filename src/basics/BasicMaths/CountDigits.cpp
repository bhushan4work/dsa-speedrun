#include <iostream> 
using namespace std;

int countdigits(int n){
        int count =0 ;
        while(n>0){
            int getlast = n % 10 ;  //gives remainder which is the last digit
            cout << getlast; //prints last digit

            n /=10 ;  //this reduces n by 1 digit
            count++ ;
        }
        return  count ;

        //another meth: int count = (int) (log10(n) + 1) ;
        //T.C is O(log10(n) ) as it is divided by 10 , base changes by the num it is divided with
}

int main(){
    int n ;
    cin >> n ;
    int digitcount = countdigits(n) ;
    cout << digitcount ;
}