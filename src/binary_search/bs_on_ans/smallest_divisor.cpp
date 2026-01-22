// statement- find smallest +ve divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is <= given limit value

// method1(brute) t.c- O( max(arr) * n)  s.c- O(1)  -normal iteration is done i.e bs not used here
int smallestDivisor(vector<int> &arr, int limit){
    int maxi = *max_element(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 1; i <= maxi; i++){ //divisors
        int sum = 0; // resets sum to check for next divisor
        for (int j = 0; j < n; j++){ 
            sum += (arr[j] + i - 1) / i; // ceil val is taken
        }
        if (sum <= limit){
            return i;
        }
    }
    return -1;
}

// method2(optimal) t.c- O( log(max(arr)) * n)  s.c- O(1)  -bs used here
int sum(vector<int> &arr, int div){
    int sum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++){
        sum += (arr[i] + div - 1) / div; // ceil val is taken
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int limit){
    int ans;
    int maxi = *max_element(arr.begin(), arr.end());
    int low = 1, high = maxi;

    while (low <= high){
        int mid = low + ((high - low) / 2);  //divisor

        if (sum(arr, mid) <= limit){
            ans = mid; // store ans
            high = mid - 1; // move left to find more smaller divisor if exists
        }
        else{
            low = mid + 1; // else move right
        }
    }
    return ans;
}