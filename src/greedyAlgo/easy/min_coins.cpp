// statement- given infinite supply of indian currency {1,2,5,10} & target val n. Find min no of coins needed to make val n 


// (optimal) t.c- O(4)  s.c- O(1)
int minCoins(int n){
    int coins[] = {10, 5, 2, 1}; // coins taken in descending order
    int count = 0;

    for (int i = 0; i < 4; i++){
        if (n >= coins[i]){
            count += n / coins[i]; // take max possible coins
            n = n % coins[i];      // reduce amt
        }
    }
    return count;
}