//statement- Given a number n. Find its unique prime factors
//example workflow
//  2 | 780 |0
//  2 | 390 |0
//  3 | 195 |0
//  5 | 65  |0
// 13 | 13  |0
//    | 1   |


//(optimal) t.c- O(√n * logn)  s.c- O(k)
vector<int> primeFac(int n) {
    vector <int> list;
    for(int i=2;i * i<=n ; i++){  //we loop from 2 to √n
        if(n % i == 0){ 
            list.push_back(i); 
            while(n % i == 0){ //keep on dividing n with i until its not divisible
                n = n / i ;
            }
        }
    }
    if(n != 1) list.push_back(n); //means that factor '13' wasnt added & so we add it
    return list;
}