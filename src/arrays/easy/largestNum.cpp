#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    //method1 - sort the array & return the lastnum , t.c.- O(nlogn) 
    sort(arr.begin(), arr.end());
    return arr[n-1];

    //method2- assume 1st num in arr as largest & compare it with others,
    // if greater num is found change it with the largest one t.c.- O(n)
    int largest = arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}
