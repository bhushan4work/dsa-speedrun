// statement- celebrity is person who is known by everyone else at party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j,
//            and 0 otherwise, determine if there is a celebrity at party. Return index of celebrity or -1 if no such person exists. Note that M[i][i] is always 0.


// (brute) t.c- O(n ^ 2)  s.c- O(n)
int celebrityBrute(vector<vector<int>>& mat) {
    int n = mat.size(); // Get the total number of people
    vector<int> in(n, 0), out(n, 0); // Arrays to track incoming and outgoing acquaintances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) { // Check if person i knows person j
                in[j]++; // Increment count of people who know person j
                out[i]++; // Increment count of people person i knows
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (in[i] == n - 1 && out[i] == 0) { // Celebrity is known by everyone else but knows nobody
            return i;
        }
    }
    return -1; // Return -1 if no such person exists
}



// (optimal) t.c- O(n)  s.c- O(1)
int celebrityOptimal(vector<vector<int>>& mat) {
    int n = mat.size(); // Get the total number of people
    int top = 0, down = n - 1; // Use two pointers for elimination
    while (top < down) {
        if (mat[top][down] == 1) { // If top knows down, top is definitively not a celebrity
            top++;
        } else { // If top doesn't know down, down is definitively not a celebrity
            down--;
        }
    }
    int candidate = top; // only remaining person is our potential celebrity candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) { // Verify candidate against all others
                return -1;
            }
        }
    }
    return candidate; // Return confirmed celebrity index
}