// statement- find smallest possible integer after removing k digits from given string nums
// approach: keep smaller nos at first, remove all the bigger ones
// edgecase: ex-"12345" here we wont be able remove k nos as per our approach but we still need to remove, so in such condn remove last k elements


//(optimal) t.c- O(n)  s.c- O(n)
string removeKdigits(string nums, int k){
    stack<char> st;

    for (int i = 0; i < nums.size(); i++){
        char digit = nums[i]; // curr digit

        // Pop last digits (when possible) if smaller digit is found
        while (!st.empty() && k > 0 && st.top() > digit){
            st.pop(); // Pop last digit
            k--;      // Decrement K by 1
        }
        st.push(digit); // Push curr digit
    }

    // If more digits can be removed
    while (!st.empty() && k > 0){
        st.pop(); // Pop last added digits
        k--;      // Decrement K by 1
    }

    if (st.empty()) return "0"; // Handling edge case

    string res = "";

    // Adding digits in stack to result
    while (!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    // Trimming zeroes at back
    while (res.size() > 0 && res.back() == '0'){
        res.pop_back();
    }

    reverse(res.begin(), res.end()); // Reverse to get actual number

    if (res.empty()) return "0"; // Edge case

    return res;
}