#include<bits/stdc++.h>
using namespace std;

void recursiveInsertion_sortt(int arr[],int i,int n){
    //recursion stops when i == n
    if (i == n) return;  //base condition

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1]; //swaps j-1 with j
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
    recursiveInsertion_sortt(arr,i+1,n);
}

int main(){
    int n; //size of the array
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; //takes input for array of size n
    }
    recursiveInsertion_sortt(arr,0,n); 
    cout<<"sorted array is: ";
    for(int i=0;i<n;i++){
        cout<< arr[i] << " "; //prints the sorted array
    }
}
