// statement- Given arr & an integer k, return the total number of subarrays whose sum equals k

//method1(brute) t.c- O(n^3)  s.c- O(1)
int subarraySum(vector<int> &arr, int k){
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int sum = 0;
            for (int m = i; m <= j; m++){ // Calculate sum of subarray from i to j
                sum += arr[m];
            }
            if (sum == k){
                count++;
            }
        }
    }
    return count;
}

//method2(better) t.c- O(n^2)  s.c- O(1)
int subarraySum(vector<int> &arr, int k){
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += arr[j]; // Add current element to sum
            if (sum == k){
                count++;
            }
        }
    }
    return count;
}

//method3(optimal) t.c- O(n)  s.c- O(n)
int subarraySum(vector<int> &arr, int k){
    int n = arr.size();
    unordered_map<int, int> prefixSumCount;  // Map to store frequency of prefix sums
    int prefixSum = 0;
    int count = 0;

    prefixSumCount[0] = 1;   // Base case: prefix sum 0 has occurred once

    for (int i = 0; i < n; i++){
        prefixSum += arr[i];  // Add current element to prefix sum

        int remove = prefixSum - k;  // Calculate the prefix sum that needs to be removed

        // If this prefix sum has been seen before,
        // add its count to the result
        if (prefixSumCount.find(remove) != prefixSumCount.end()){
            count += prefixSumCount[remove];
        }
        prefixSumCount[prefixSum]++;  // Update the frequency of the current prefix sum
    }
    return count;
}
