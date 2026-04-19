//statement- Given an integer N, return all divisors of N

int main(){
    int n ;
    cin >> n ;

    //(brute)
    //below loop runs for n iterations, T.C is O(n)
    for(int i =1 ;i <=n ;i++){
        if(n%i==0){
            cout << i << " " ;
        }
    }

    //(optimal) t.c- O(sqrt(n))
    //suppose n=36 so its factors are 1*36, 2*18 ,etc but after 6*6 factors repeat itself
    vector<int> list;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            list.push_back(i); // this will add 1 from 1*36
            if(n / i != i){  //this prevents adding same divisor twice e.g 6*6
                list.push_back(n / i); // adds 36 from 1*36
            }
        }
    }
    //O(n  log n) : n is num of factors - T.C
    sort(list.begin(), list.end());    // sorts list into ascending order
    //O(num of factors) - T.C
    for(int it : list ){
       cout << it << " " ;
    }
}