#include <bits/stdc++.h> //includes all the libraries combined
using namespace std;

//T.C.- push=pop= O(logn), top=O(n)
void explainPair(){
    pair<int,int> p1 = {1,3};
    cout << p.first << "  " << p.second; //prints 1 3

    pair<int , pair<int ,int> > p2 = {1, {2,3}}; //nested to print 3 num
    cout << p.first << " " << p.second.first << " " << p.second.second; //prints 1 2 3

    pair<int, int> arr[] = {{1,2} , {3,4} , {5,6}}; //pairs as array
    cout << arr[1].second; //prints 4
}

void explainVector(){
    vector<int> v1; //creates an empty container
    v1.push_back(1); //adds 1 into container
    v1.emplace_back(2); //incr its size and pushes 2 at the back

    vector <pair<int,int>> vec;
    vec.push_back({1,2}); //stores as pair - [(1,2)]
    vec.emplace_back(3,4); //[(1,2) , (3,4)]

    vector<int> v2(5,100); //contains {100,100,100,100,100}
    vector<int> v2(5); //contains arr of size 5 having garbage value,size can incr if push_back is used
    vector<int> v3(v2); //copyof vec v2 in v3

    //ex: take v = {20,10,50,4,5}
    vector<int>v;
    vector<int>::iterator it = v.begin(); //points memory address of element '20'
    it++; //jumps to next element i.e 10
    cout << *(it); //* prints the num not address

    it = it + 2; //shifts by 2 i.e num '4'
    cout << *i(t); //prints 4

    vector<int>::iterator it = v.
    vector<int>::iterator it = v.end(); //points out element after 5; if it-- is done after this then we get 5
    cout << v.back(); //prints 5

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *(it); //prints value in vector v
    }
    for(auto it = v.begin(); it = v.end(); it++){ //auto assigns to a vector iterator & its datatype automatically
        cout << *(it);
    }
    for(auto it : v){ //for each loop 
        cout << it;
    }

    v.erase(v.begin()+1); //gives {20,50,4,5}
    v.erase(v.begin()+1,v.begin()+3) //gives {10,5}

    vector<int>v4(2,200) //gives {200,200}
    v4.insert(v4.begin(),300); //gives {300,200,200}
    v4.insert(v4.begin()+1,2,10); //gives {300,10,10,200,200}

    vector<int>copy(2,50); //gives {50,50}
    v4.insert(v4.begin(),copy.begin(),copy.end()); //gives {50,50,300,10,10,200,200}

    cout << v4.size(); //gives size of vector
    v4.pop_back(); //removes last element in vector
    v4.clear(); //erases entire vector
    cout << v4.empty(); //gives boolean on whether vector is empty

    //vx={22,33} vy={44,55}
    vx.swap(vy); //vector values gets swapped with eachother
}

void explainList(){
    list<int>ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4); //{2,4}
    ls.push_front(5); //{5,2,4}
    //rest fxns same as vector
    //begin,end,clear,size,swap,insert
}

void explainDeque(){
    deque<int>dq;
    dq.push_back(1); //{1}
    dq.emplace_back(2); //{1,2}
    dq.push_front(4); //{4,1,2}
    dq.emplace_front(3); //{3,4,1,2}
    dq.pop_back(); //{3,4,1}
    dq.pop_front(); //{4,1}
    dq.back(); //used to reference the last element i.e it gives '1'
    dq.front(); //used to reference the first element i.e it gives '4'
    //rest fxns same as vector
    //begin,end,rend,rbegin,insert,size,swap
}

//stack- think of it as a bucket: 1st element will be at bottom and viseversa
//LIFO- last in, first out
void explainStack(){
    stack<int>st;
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.emplace(5); //{5,2,1}
    cout << st.top(); //prints last added value i.e 5
    st.pop(); //deletes last added value i.e 5
    cout << st.size();
    cout << st.empty();
    
    stack<int>st1,st2;
    st1.swap(st2);
}

//Queue- think of it as a line at ticket-stall
// FIFO- first in, first out
void explainQueue(){
    queue<int>q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(3); //{1,2,3}

    q.back() += 5; //does 3+5 i.e adds 5 to value at last
    cout << q.back(); //prints 8
    cout << q.front(); //prints 1
    q.pop(); //pops out the value at 1st position -{2,3}
    cout << q.front(); //prints 2
    //rest fxns same as stack- size swap empty
}

