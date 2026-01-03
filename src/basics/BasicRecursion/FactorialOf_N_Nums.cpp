//statement- Given a number X,  print its factorial
//           To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.
//Note: X is always a positive number

int fact(int n){
    if(n==0){
        return 1;  //we return 1 as in '*' if we return 0,whole eqn will get zero after base condn gets true
    }
    else{
        return n * fact(n-1) ;
    }
}

int main(){
    int n ;
    cin >> n ;
    cout << fact(n) ;
}