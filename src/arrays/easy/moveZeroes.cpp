
void moveZeroes(vector<int>& arr, int n){
    //method1- (brute) t.c.- O(n + x + (n-x)) , s.c- O(x) & for worstcase(no zeroes)- O(n)
    //Zeroes at the end
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]); //stores nonZero element in temp arr
        }
    }
    int nz = temp.size();
    for(int i=0;i<nz;i++){
        arr[i] = temp[i]; //puts back all nonZero element in arr
    }
    for(int i=nz;i<n;i++){
        arr[i] = 0; //assigns remaining values as 0
    }
    return arr;

    //Zeroes at beginning
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            temp.push_back(arr[i]);   // store all zeroes in temp arr
        }
    }
    int z = temp.size();
    for(int i = 0; i < zc; i++) {
        arr[i] = 0; //puts zeroes at the start of array
    }
    int j = z;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) { 
            arr[idx] = arr[i]; //puts the nonZero elements after the temp arr of zeroes
            j++;
        }
    }
    return arr;

    //method2- (optimal) -2pointer t.c.- O(x + (n-x)) = O(n) , s.c.- O(1)
    //Zeroes at the end
    int j= -1; //or INT_MIN or any value less than 0
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i; //j stores the index where 0 exists
            break;
        } //from this loop we get the 1st zeroth element
    }
    for(int i=j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]); //i iterates thru the loop & swaps the nonZero with j ,j always points to zeroth element
            j++; //j moves to next zeroth position
        }
    }
    
    //Zeroes at beginning
    int j = -1;  
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            j = i; //j stores the index where nonZero exists
            break;
        } //from this loop we get the 1st nonZero element
    }
    for (int i = j + 1; i < n; i++) {
        if (arr[i] == 0) { 
            swap(arr[i], arr[j]);  //i iterates thru the loop & swaps Zero with j ,j always points to nonZero element
            j++;  //j moves to next NON-zero position
        }
    }

}