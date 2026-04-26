// statement- given circular arr,return next greater element for each element in arr. next greater element for x is 1st element > x that we see while traversing clockwise
// monotonic means storing element in some order, here we store element in decr order


//here we double given arr by iterating from 2n-1 & we index it with i%n to check backward elements of ith element, rest logic same as NGE_I
//(optimal) t.c- O(n + n)  s.c- O(n + n)
vector<int> nextGreaterElements(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n); // To store next greater elements
    stack<int> st;

    for (int i = (2*n) - 1; i >= 0; i--){ // Start traversing from back
        int ind = i % n; // Get the actual index of circular arr
        int currEle = arr[ind]; // Get the current element

        // Pop elements in stack until stack is not empty & the top element is not greater element
        while (!st.empty() && st.top() <= currEle){
            st.pop();
        }

        // Store answer for second half
        if (i < n){
            if (st.empty()) ans[i] = -1; // If greater element is not found, stack will be empty
            else ans[i] = st.top(); // Else store ans
        }
        st.push(currEle); // Push curr element in stack maintaining the decr order
    }
    return ans;
}