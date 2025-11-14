#include <iostream> 

using namespace std ;

void pattern5(int n){
        int num = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout << num << " " ;
                num++ ;
            }
            cout << endl;
        }
    }

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        pattern5(n);
    }
}