//intersection of 2 sorted arr's
//ex arr1[1,2,3,3,4] arr2[1,2,2,3,3,4] - here as 2 has only one 2 as a partner in 2nd arr ,only 1time 2 will be added but for 3 it will be added 2times as 2 pairs exists

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
    //method1(brute)-  t.c.- O(n1*n2)  s.c.- O(n2)  ,(this approach gives an TLE error on submission)
	vector<int> ans;
	vector<int> visited(m, 0); //marks which indices of arr2 are already used
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i] == arr2[j] && visited[j] == 0){ //checks if both elements are same & if this arr2[j] element was NOT matched earlier.
				ans.push_back(arr1[i]);
				visited[j] = 1; //Marks arr2[j] as "used".
				break; //Stop the inner loop because arr1[i] is already matched once
			}
			if(arr2[j] > arr1[i]) break; //as arr is sorted there is no point of checking for greater

		}
	}
	return ans;

    //method2(optimal)- 2pointer  t.c.- O(n1+n2)  s.c.- O(n1+n2) to store & return ans 
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){  
            i++;   //Moves the pointer of the smaller value forward as arr is sorted we need to incr to catchup the same values 
        }
        else if (arr1[i] > arr2[j]){
            j++;  //Moves the pointer of the smaller value forward as arr is sorted we need to incr to catchup the same values
        }
        else{
            ans.push_back(arr1[i]); //when same value found , both pointers r moved forward to avoid duplicates 
            i++;
            j++;
        }
    }
    return ans;

}