// statement- find out least-weight capacity so that you can ship all the packages within 'd' days. ith day consists of arr[i] wt
// search range - [maxWt of arr to sum of all wt's]

// method1(brute) t.c- O((sumOfWt-maxWt)* n) s.c- O(1)  -normal iteration is done i.e bs not used here
int findDays(vector<int> &arr, int capacity){
    int days = 1;
    int currentLoad = 0;

    for (int i = 0; i < arr.size(); i++){
        // Check if adding current package exceeds capacity for the day
        if (arr[i] + currentLoad > capacity){
            days++; // Increase day count and reset load with new day
            currentLoad = arr[i];
        }
        else{
            currentLoad += arr[i]; //else add current package wt to the day's load
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int d){
    int low = *max_element(weights.begin(), weights.end());  //finds max in arr
    int high = accumulate(weights.begin(), weights.end(), 0);  //calculates sum of arr

    for (int capacity = low; capacity <= high; capacity++){
        int noOfDays = findDays(weights, capacity);

        if (noOfDays <= d){
            return capacity;
        }
    }
    return high;
}


// method2(optimal) t.c- O(log(sumOfWt-maxWt)* n)  s.c- O(1)  -bs used here
int findDays(vector<int> &arr, int capacity){
    int days = 1;
    int currentLoad = 0; // tracks currentLoad for a day

    for (int i = 0; i < arr.size(); i++){
        if (arr[i] + currentLoad > capacity){
            days++;
            currentLoad = arr[i]; // Increase day count and reset load with new day
        }
        else{
            currentLoad += arr[i];  //else add current package wt to that day's load
        }
    }
    return days;
}
int shipWithinDays(vector<int> &arr, int d){
    int low = *max_element(arr.begin(), arr.end());   // finds max in arr
    int high = accumulate(arr.begin(), arr.end(), 0); // Calculates sum of all wt's
    int ans;
    while (low < high){
        int mid = low + ((high - low) / 2);
        // Calculate how many days needed when ship cap is mid
        int noOfDays = findDays(arr, mid);

        if (noOfDays <= d){
            ans = mid;
            high = mid - 1; // decr capacity by moving right
        }
        else{
            low = mid + 1; // increase capacity by moving left
        }
    }
    return ans;
}
