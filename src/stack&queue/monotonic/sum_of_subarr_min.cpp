// statement- calculate sum of min value in each (contiguous) subarr of arr. Since result may be large, return ans modulo 10⁹ +7


//(brute) t.c- O(n^2)  s.c- O(1)
int sumSubarrayMins(vector<int> &arr){
    int n = arr.size();
    int mod = 1e9 + 7; // Mod value
    int sum = 0;

    for (int i = 0; i < n; i++){
        int mini = arr[i]; // To store min of subarr

        for (int j = i; j < n; j++){
            mini = min(mini, arr[j]); // Update min value
            sum = (sum + mini) % mod; // Update sum
        }
    }
    return sum;
}


//(optimal) t.c- O(n)  s.c- O(n)
vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--){ // Start traversing from the back
        int currEle = arr[i];

        // Pop elements until stack is not empty & top element is not the smaller element
        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n; // Update ans

        st.push(i); // Push index of curr element in stack
    }
    return ans;
}

// Fxn to find indices of previous smaller or equal elements
vector<int> findPSEE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++){
        int currEle = arr[i];

        // Pop elements until stack is not empty & top elements are greater than curr element
        while (!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1; // Update ans

        st.push(i); // Push index of curr element in stack
    }
    return ans;
}

// Fxn to find sum of min value in each subarr
int sumSubarrayMins(vector<int> &arr){
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);
    int n = arr.size();
    int mod = 1e9 + 7; // Mod value
    int sum = 0;

    for (int i = 0; i < n; i++){
        int left = i - psee[i]; // Count of 1st type of subarr
        int right = nse[i] - i; // Count of 2nd type of subarr

        long long freq = left * right * 1LL; // Count of subarr where curr element is min

        int val = (freq * arr[i] * 1LL) % mod; // Contribution due to curr element

        sum = (sum + val) % mod; // Updating sum
    }
    return sum;
}
