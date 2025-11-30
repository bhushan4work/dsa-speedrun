//find union of 2 sorted arr- take unique elements from 2 arr's & join them into a single arr
#include <bits/stdc++.h>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    //method1(brute)- t.c.- O(n1logn + n2logn) + (n1 + n2)  s.c.- O(n1+n2) + O(n1+n2) here in s.c. n1 & n2 is used to return the ans
    int n1 = a.size();
    int n2 = b.size();

    set<int> st; //as set includes only unique values
    for(int i=0;i<n1;i++){
        st.insert(a[i]); //stores unique values from arr a
    }
    for(int i=0;i<n2;i++){
        st.insert(b[i]); //stores unique values from arr b
    }

    vector<int> temp;
    for(auto it : st){
        temp.push_back(it); //stores unique values from both arr into temp
    }
    return temp;

    //method2(optimal)- 2pointer- t.c.- O(n1+n2) , s.c.- O(n1+n2) here in s.c. n1 & n2 is used to return ans
    int n1 = a.size();
    int n2 = b.size();
    i = 0;  //pointer to iterate in 1st arr
    j = 0;  //pointer to iterate in 2nd arr
    vector<int> unionArr;
    while(i<n1 && j<n2){ //loops until arr1 & arr2 both gets exhausted
        if(a[i] <= b[j]){ 
            if(unionArr.size() == 0 || unionArr.back() != a[i]){ // Prevent adding duplicates by checking at the back
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){ // Prevent adding duplicates by checking at the back
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){  // if 1st array gets exhausted & 2nd remains we loop thru the remaining elements in 2nd arr
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n1){  // if 2nd array gets exhausted & 1st remains we loop thru the remaining elements in 1st arr
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    return unionArr;


     
}