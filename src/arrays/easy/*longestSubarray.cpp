//statement- Find length of longest subarray in which sum of elements is equal to ‘K’. → 2 subquestion - one with arr having both +ves -ves & other with only +ves

int getLongestSubarray(vector<int>& arr, int k){
    //method1(brute)- t.c.- O(n^2)  s.c- O(1) for both (only +ves & -ves +ves arr) but may give a tle error
    int length = 0;
    for(int i=0;i<arr.size();i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum += arr[j]; 
            if(sum == k){ 
                length = max(length,j-i+1); //j-i+1 gives length of subarr
            }            
        }
    }
    return length;

    //method2 (hashing) is better soln for arr(having +ves) & optimal soln for arr(having +ves & -ves) t.c -O(nlogn) s.c. -O(n)
    map<long long,int> preSumMap;
    long long sum =0;
    int maxLen = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        long long remain = sum - k ;
        if(preSumMap.find(remain) != preSumMap.end()){
            int len = i - preSumMap[remain];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;

    //method3(optimal) 2 pointer - for arr(having +ves) t.c- O(2n)  s.c- O(1)
    //here t.c is not O(n^2) as the inner loop doesnt run for n times each iteration, it runs for O(n) overall
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    while(right < arr.size()){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;  
        }
        if(sum == k){
            maxLen = max(maxLen,right - left + 1);
        }
        right++;
        if(right < arr.size()) sum += arr[right]; 
    }
    return maxLen;

}