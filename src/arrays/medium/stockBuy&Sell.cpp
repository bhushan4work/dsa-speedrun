// stock buy & sell - You want to maximize your profit by choosing a single day to buy 1 stock and choosing a different day in the future to sell that stock.
//                    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// this problem comes under dynamic programming as it remembers the past

// method1(brute)-  t.c- O(n^2) s.c- O(1)
int maxProfit(vector<int> &prices){
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++){
        for (int j = i + 1; j < prices.size(); j++){ 
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

// method2(optimal)-  t.c- O(n) s.c- O(1)
int maxProfit(vector<int> &prices){
    int mini = prices[0];  //assume 1st element as minimum
    int maxProfit = 0;
    for(int i=1;i<prices.size();i++){
        int cost = prices[i] - mini;  //we find cost at each element & keep updating the profit
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
