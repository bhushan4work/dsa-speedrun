#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low, int high){
    int pivot = arr[low]; //1st element in array
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){ // Move i right while arr[i] <= pivot
            i++;
        }
        while(arr[j]>pivot && j>=low+1){ // Move j left while arr[j] > pivot
            j--;
        }
        if(i<j) swap(arr[i],arr[j]); //swaps i with j
    }
    //Place pivot in its correct position
    swap(arr[low], arr[j]); //swaps pivot with j
    return j; //as pivot goes to j, it's the pIndex
}

void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}

//as we are using &arr here,we need not to return arr as we modify the original arr rather than making a copy
void quicksort(vector<int> &arr) {
    if (!arr.empty()) qs(arr, 0, (int)arr.size() - 1);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i]; //takes input for the array
    }
    quicksort(arr);

    cout<< "sorted array is: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " "; //prints sorted array
    }
    return 0;
}