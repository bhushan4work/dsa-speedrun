#include <bits/stdc++.h>
using namespace std;

//optimal approach t.c.- O(n) , s.c. (in algo) - O(n) , s.c.-(extra space)- O(1) 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Left Rotate an Array by One
    int temp = arr[0]; //stores the 1st element
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i]; //shifts each element to the left by 1
    }
    arr[n-1] = temp; //shifts 1st element to the last
    return arr;

    //right rotate an array by one
    int temp = arr[n-1] //stores the last element
    for(int i=n-1;i>0;i--){
        arr[i] = arr[i-1]; //shifts each element to the right by 1
    }
    arr[0] = temp; //shifts last element to the 1st
    return arr;
}