//PriorityQueue- think of it as a bucket
void explainPQ{
    //maxheap- largest num is given priority
    priority_queue<int>pq;
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.emplace(10); //{10,5,2}

    cout << pq.top(); //prints 10
    pq.pop(); //topmost gets deleted i.e 10
    //other fxns same as queue- size swap empty

    //for minimum heap- minimum num is given priority
    priority_queue<int, vector<int>, greater<int>>pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}
    pq.emplace(10); //{2,5,10}
    cout << pq.top(); //prints 2
}

//set- stores in sorted order,unique values 
void explainSet(){
    set<int>st;
    st.insert(1); //{1}
    st.emplace(2); //{1,2}
    st.insert(2); //{1,2}
    st.insert(4); //{1,2,4}

    auto it = st.find(2); //returns iterator which points to 2 i.e address & not the value
    auto it = st.find(5); //returns iterator(at last element) i.e '4' as 5 doesnt exist
    st.erase(4);

    int cnt = st.count(1); //counts if 1 exist, if yes then 1 else 0

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); //gives {1}

    //lowerbound & upperbound works in the same way as it does in vector
    //to get index
    auto it = st.upper_bound(4); //returns iterator of next element greater than which is asked
    auto it = st.lower_bound(2); //same like .find ,if a value doesnt exist then it points to immediate next greater num in set    
}

//MultiSet- similar to set,stores duplicate\same values too
void explainMultiSet(){
    multiset<int>ms;
    ms.insert(1); //{1} 
    ms.insert(2); //{1,2}
    ms.insert(2); //{1,2,2}

    ms.erase(2); //erases both 2's here
    //if we erase value it deletes all, but if we erase address it deletes a specific address & not all elements
    ms.erase(ms.find(2)); //erases address of 1st occurrence of 2
    ms.erase(ms.find(2),ms.find(2)+2); //finds address of 2 & goes till 2times i.e both 2's gets erased

    int cnt1 = ms.count(2);
    //rest fxns are same as set 
}

//UnOrderedSet- no order i.e doesnt sort the elements, stores unique values
void explainUSet(){
    unordered_set<int>us;
    //lowerbound & upperbound doesnt work here
    //rest fxns are same
}

void explainMap(){
    //there can be many similar values but the key to it is unique in sorted-order, think of it as same name & diff roll no
    map<int,int>mpp; //<key,value>
    map<int,pair<int,int>>mpp; //<key,<value,value>>
    map<pair<int,int>,int>mpp; //<<key,key>,value>

    mpp[1] = 2; //key-1 stores value-2
    mpp.emplace({3,1}); //key 3 stores value 1
    mpp.insert({2,4}); //key 2 stores value 4
    //above 3 values is stored in order of sorted-keys: 
    //  {1,2};
    //  {2,4};
    //  {3,1}; 
    mpp[{2,3}] = 10; // {{2,3},10}

    for(auto it : mpp){ //it stores in pair that is why .first .second is used to access the values in each pair
        cout << it.first << " " << it.second;
    }
    cout << mpp[1]; //gives '2' as it is value to the key 1
    cout << mpp[5]; //says null as key-5 doesnt exist

    auto it = mpp.find(3); //points to the iterator {3,1}
    cout << *(it).second; //access the elements inside, and .second gives value 1

    auto it = mpp.find(5);
    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);
    //rest other fxns are same
}

void explainMultiMap(){
    //stores duplicate keys,in sorted order,rest is same as map
}

void explainedUnorderedMap(){
    //not in sorted order,have unique keys
}

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    //they are same

    if(p1.first > p2.first) return true;
    return false;
}
void explainExtra(){
    //{1,2,4,3} 
    sort(a,a+n); //a=1(included) & a+n=after 3(excluded) , sorts in ascending order
    sort(v.begin(),v.end());

    sort(a+2,a+4); //sorts for a certain positions in vector

    sort(a,a+n,greater<int>); //sorts in descending order

    pair<int,int> a[] = {{1,2},{2,1},{4,1}};
    //myway condition: sort acc to 2nd element, if 2nd element is same then sort it acc to 1st element but in descending
    sort(a,a+n,comp);
    //{{4,1},{2,1},{1,2}}

    int num = 7; //binary of 7 is 111
    int cnt = __builtin_popcount(); //gives no of 1's or set bits
    
    long long num = 165786578687;
    int cnt = __builtin_popcountll(); //for long long nums

    string s = "123";
    sort(s.begin();s.end()); //start with sorted string to get all permutations

    do{
        cout << s << endl; 
    }while(next_permutation(s.begin(),s.end()));
    int maximum = *max_element(a,a+n);
    int minimum = *min_element(a,a+n);
}