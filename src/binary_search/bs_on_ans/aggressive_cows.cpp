// statement- arr denotes position of stalls. 'k' denotes no of aggressive cows. assign stalls to 'k' cows such that the min distance betn any 2 of them is the max possible
//            find the max possible min distance

// method1(brute) t.c- O( nlogn + (n * arr(max-min) )  s.c- O(1)  -normal iteration is done i.e bs not used here
bool canPlace(vector<int> &arr, int cows, int d){
    int count = 1;
    int lastPos = arr[0]; // Place the first cow at the first stall

    for (int i = 1; i < arr.size(); i++){
        // If current stall is at least 'd' dist away from last cow
        if (arr[i] - lastPos >= d){
            count++;   
            lastPos = arr[i]; // Place a cow here
        }
        if (count >= cows) return true;
    }
    return false;  // Not possible to place all cows
}
int aggressiveCows(vector<int> &stalls, int cows){
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int maxDist = arr[n - 1] - arr[0]; // Get the max possible dist
    int ans = 0;

    for (int d = 1; d <= maxDist; d++){
        // If cows can be placed with distance d
        if (canPlace(arr, cows, d)){
            ans = d;
        }
    }
    return ans;
}


// method2(optimal) t.c- O( nlogn + (n * log(arr(max-min))) )  s.c- O(1)  -bs used here
bool canPlace(vector<int> &arr, int cows, int d){
    int count = 1;
    int lastPos = arr[0];  // Place first cow at the first stall

    for (int i = 1; i < arr.size(); i++){
        // Check if this stall is at least 'd' away from last placed cow
        if (arr[i] - lastPos >= d){
            count++;
            lastPos = arr[i];  // Update last placed cow position
        }
        if (count >= cows) return true; // If all cows placed, return true
    }
    return false; // Not possible to place all cows
}
int aggressiveCows(vector<int> &arr, int cows){
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int low = 1, high = arr[n-1] - arr[0];
    int ans = 0;

    while (low <= high){
        int mid = low + (high - low) / 2;

        // If placing cows is possible with mid distance
        if (canPlace(arr, cows, mid)){
            ans = mid;
            low = mid + 1; // move right to find larger min dist
        }
        else{
            high = mid - 1; // else move left
        }
    }
    return ans;
}