//statement- find the subarray with the largest sum and return the sum of the elements present in that subarray.

//method1(brute)  t.c- O(n^3)  s.c- O(1)
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN; // Initialize maxSum with smallest possible int
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0; // stores the sum of the current subarray
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// method2(better)  t.c- O(n^2)   s.c- O(1)
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN; // Initialize maxSum with smallest possible int
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0; // stores the sum of the current subarray
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// method3(optimal) using Kadane's algo  t.c- O(n)  s.c- O(1)

// type1- finding max subarray sum
int maxSubArray(vector<int> &nums){
    long long maxi = LLONG_MIN;
    long long sum = 0; // stores the sum of the current subarray

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > maxi)
        { // Update maxi if current sum is greater
            maxi = sum;
        }

        if (sum < 0)
        { // Reset sum to 0 if it becomes negative
            sum = 0;
        }
    }
    return maxi;
}

// type2- finding max subarray
int maxSubArray(vector<int> &nums){
    long long maxi = LLONG_MIN;
    long long sum = 0;
    int start = 0;   // starting index of current subarray
    int ansStart = -1, ansEnd = -1; // indices of the maximum sum subarray

    for (int i = 0; i < nums.size(); i++){
        if (sum == 0){
            start = i;  // update starting index if sum is zero
        }

        sum += nums[i];

        if (sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0){  // Reset sum to 0 if it becomes negative
            sum = 0;
        }
    }

    for (int i = ansStart; i <= ansEnd; i++){ // Printing the subarray
        cout << nums[i] << " ";
    }
}
