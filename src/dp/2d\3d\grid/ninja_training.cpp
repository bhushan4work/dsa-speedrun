//statement- Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any 1 of these three activities. (Running, Fighting Practice or Learning New Moves). 
//           Each activity has some merit points on each day. As he has to improve all his skills, he can’t do same activity in 2 consecutive days. Can you help him find out max merit points he can earn?
//           given 2D arr of size N*3 ‘POINTS’ with points corresponding to each day & activity. task is to calculate max no of merit points that Ninja can earn.


// (optimal) -memoization t.c- O(n * 4 * 3)  s.c- O(n * 4)
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (dp[day][last] != -1) { // If result for this day and last activity is already calculated, return it
        return dp[day][last];
    }

    if (day == 0) { // Base case: When we reach the first day (day == 0)
        int maxi = 0;
        for (int i = 0; i <= 2; i++) { // Calculate max points for first day by choosing an activity different from last one
            if (i != last) {
                maxi = max(maxi, points[0][i]);
            }
        }

        return dp[day][last] = maxi; // Store result in dp array and return it
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) { // Iterate through activities for curr day
        if (i != last) {
            int activity = points[day][i] + f(day - 1, i, points, dp); // Calculate points for curr activity and add it to max points obtained so far (recursively calculated)
            maxi = max(maxi, activity);
        }
    }

    return dp[day][last] = maxi; // Store result in dp array and return it
}

int ninjaTraining(int n, vector<vector<int>> &points) { // Function to find max points for ninja training
    vector<vector<int>> dp(n, vector<int>(4, -1)); // Create memoization table (dp) to store intermediate results

    return f(n - 1, 3, points, dp); // Start recursive calculation from last day with no prev activity
}



// (optimal) -tabulation t.c- O(n * 4 * 3)  s.c- O(n * 4)
int ninjaTraining(int n, vector<vector<int>>& points) {
  vector<vector<int>> dp(n, vector<int>(4, 0)); // Create 2D DP table: dp[i][j] represents max points at day i with last activity j

  dp[0][0] = max(points[0][1], points[0][2]); // Initialize DP table for first day (day 0)
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); // Max points for day 0 considering any activity

  for (int day = 1; day < n; day++) { // Iterate through days starting from day 1
    for (int last = 0; last < 4; last++) { // Check all possible "last activities" (0, 1, 2, or no prev activity 3)
      dp[day][last] = 0; // Initialize dp[day][last] to 0

      for (int task = 0; task <= 2; task++) { // Iterate through tasks (activities) for curr day

        if (task != last) { // If curr task is different from last task, we can perform this task
          int activity = points[day][task] + dp[day - 1][task]; // Calculate curr activity points + max points on prev day
          dp[day][last] = max(dp[day][last], activity); // Update maximum points for curr day and last activity
        }
      }
    }
  }

  return dp[n - 1][3]; // max points for last day with any activity can be found in dp[n-1][3]
}