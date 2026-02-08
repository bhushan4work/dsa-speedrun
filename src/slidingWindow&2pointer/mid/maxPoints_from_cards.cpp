// statement- each card in arr has score denoted by its value. Choose k cards. In each step, card can be chosen either all from beginning
//             or all from end or mix of both .ans is maxSum of scores of chosen cards

// method1(optimal) t.c- O(2k)  s.c- O(1)
int maxScore(vector<int> &arr, int k){
    int n = arr.size();
    int lSum = 0, rSum = 0;
    int ans = 0; // stores max current sum from lSum+rSum

    for (int i = 0; i < k; i++){
        lSum += arr[i]; // take sum of 1st k elements
        ans = max(ans, lSum + rSum);
    }

    int rInd = n - 1; // pointer to add elements from righmost side
    for (int i = k - 1; i >= 0; i--){
        lSum -= arr[i];    // remove 1 element from end of leftmost side
        rSum += arr[rInd]; //& add 1 element from rightmost side
        ans = max(ans, lSum + rSum);
        rInd--;
    }
    return ans;
}