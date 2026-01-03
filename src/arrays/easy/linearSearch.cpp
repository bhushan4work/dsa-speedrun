//statement- find whether ‘num’ is present in the array or not

int linearSearch(int n, int num, vector<int> &arr){
    for(int i=0;i<n;i++){
        if(arr[i] == num){ //checks for the num in arr & returns its index
            return i;
        }
    }
    return -1;
}