// statement- given an arr where 'arr[i]' denotes that 'ith' rose will bloom on 'arr[i]th' day. Find min no of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if not possible
// note:  You can only pick already bloomed roses that are adjacent to make a bouquet

// method1(brute) t.c- O( (max(arr)-min(arr)) * n )  s.c- O(1)  -normal iteration is done i.e bs not used here, give TLE

//  checks if we can form 'm' bouquets by 'day'
bool possible(vector<int> &arr, int day, int m, int k){
    int n = arr.size();
    int cnt = 0;   // Counter for consecutive bloomed flowers
    int noOfB = 0; // Count of bouquets made

    for (int i = 0; i < n; i++){
        if (arr[i] <= day){  //day is mid of a range here
            cnt++;   // Flower bloomed, increment consecutive count
            if(cnt == k){ //we got req flowers for a bouq
                noOfB++;
                cnt = 0; //reset cnt to avoid adding same flowers again
            }
        }
        else{
            cnt = 0;  // resets cnt
        }
    }
    return noOfB >= m; //returns true if req noOfB is found
}
//finds the min day to form 'm' bouquets
int minDaysToMakeBouquets(vector<int> &bloomDays, int m, int k){
    long long totalFlowers = 1LL * m * k;
    if (totalFlowers > bloomDays.size()) return -1; // Not enough flowers

    int mini = *min_element(bloomDays.begin(), bloomDays.end());
    int maxi = *max_element(bloomDays.begin(), bloomDays.end());

    for (int day = mini; day <= maxi; ++day){
        if (isPossible(bloomDays, day, m, k)){
            return day;
        }
    }
    return -1; // Not possible to make bouquets
}


// method2(optimal) t.c- O( log(max(arr)-min(arr)) * n )  s.c- O(1)  -bs used here

// check if it's possible to make m bouquets on or before a given day
bool possible(vector<int> &arr, int day, int m, int k){
    int n = arr.size();
    int cnt = 0;   // Counter for consecutive bloomed flowers
    int noOfB = 0; // Count of bouquets made

    for (int i = 0; i < n; i++){
        if (arr[i] <= day){  //day is mid of a range here
            cnt++;   // Flower bloomed, increment consecutive count
            if(cnt == k){ //we got req flowers for a bouq
                noOfB++;
                cnt = 0; //reset cnt to avoid adding it again
            }
        }
        else{
            cnt = 0;  // resets cnt
        }
    }
    return noOfB >= m; //returns true if req noOfB is found
}
// finds the min day to make m bouquets
int roseGarden(vector<int> &arr, int m, int k){
    long long totalF = 1LL * k * m; // Total flowers req, converted to long long to avoid overflow

    if (totalF > arr.size()) return -1; //req Flowers > available then not possible 
    
    int mini = *min_element(arr.begin(), arr.end());  // Finds min bloom days from arr
    int maxi = *max_element(arr.begin(), arr.end());  // Finds max bloom days from arr

    int low = mini, high = maxi;
    int result = -1; //for storing ans

    while (low <= high){
        int mid = (low + high) / 2;

        if (possible(arr, mid, m, k)){ //when req noOfB is found do this
            result = mid; //store ans
            high = mid - 1;  //move left of mid to find if an earlier day exists
        }
        else{
            low = mid + 1; //else move to right of mid
        }
    }
    return result;
}