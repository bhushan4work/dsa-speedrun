//statement- Given an integer N, write a program to print numbers from 1 to N

//method1
void func(int i,int n){
    if (i>n) return;
    cout << i ;
    func(i+1, n);
}

//method2 :without using '+' i.e by backtracking
void funcc(int i,int n){
    if(i<1) return;
    funcc(i-1, n) ;  //we call this fxn first before print,this goes on till i<1 &
    //once its true 'return' starts executing back so we get 1,2,..N
    cout << i ;
}

int main (){
    int n ;
    cin >> n ;
    func(1,n) ;
    funcc(n ,n);
}