// statement- 'arr' with an equal number of +ves & -ves is given.Without altering relative order of +ves & -ves elements,
//              return an arr of alternately +ves & -ves values.

// method1(optimal)  t.c- O(n + n/2)  s.c- O(n)
vector<int> RearrangeBySign(vector<int> &arr, int n){
    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if (arr[i] > 0)
        pos.push_back(arr[i]); // Add positive to pos[]
        else
        neg.push_back(arr[i]); // Add negative to neg[]
    }
    // Place positives at even indices and negatives at odd indices
    for (int i = 0; i < n / 2; i++){
        arr[2 * i] = pos[i];     // Even index → positive
        arr[2 * i + 1] = neg[i]; // Odd index → negative
    }
    
    return arr;
}

// method2(optimal)  t.c- O(n)  s.c- O(n)
vector<int> rearrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++){
        if (nums[i] < 0){
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else{
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }
    return ans;
}

// FAQ - when unequal amount of +ves & -ves values are present

// method1(optimal)  t.c- O(2n)  s.c- O(n)
void rearrange(vector<int> &arr){
    int n =arr.size()
    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if (arr[i] > 0)
            pos.push_back(arr[i]); // Add +ves to pos[]
        else
            neg.push_back(arr[i]); // Add -ves to neg[]
    }

    if (pos.size() > neg.size()){
        //this loop places all the alternate +ves & -ves & we loop till minority betn the two i.e neg here
        for (int i = 0; i < neg.size(); i++){  
            arr[2 * i] = pos[i];     // Even index → positive
            arr[2 * i + 1] = neg[i]; // Odd index → negative
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++){
            arr[index] = pos[i]; //placing remaining +ves at the end of arr
            index++;
        }
    }
    else{ // includes pos < neg & pos = neg cases

        //this loop places all the alternate +ves & -ves & we loop till minority betn the two i.e pos here
        for (int i = 0; i < pos.size(); i++){ 
            arr[2 * i] = pos[i];     // Even index → +ves
            arr[2 * i + 1] = neg[i]; // Odd index → -ves
        }
        //as in else case pos = neg is also included ,hence if pos = neg then below code will not run
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++){
            arr[index] = neg[i];   //placing remaining -ves at the end of arr
            index++;
        }
    }
    return arr;
}

