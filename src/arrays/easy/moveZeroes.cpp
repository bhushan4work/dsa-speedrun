
void moveZeroes(vector<int>& arr, int n){
    //method1- (brute) t.c.- O(n + x + (n-x)) = O(2n) , s.c- O(x) & for worstcase(no zeroes)- O(n)
    //Zeroes at the end
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]); //stores nonZero element in temp arr
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i] = temp[i]; //puts back all nonZero element in arr from temp
    }
    for(int i=temp.size();i<n;i++){
        arr[i] = 0; //assigns remaining values as 0
    }
    return arr;

    //Zeroes at beginning
    vector<int> temp;
    int cnt = 0; //counts the num of zeroes in arr
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);  // store all nonZeroes in temp arr
        }
        else{
            cnt++;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        arr[i] = 0; //puts back all the zeroes at beginning
    }
    int j = 0; //pointer to place nonZero elements back to arr
    for(int i = cnt; i<n; i++) {
        arr[i] = temp[j]; //puts zeroes at the start of array
        j++; //to get next element from temp
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