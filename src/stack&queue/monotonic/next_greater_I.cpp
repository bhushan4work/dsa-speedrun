// statement- return next greater element for each element in arr. next greater element for x is 1st element > x that we see while traversing clockwise
// t.c is not O(n^2) as push & pop both happens n times i.e once each in worst case

//(optimal) t.c- O(n + n)  s.c- O(n + n)
vector<int> nextGreater(vector<int> &nums){
    stack<int> st;
    int n = nums.size();
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--){ // Traverse from right to left
        while (!st.empty() && st.top() <= nums[i]){ // Pop all <= elements
            st.pop();
        }

        if (st.empty()) res[i] = -1; // If stack is empty, no greater element exist, so -1
        else res[i] = st.top(); // Else top of stack is ans

        st.push(nums[i]); // Push curr element
    }
    return res;
}



// statement- Find next greater element of each value in nums1 based on its position in nums2; if none exists, return -1

//(optimal) t.c- O(n + m)  s.c- O(n + n)
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2){
    stack<int> st;
    unordered_map<int, int> nge; // value -> next greater

    // Process nums2 & map NGE for each element in map
    for (int i = nums2.size() - 1; i >= 0; i--){
        while (!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }

        nge[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }

    vector<int> ans;
    for (int x : nums1){
        ans.push_back(nge[x]); //finds next greater of arr1 for x from map of arr2
    }

    return ans;
}