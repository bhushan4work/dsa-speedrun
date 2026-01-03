//statement- You are given an array. The task is to reverse the array and print it

void reverseArrayy(int i,int arr[],int n) {
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArrayy(i+1,arr,n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverseArrayy(0,arr,n);
    cout <<"reversed array is: ";
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
}