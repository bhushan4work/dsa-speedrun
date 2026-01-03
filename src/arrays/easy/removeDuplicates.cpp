//statement- remove duplicate from sorted array

int removeDuplicates(vector<int>& nums) {
    //method1(brute force) - t.c.- O(nlogn + n)
    set <int> st; //stores unique elements from arr
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]); //inserts unique elements in set from arr nums
    }
    int index = 0;
    for(auto it : st){
        nums[index] = it; //changes arr of duplicates to arr of unique elements
        index++;
    }
    return index; //returns num of unique elements

    //method2 (optimal) - using 2 pointer , t.c.- O(n) , s.c.- O(1)
    if(nums.size() == 0) return 0;

    int i = 0; //element at 0th index is 1st unique element 
    for(int j = 1; j < nums.size(); j++) {
        if(nums[j] != nums[i]) { //checks for unique elements in arr
            nums[i+1] = nums[j];  //place next unique number at nums[i+1] i.e at nums[0+1]
            i++;
        }
    }
    return i + 1; //gives the size of array, as arr starts from 0th index we do +1

} 