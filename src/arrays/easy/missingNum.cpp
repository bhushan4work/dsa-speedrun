//statement- find missingNum betn 1 to n nums in array

int missingNumber(vector<int>&arr, int n) {
    //method1-(brute)  t.c.- O(n*n)  s.c.- O(1)
    for(int i=1;i<=n;i++){ //as we want to check missingNum betn 1 to n
        int flag =0;
        for(int j=0;j<n;j++){
            if(arr[j] == i){ //ex it checks if 1 exists on 0th index of arr
                flag =1;
                break;
            }
        }
        if(flag == 0){
            return i;
        }
    }

    //method2-(better) by hashing  t.c.- O(n+n)= O(2n)  s.c.- O(n) as we form new arr of hash
    hash[n+1] = {0}; //array of size n+1, and initialize ALL elements to 0
    for(int i=0;i<n-1;i++){  //we loop till n-1 as 1 num is missing so the arr size decreases by 1
        hash[arr[i]] = 1; //marks every num in arr as 1 i.e the num exist in the arr
    }
    for(int i=1;i<=n;i++){
        if(hash[i] == 0) return i; //returns num which is not present\hashed in the prev loop
    }

    //method3-(optimal) by sum  t.c.- O(n)  s.c.- O(1)
    int sum = (n * (n+1)) / 2; //here n is not arr.size() , its the total num of elements in arr including missing num
    int sum2 = 0;
    for(int i=0;i<n-1;i++){ //we loop till n-1 as 1 num is missing so the arr size decreases by 1
        sum2 += arr[i];
    }
    return sum-sum2;

    //method4-(optimal) by XOR  t.c.- O(n)  s.c.- O(1)
    //xor- returns true(or 1) when 2 inputs are diff, else false(or 0) when 2 inputs are same
    int xor1 = 0,xor2 = 0;
    for(int i=0;i<N-1;i++){ // we loop till n-1 as 1 num is missing so the arr size decreases by 1
        xor2 = xor2 ^ arr[i]; //XOR of all array elements
        xor1 = xor1 ^ (i+1); //XOR of numbers 1 to n
    }
    xor1 = xor1 ^ N; //adds the missing last number into the XOR calculation as loop runs till N-1 only
    return xor1 ^ xor2;

    //alternative for method4- t.c.- O(2n)  s.c.- O(1)
    int n = arr.size();
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i <= n; i++) xor1 ^= i; //xor1 will store XOR of all numbers from 0 to n
    for (int x : arr) xor2 ^= x;  //xor2 will store XOR of all elements present in the arr
    return xor1 ^ xor2; 
}