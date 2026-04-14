// statement- return all binary str of length n that dont contain consecutive 1s


// (brute) -using recursion t.c- O(2^n)  s.c- O(1) -gives tle, can be solved optimally with dp
void solve(int n, string &curr, vector<string> &ans){
    if (curr.size() == n){ // base case
        ans.push_back(curr);
        return;
    }

    // choose '0'
    curr.push_back('0');
    solve(n, curr, ans);
    curr.pop_back();

    // choose '1' (only if last is not '1')
    if (curr.empty() || curr.back() != '1'){
        curr.push_back('1');
        solve(n, curr, ans);
        curr.pop_back();
    }
}

vector<string> generateBinaryStrings(int n){
    vector<string> ans; //stores valid binary str
    string curr = ""; 
    solve(n, curr, ans);
    return ans;
}