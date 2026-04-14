// statement- arr represents max no of steps you can jump forward from that element, return true if we can reach last index starting from the first index. Otherwise, return false

// (optimal) t.c- O(n)  s.c- O(1)
bool canJump(vector<int> &nums){
    int maxIndex = 0; //farthest index we are aloud to reach\move 

    for (int i = 0; i < nums.size(); i++){
        if (i > maxIndex){ // if current index is beyond aloud reachable point
            return false; // means we cannot move further
        }
        maxIndex = max(maxIndex, i + nums[i]); // Update farthest index we are aloud to move to
    }
    return true; // If we finish the loop, we can reach last index
}