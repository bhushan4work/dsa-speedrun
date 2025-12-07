//Left rotate an array by D places
#include <bits/stdc++.h>
using namespace std;

//rotateArray by d places - shifting position of the elements either to the left or right by k places

vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    k = k % n; //if k is greater than n ,we only need to rotate the remainder
    
    //method1(brute) t.c.- O(k+ (n-k) + k ) = O(n+k) , s.c.-(extra space)- O(k)
    //for left rotation
    int temp[n]; //or vector<int> temp(k);
    for(int i=0;i<k;i++){ 
        temp[i] = arr[i]; //store the elements that is to be rotated in temp arr
    }
    for(int i=k;i<n;i++){
        arr[i-k] = arr[i]; //shifts the remaining elements to left by k places
    }
    for(int i=n-k;i<n;i++){
        arr[i] = temp[i-(n-k)]; //puts the temp elements back
    }
    return arr ;

    //for right rotation 
    int temp[n]; //or vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i]; //stores k elements
    }
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i]; //shifts elements to right 
    }
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i]; //puts temp elements back 
    }
    return arr;
    
    //method2(optimal approach) t.c.- O(k + (n-k) + n)  , s.c.-(extra space)- O(1)
    //reverse(a,k) → reverse(k,n) → reverse(a, n)
    //for left rotation - (for codeStudio que)
    reverse(arr.begin(),arr.begin()+k); //last element i.e arr+k is exclusive(i.e < arr+k) 
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());

    //reverse(a,n) → reverse(a,k) → reverse(k, n)
    //for right rotation -(for leetcode que) 
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k); //last element i.e arr+k is exclusive(i.e < arr+k)
    reverse(arr.begin()+k,arr.end());
    
}    

