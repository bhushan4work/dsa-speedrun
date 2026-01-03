//statement- given an element that appears more than n/2 times in arr. The arr is guaranteed to have majority element.

// method1(brute) t.c- O(n^2)  s.c- O(1)
int majorityElement(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        int cnt = 0; //counts freq of element
        for (int j = 0; j < arr.size(); j++){
            if (arr[j] == arr[i]){
                cnt++;
            }
        }
        if (cnt > (n / 2)){ // Check if frequency of arr[i] is greater than n/2
            return nums[i];
        }
    }
    return -1;
}

//method2(better) using hashing t.c- O(nlogn + n)  s.c- O(n) as we are storing elements in map
int majorityElement(vector<int>& arr) {
    map <int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++; //we increment freq of each element in arr as {element(key) :freq(value)}
    }
    for(auto it : mpp){
        if(it.second > (arr.size() / 2)){ // checks if freq of element is more than n/2 times
            return it.first ; //returns the majority element
        }
    }
    return -1;
}

//method3(optimal) using Moore's Voting Algorithm  t.c- O(n)  s.c- O(1)
int majorityElement(vector<int>& arr) {
    int cnt = 0;
    int el;
    for(int i=0;i<arr.size();i++){
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == el){
            cnt1++;
        }
        if(cnt1 > (arr.size() / 2)){
            return el;
        }
    }
    return -1;
}