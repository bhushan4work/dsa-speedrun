#include <iostream>
#include <cmath>
using namespace std ;

//ArmstrongNUm = suppose num=123 so if 1^3 + 2^3 + 3^3 = 123 then its ArmstrongNum

int main(){
    int n ;
    cout << "enter a num : " ;
    cin >> n ;
    int sum = 0 ;
    int dup = n ;   //for making a duplicate copy of the num to compare with sum

    while(n>0){
        int lastdigit = n % 10 ; //gives lastdigit
        sum += pow(lastdigit, 3); //does the cube of the lastdigit
        n /= 10 ; //remove lastdigit
    }

    if (dup == sum){
        cout << "yes. Its a ArmstrongNum" ;
    }
    else{
        cout << "no. Its not a ArmstrongNum" ;
    }
}