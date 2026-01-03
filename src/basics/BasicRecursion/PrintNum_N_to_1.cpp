//statement- Given an integer N, write a program to print numbers from N to 1

//method1
void func(int i, int n){
    if(i<1) return;
    cout << i ;
    func(i-1,n);
}
    
//method2 : by backtracking i.e using '+' rather than '-'
void funcc(int i, int n){
    if(i>n) return ;
    funcc(i+1, n);
    cout << i ;
}

int main (){
    int n ;
    cin >> n ;
    func(n,n) ; //we start from n so here i is taken as n in fxn
    funcc(1,n) ;
}