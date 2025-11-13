#include <iostream> 

using namespace std ;

void pattern6(int n){
    for(int i=0;i<n;i++){
        for(char ch='A';ch <= 'A'+i;ch++){
                cout << ch << " " ;
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
        pattern6(n);
    }
}