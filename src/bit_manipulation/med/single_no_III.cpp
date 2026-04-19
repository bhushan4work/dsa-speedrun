// statement- every integer in arr appears 2x except for 2 integers. return 2 integers that appear only 1x in arr


//(brute) t.c- O(2n)  s.c- O(n)
vector<int> singleNumber(vector<int> &nums){
    vector<int> ans;
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++){
        mpp[nums[i]]++; // Update the map
    }

    for (auto it : mpp){
        if (it.second == 1){ // If frequency is 1
            ans.push_back(it.first); // Add the element to the result array
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}


//(optimal) t.c- O(n)  s.c- O(1)
vector<int> singleNumber(vector<int> &nums){
    long xorr = 0; // Variable to store XOR of all elements

    for (int i = 0; i < nums.size(); i++){
        xorr = xorr ^ nums[i]; // Update the XOR
    }

    // Variable to get rightmost bit set i.e 1 in overall XOR
    int rightmost = (xorr & (xorr - 1)) ^ xorr;

    // Variables to stores XOR of elements in bucket 1 ,2
    int buc1 = 0, buc2 = 0;
    for (int i = 0; i < nums.size(); i++){
        // Divide nos among bucket 1, 2 based on rightmost set bit
        if ( (nums[i] & rightmost) != 0){
            buc1 = buc1 ^ nums[i];  // xor's all no where bit is 1
        }
        else{
            buc2 = buc2 ^ nums[i];  // xor's all no where bit is 0
        }
    }

    if (buc1 < buc2) return {buc1, buc2}; // Return the result in sorted order
    return {buc2, buc1};
}