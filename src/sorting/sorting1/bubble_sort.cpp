#include<bits/stdc++.h>
using namespace std;
//BubbleSort- push maxnum to last by adjacent swap

//T.C.- worstcase- O(N^2) O(N*(N+1)\2) , bestcase- O(N)
void bubble_sortt(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1]; //adjacent swaps
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sortt(arr,n);
    cout<<"sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " "; //prints sortedarray
    }
}