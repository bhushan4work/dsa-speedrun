#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n ;
    cin >> n ;

    //method1
    //below loop runs for n iterations, T.C is O(n)
    for(int i =1 ;i <=n ;i++){
        if(n%i==0){
            cout << i << " " ;
        }
    }

    //method2
    //suppose n=36 so its factors are 1*36, 2*18 ,etc but after 6*6 the factors repeat itself
    // so we wanna print till 6*6 only as we get all factors .
    vector<int> list;     //list that stores values
    //O(sqrt(n)) - T.C
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            list.push_back(i);
            if(n / i != i){  //counts divisor in pair
            list.push_back(n / i); 
            }
        }
    }
    //O(n  log n) : n is num of factors - T.C
    sort(list.begin(), list.end());    // sorts list into ascending order
    //O(num of factors) - T.C
    for(int it : list ){
       cout << it << " " ;
    }
    //for total T.C ,add all T.C
}