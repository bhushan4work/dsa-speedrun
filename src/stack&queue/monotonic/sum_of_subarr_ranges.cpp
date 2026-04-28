// statement- determine range of subarr, defined as diff betw largest & smallest elements within subarr. Calculate & return sum of all subarr ranges of nums


//(brute) t.c- O(n^2)  s.c- O(1)
long long subarrRanges(vector<int> &arr){
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++){
        int smallest = arr[i]; // To store smallest value of subarr
        int largest = arr[i]; // To store largest value of subarr

        for (int j = i; j < n; j++){
            smallest = min(smallest, arr[j]); // Update smallest value
            largest = max(largest, arr[j]); // Update largest value

            sum += (largest - smallest); // Update sum
        }
    }
    return sum;
}


//(optimal) t.c- O(n)  s.c- O(n)
vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--){ // Start traversing from back
        int currEle = arr[i]; // Get curr element

        // Pop elements in stack until stack is not empty & top element is not smaller element
        while (!st.empty() && arr[st.top()] >= currEle){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n; // Update ans

        st.push(i); // Push index of curr element in stack
    }
    return ans;
}

// Function to find indices of next greater elements
vector<int> findNGE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--){ // Start traversing from back
        int currEle = arr[i]; // Get curr element

        // Pop elements in stack until stack is not empty & top element is not greater element
        while (!st.empty() && arr[st.top()] <= currEle){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n; // Update ans

        st.push(i); // Push index of curr element in stack
    }
    return ans;
}

// Function to find indices of previous smaller or equal elements
vector<int> findPSEE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++){
        int currEle = arr[i];

        // Pop elements in stack until stack is not empty & top elements are greater than curr element
        while (!st.empty() && arr[st.top()] > currEle){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1; // Update ans

        st.push(i); // Push index of curr element in stack
    }
    return ans;
}

// Function to find indices of previous greater or equal elements
vector<int> findPGEE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++){
        int currEle = arr[i]; // Get curr element

        // Pop elements in stack until stack is not empty & top elements are smaller than curr element
        while (!st.empty() && arr[st.top()] < currEle){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1; // Update ans

        st.push(i); // Push index of curr element in stack
    }
    return ans;
}

// Function to find sum of min value in each subarr
long long sumsubarrMins(vector<int> &arr){
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++){
        int left = i - psee[i]; // Count of first type of subarrs
        int right = nse[i] - i; // Count of second type of subarrs

        long long freq = left * right * 1LL; // Count of subarrs where curr element is min
        long long val = (freq * arr[i] * 1LL); // Contribution due to curr element

        sum += val; // Updating sum
    }
    return sum;
}

// Function to find sum of max value in each subarr
long long sumsubarrMaxs(vector<int> &arr){
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++){
        int left = i - pgee[i]; // Count of first type of subarrs
        int right = nge[i] - i; // Count of second type of subarrs

        long long freq = left * right * 1LL; // Count of subarrs where curr element is min
        long long val = (freq * arr[i] * 1LL); // Contribution due to curr element

        sum += val; // Updating sum
    }
    return sum;
}

// Function to find sum of subarr ranges in each subarr
long long subarrRanges(vector<int> &arr){
    return (sumsubarrMaxs(arr) - sumsubarrMins(arr));
}