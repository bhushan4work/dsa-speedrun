// statement- Given an arr of non-negative integers, height representing elevation of ground. Calculate amt of water that can be trapped after rain


// (brute) t.c- O(n ^ 2)  s.c- O(1)
int trap(vector<int>& height) { // Calculates trapped water by checking both sides of each bar.
    int n = height.size();
    if (n < 3) { // At least three bars are required to trap water.
        return 0;
    }
    int totalWater = 0;
    for (int i = 0; i < n; i++) { // Treat each index as a possible position for water.
        int leftMax = 0;
        int rightMax = 0;
        for (int j = 0; j <= i; j++) { // Find the tallest boundary from the left up to i.
            leftMax = max(leftMax, height[j]);
        }
        for (int j = i; j < n; j++) { // Find the tallest boundary from i to the right end.
            rightMax = max(rightMax, height[j]);
        }
        int waterLevel = min(leftMax, rightMax);
        totalWater += waterLevel - height[i]; // The space above the bar contributes trapped water.
    }
    return totalWater;
}



// (better) t.c- O(n)  s.c- O(n)
int trap(vector<int>& height) { // Uses prefix and suffix maximum boundaries for each bar.
    int n = height.size();
    if (n < 3) { // At least three bars are required to trap water.
        return 0;
    }
    vector<int> leftMax(n);
    vector<int> rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) { // Build the tallest boundary seen from the left side.
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) { // Build the tallest boundary seen from the right side.
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    int totalWater = 0;
    for (int i = 0; i < n; i++) { // Use both boundaries to calculate water at each bar.
        int waterLevel = min(leftMax[i], rightMax[i]);
        totalWater += waterLevel - height[i];
    }
    return totalWater;
}



// (optimal) t.c- O(n)  s.c- O(1)
int trap(vector<int>& height) { // Uses two pointers and keeps only the required boundaries.
    int n = height.size();
    if (n < 3) { // At least three bars are required to trap water.
        return 0;
    }
    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int totalWater = 0;
    while (left < right) { // Process the side with the smaller current boundary.
        if (height[left] < height[right]) { // The left side can be decided using leftMax.
            if (height[left] >= leftMax) { // Update the left boundary when a taller bar appears.
                leftMax = height[left];
            } else { // Otherwise, the gap above this bar stores water.
                totalWater += leftMax - height[left];
            }
            left++;
        } else { // The right side can be decided using rightMax.
            if (height[right] >= rightMax) { // Update the right boundary when a taller bar appears.
                rightMax = height[right];
            } else { // Otherwise, the gap above this bar stores water.
                totalWater += rightMax - height[right];
            }
            right--;
        }
    }
    return totalWater;
}
