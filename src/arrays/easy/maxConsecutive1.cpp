//find the max times '1' occur in an arr consecutively
int findMaxConsecutiveOnes(vector<int>& nums) {
    //t.c- O(n)
    int maxOnes = 0; //keeps track of max consecutive 1's
    int count = 0; //counter for max consecutive 1's
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++; 
        }
        else{
            count = 0; //resets to 0 if consecutive 1's not found
        }
        maxOnes = max(maxOnes, count); //updates max consecutive 1's in arr
    }
    return maxOnes; 
}
