// statement- arr represents boards & each element of arr represents length of each board. ‘K’ no of painters are available to paint these boards.
//            each unit of board takes 1 unit of time to paint. return area of min time to paint all n boards


// method1(brute) t.c- O(n * (sum(arr) - max(arr)+1))  s.c- O(1)  -normal iteration is done i.e bs not used here
int countPainters(vector<int> &arr, int time){
    int painters = 1;
    long long currSumOfTime = 0;

    for (int i = 0; i < arr.size(); i++){
        if (currSumOfTime + arr[i] <= time){
            currSumOfTime += arr[i]; // adds prevTime to curr board time
        }
        else{
            painters++;
            currSumOfTime = arr[i]; // starts new timeSum from next board
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &arr, int k){
    int low = *max_element(arr.begin(), arr.end());   // gives max of arr
    int high = accumulate(arr.begin(), arr.end(), 0);  // gives sum of arr

    int ans = -1;

    while (low <= high){
        int mid = (low + high) / 2;
        if (countPainters(arr, mid) <= k){
            ans = mid;
            high = mid - 1; // move left to find min time to get k painters
        }
        else{
            low = mid + 1; // else move right
        }
    }
    return ans;
}


// method2(optimal) t.c- O( n * log(sum(arr) - max(arr)+1) )  s.c- O(1)  -bs used here
int countPainters(vector<int> &arr, int time){
    long long currSumOfTime = 0;
    int painters = 1;

    for (int i = 0; i < arr.size(); i++){
        if (currSumOfTime + arr[i] <= time){
            currSumOfTime += arr[i]; // adds prevTime to curr board time
        }
        else{
            painters++;
            currSumOfTime = arr[i]; // starts new timeSum from next board
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &arr, int k){
    int ans = -1;
    int low = *max_element(arr.begin(), arr.end());    // gives max of arr
    long long high = accumulate(arr.begin(), arr.end(), 0LL);  // gives sum of arr

    while (low <= high){
        long long mid = low + ((high - low) / 2);

        if (countPainters(arr, mid) <= k){
            ans = mid;
            high = mid - 1; // move left to find min time to get k painters
        }
        else{
            low = mid + 1; // else move right
        }
    }
    return ans;
}