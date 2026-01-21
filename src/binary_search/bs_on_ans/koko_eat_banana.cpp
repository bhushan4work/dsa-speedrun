// statement- find min number of bananas ‘k’ to eat per hour so that koko can eat all the bananas within ‘h’ hours
// piles = [3, 6, 7] means - 1st pile → 3 bananas, 2nd pile → 6 bananas & so on ...
// note: koko doesnt eat one pile per hour she may take multiple hours per pile

// method1(brute) t.c- O( n * max(arr) )  s.c- O(1)  -normal iteration is done i.e bs not used here, (will give TLE error)
int findMax(vector<int> &arr){  //finds max in arr
    int n = arr.size();
    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &arr, int hourly){  //calculates totalH for each pile in arr
    int totalHours = 0;
    for (int pile : arr){
        totalHours += (pile + hourly - 1) / hourly;  //used instead of ceil(a\b) to avoid overflow
    }
    return totalHours;
}
int minEatingSpeed(vector<int> &arr, int h){   //gives final ans for speed of eating bananas\hr
    int maxVal = findMax(arr);

    for (int i = 1; i <= maxVal; i++){  // Try every possible speed
        int hours = calculateTotalHours(arr, i);

        if (hours <= h){ //counted hrs for i <= req hrs
            return i; //if we get our ans we stop the fxn here or return maxVal at the end
        }
    }
    return maxVal; //when counted hrs > req hrs 
}

// method2(optimal) t.c- O( n * log(max(arr) )  s.c- O(1)  -bs used here
int findMax(vector<int> &arr){ //finds max in arr
    int n = arr.size();
    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
long long calculateTotalHours(vector<int> &arr, int hourly){ //calculates totalH for pile passed from arr in this fxn
    int n = arr.size();
    long long totalH = 0;
    for (int i = 0; i < n; i++){
        totalH += (arr[i] + hourly - 1) / hourly; //used instead of ceil(a\b) to avoid overflow
    }
    return totalH;
}
int minEatingSpeed(vector<int> &arr, int h){ //gives final ans for speed of eating bananas\hr
    int low = 1, high = findMax(arr);
    int result = -1; //to store ans
    while (low <= high){
        int mid = low + ((high - low) / 2);
        long long totalH = calculateTotalHours(arr, mid); //runs for every mid & finds totalH for it
        if (totalH <= h){ //counted hrs for mid <= req hrs
            result = mid;  //store the ans
            high = mid - 1; //move left of mid to check if any smaller speed exists
        }
        else{
            low = mid + 1; //move right of mid
        }
    }
    return result;
}