#include<bits/stdc++.h>
using namespace std;

void recursiveBubble_sortt(int arr[], int n){
    //recursion stops when arraysize is 1
    if(n == 1) return; //base condition

    for(int i=0;i<=n-2;i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i+1]; //swaps j+1 with j
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
    //sort remaining elements
    recursiveBubble_sortt(arr,n-1);
}

int main(){
    int n;
    cin>>n; //takes input of size of the array
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; //takes the array input
    }
    recursiveBubble_sortt(arr,n); 
    cout<< "sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i] << " "; //prints sorted array
    }
}
