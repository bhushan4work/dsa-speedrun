// statement- arr[i] represents stock price on day i. Calculate span of stock prices for each day.
//            span Sᵢ for day i is defined as max no of consecu prev days (including curr day) for which stock price was <= price on day i


//(brute) t.c- O(n^2)  s.c- O(n)
vector<int> v; // stores all previous prices

StockSpanner(){
    // nothing needed here
}

int next(int price){
    int span = 1; // span always includes current day

    for (int i = v.size() - 1; i >= 0; i--){ // Traverse previous prices backwards
        if (price >= v[i]){
            span++; // extend span if condition satisfied
        }
        else{
            break; // stop when greater price is found
        }
    }
    v.push_back(price); // store curr price for future calls

    return span;
}


//(optimal) - using PGE t.c- O(n)  s.c- O(n)
vector<int> findPGE(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n); // To store prev greater element
    stack<int> st;
    
    for (int i = 0; i < n; i++){
        int currEle = arr[i];
        
        // Pop elements in stack until stack is not empty & top element is not greater element
        while (!st.empty() && arr[st.top()] <= currEle){
            st.pop();
        }
        
        if (st.empty()) ans[i] = -1; // If greater element is not found, stack will be empty
        else ans[i] = st.top(); // Else store ans
        
        st.push(i); // Push curr index in stack
    }
    return ans;
}
vector<int> stockSpan(vector<int> arr){
    int n = arr.size();
    vector<int> PGE = findPGE(arr); // Get indices of prev greater elements
    vector<int> ans(n);
    
    // Compute result
    for (int i = 0; i < n; i++){
        ans[i] = i - PGE[i];
    }
    return ans;
}



//(optimal) t.c- O(n)  s.c- O(n)
stack<pair<int, int>> st; // stack stores {price, span}

StockSpanner(){
    // no initialization needed
}

int next(int price){
    int span = 1; // curr day always counts

    // Pop all smaller or equal prices & accumulate their spans
    while (!st.empty() && st.top().first <= price){
        span += st.top().second;
        st.pop();
    }
    st.push({price, span}); // Push curr price with its computed span

    return span;
}