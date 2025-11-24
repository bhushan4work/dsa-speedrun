#include<bits/stdc++.h>
using namespace std;

//in vector<int> &arr, why & is used?
//we are passing the original vector,No copying,changes made inside fxn happen directly to real array,Fast\memory-efficient

void merge(vector <int> &arr,int low, int mid,int high){
    vector<int> temp;
    //[low...mid]   -first array
    //[mid+1...high] -second array
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){ //This loop runs as long as both sides still have elements & stops when one of the sides gets empty
    if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){ //when left side still have leftover elements
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){ //when right side still have leftover elements
    temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){ //Copy back to original array
        arr[i] = temp[i-low];
    }
}

void mS(vector<int> &arr,int low,int high){
    if(low == high) return;
    int mid = (low + high) / 2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort(vector <int> &arr,int n){
    if(n <= 1) return; //i.e if only 1 or No element exists,break as nothing to sort
    mS(arr,0,n-1); 
}
int main(){
    int n; //n = num of elements
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){ //to take input for the array
        cin>>arr[i];
    }

    mergeSort(arr,n);

    cout << "sorted array is: ";
    for(int i=0;i<n;i++){ //to print the sorted array
        cout<<arr[i]<< " ";
    }
    return 0;
}