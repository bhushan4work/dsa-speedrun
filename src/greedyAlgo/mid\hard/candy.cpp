// statement- rating values are listed in arr assigned to each kid. return the min no of candies needed to distribute among children. kids receive candy acc to criteria:
// 1: There must be at least 1 candy for every child.
// 2: Kids whose scores are higher than their neighbours receive more candies than their neighbours

// (brute) t.c- O(n^2)  s.c- O(n)
int candy(vector<int> &ratings){
    int n = ratings.size();    // Total no of children
    vector<int> candies(n, 1); // arr to keep track of candies given to each child, initialized to 1
    bool updated = true;       // Boolean flag to track if we made any change in curr iteration

    while (updated){ // Repeat until no changes are made in full scan
        updated = false;

        // Left to right pass to check increasing rating condition
        for (int i = 1; i < n; ++i){
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]){
                candies[i] = candies[i - 1] + 1;
                updated = true;
            }
        }

        // Right to left pass to check decreasing rating condition
        for (int i = n - 2; i >= 0; --i){
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]){
                candies[i] = candies[i + 1] + 1;
                updated = true;
            }
        }
    }
    return accumulate(candies.begin(), candies.end(), 0); // Return the total candies
}


// (better) t.c- O(2n)  s.c- O(n)
int candy(vector<int> &ratings){
    int n = ratings.size();
    vector<int> candies(n, 1); // Initialize each child with 1 candy

    // Traverse from left to right
    for (int i = 1; i < n; ++i){
        if (ratings[i] > ratings[i - 1]){ // If curr rating is higher than previous, give more candies
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Traverse from right to left
    for (int i = n - 2; i >= 0; --i){
        if (ratings[i] > ratings[i + 1]){ // If curr rating is higher than next, adjust candy count
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }    
    return accumulate(candies.begin(), candies.end(), 0); // Sum up all candies
}


// (optimal) t.c- O(n)  s.c- O(1)
int candy(vector<int> &ratings){
    int n = ratings.size();
    if (n <= 1) return n;

    int sum = n; // Assign 1 candy to each child initially
    int i = 1;

    while (i < n){
        if (ratings[i] == ratings[i - 1]){ // adjacent ratings are equal, then no extra candies beyond 1
            i++;
            continue;
        }
        
        int peak = 0; // Length of increasing slope
        // Traverse strictly increasing sequence, Each next child gets one more candy than previous
        while (i < n && ratings[i] > ratings[i - 1]){
            peak++;
            sum += peak; // Add extra candies based on slope length
            i++;
        }

        int down = 0; // Length of decreasing slope
        // Traverse strictly decreasing sequence, Ensure higher-rated child gets more candies than next
        while (i < n && ratings[i] < ratings[i - 1]){
            down++;
            sum += down; // Add extra candies for decreasing order
            i++;
        }

        //peak element is counted in both incr & decr slopes, we subtract overlap to avoid double counting
        sum -= min(peak, down);
    }
    return sum; // Return the min total candies required
}