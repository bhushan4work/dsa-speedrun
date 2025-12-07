//Find the number that appear once,where other numbers appear twice

int singleNumber(vector<int>& arr) {
    //method1-(brute)  t.c.- O(n^2) s.c.- O(1)
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // current element to check
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num) 
                cnt++;  // Counts occurrences of this element
        }
        if (cnt == 1) return num;   // If it occurs only once, return it
    }
    return -1;

    //method2-(better)  t.c.- O(n+n+n)  s.c.- O(maxelement+1)
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]); // Finds the max value in the arr
    }

    vector<int> hash(maxi + 1, 0); //creates new arr of size 'maxi + 1' where all values are set to 0
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;  //Counts the frequency of each num
    }
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1){  //Finds the element that occurs exactly once
            return arr[i];
        }        
    }
    return -1;

    //method3-(optimal)  t.c.- O(n) s.c.- O(1)
    //xor- returns true(or 1) when 2 inputs are diff, else false(or 0) when 2 inputs are same
    int n = arr.size();
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];  // XOR all elements. Duplicates cancel out, leaving the single element.
    }
    return xorr;
}