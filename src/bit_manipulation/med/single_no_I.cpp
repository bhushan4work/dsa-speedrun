// statement- every element in arr appears 2x except for one. Find that single one


//(brute) t.c- O(3n)  s.c- O(maxelement + 1)
int getSingleElement(vector<int> &arr){
    // Find max value in arr
    int maxi = arr[0];
    for (int i = 0; i < arr.size(); i++){
        maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi + 1, 0);
    // Count freq of each no
    for (int i = 0; i < arr.size(); i++){
        hash[arr[i]]++;
    }

    // Find element that occurs exactly once
    for (int i = 0; i < arr.size(); i++){
        if (hash[arr[i]] == 1) return arr[i];
    }

    return -1;
}


//(optimal) t.c- O(n)  s.c- O(1)
int getSingleElement(vector<int> &arr){
    int xorr = 0;

    // XOR all elements. Duplicates cancel out, leaving single element
    for (int i = 0; i < arr.size(); i++){
        xorr = xorr ^ arr[i];
    }
    return xorr;
}