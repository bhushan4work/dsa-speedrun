// statement- val in arr is type of fruit, we got 2 baskets to fill. each basket should have 1 type of fruit only(cnt of this fruit can be anything).
//            return length of total fruits including both baskets


// (brute) t.c- O(n^2)  s.c- O(1)
// as we have maxbasket to fill fruits = 2 so size of map will not go more than that & so it doesnt affect t.c & s.c
int totalFruit(vector<int> &arr){
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++){
        unordered_map<int, int> mpp; // Create a map to store the count of fruit types

        for (int j = i; j < fruits.size(); j++){
            mpp[fruits[j]]++; // Add current fruit to the mpp
            if (mpp.size() <= 2){ // If mpp has more than 2 types, break
                maxLen = max(maxLen, j - i + 1); // Update maximum fruits collected
            }
            else{
                break; // If mpp has more than 2 types, break
            }
        }
    }
    return maxLen;
}

// (better) t.c- O(n+n)  s.c- O(1)
// as we have maxbasket to fill fruits = 2 so size of map will not go more than that & so it doesnt affect t.c & s.c
int totalFruit(vector<int> &arr){
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<int, int> mpp;

    while (r < arr.size()){
        mpp[arr[r]]++; //Add the current fruit to map & incr its cnt

        if (mpp.size() > 2){
            while (mpp.size() > 2){ //we keep on shrinking left pointer to the right until we get mpp.size <= 2
                mpp[arr[l]]--; //Remove one fruit from the left side
                if (mpp[arr[l]] == 0){ //If certain fruit's type cnt becomes 0, remove it completely from map
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }

        if (mpp.size() <= 2){
            maxLen = max(maxLen, r - l + 1);  //calculate current window size & update maxLen 
        }
        r++;
    }
    return maxLen;
}

// (optimal) t.c- O(n)  s.c- O(1)
// as we have maxbasket to fill fruits = 2 so size of map will not go more than that & so it doesnt affect t.c & s.c
int totalFruit(vector<int> &arr){
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<int, int> mpp;
    while (r < arr.size()){
        mpp[arr[r]]++; //Add the current fruit to map & incr its cnt

        if (mpp.size() > 2){
            mpp[arr[l]]--; //Remove one fruit from the left side
            if (mpp[arr[l]] == 0){ //If certain fruit's type cnt becomes 0, remove it completely from map
                mpp.erase(arr[l]);
            }
            l++; //move 
        }

        if (mpp.size() <= 2){
            maxLen = max(maxLen, r - l + 1); //calculate current window size & update maxLen 
        }
        r++;
    }
    return maxLen;
}
