#include<bits/stdc++.h>
using namespace std;

//T.C.- O(N^2) or O(N*(N+1)\2)
void selection_sortt(int arr[],int n){
    for(int i=0;i<=n-2;i++){ //loops till last2nd num as lastnum will get sorted byitself at the end
    int min=i;
    for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]) min=j;
        }
        int temp = arr[min]; //swaps value
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
    }
    selection_sortt(arr,n);
    cout << "sorted array is: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " "; //prints sortedarray
    }
    return 0;
}