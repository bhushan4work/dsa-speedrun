// statement(works for lc 1106)- given a valid boolean expression containing 't', 'f', '!', '&', '|', parentheses and commas.
//           evaluate the expression and return its boolean result.


// (optimal) -using stack t.c- O(n) s.c- O(n)
bool parseBoolExpr(string expression) {
    stack<char> st;

    for (char currChar : expression) {
        if (currChar == ',' || currChar == '(')
            continue;

        if (currChar == 't' || currChar == 'f' || currChar == '!' ||
            currChar == '&' || currChar == '|') {
            st.push(currChar);
        }
        else if (currChar == ')') {
            bool hasTrue = false, hasFalse = false;

            while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                char topValue = st.top();
                st.pop();

                if (topValue == 't') hasTrue = true;
                if (topValue == 'f') hasFalse = true;
            }

            char op = st.top();
            st.pop();

            if (op == '!') {
                st.push(hasTrue ? 'f' : 't');
            }
            else if (op == '&') {
                st.push(hasFalse ? 'f' : 't');
            }
            else {
                st.push(hasTrue ? 't' : 'f');
            }
        }
    }

    return st.top() == 't';
}



//statement- given string expr consisting of chars: T, F, &, |, ^(XOR). expr is guaranteed to follow pattern "operand operator operand operator .... operand" 
//           (i.e. it always starts and ends with operand and no 2 operator are adj). Return no of distinct ways to fully parenthesize expr such that whole expr evaluates to true.
//           Because ans can be very large, return it modulo 109+7


// (optimal) -memoization t.c- O(n ^ 3) s.c- O(n ^ 2 + n)
const int mod = 1e9 + 7;

long long f(int i, int j, int isTrue, string &exp,
            vector<vector<vector<long long>>> &dp) {
    if (i > j) return 0;                                  // invalid partition

    if (i == j) {                                         // single operand
        if (isTrue) return exp[i] == 'T';                 // want true
        return exp[i] == 'F';                             // want false
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];  // memoized result

    long long ways = 0;

    for (int ind = i + 1; ind <= j - 1; ind += 2) {       // try each operator
        long long lT = f(i, ind - 1, 1, exp, dp);         // left evaluates true
        long long lF = f(i, ind - 1, 0, exp, dp);         // left evaluates false
        long long rT = f(ind + 1, j, 1, exp, dp);        // right evaluates true
        long long rF = f(ind + 1, j, 0, exp, dp);        // right evaluates false

        if (exp[ind] == '&') {                            // AND operator
            if (isTrue)
                ways = (ways + lT * rT) % mod;            // true only if both true
            else
                ways = (ways + lF * rT + lT * rF + lF * rF) % mod;
        }
        else if (exp[ind] == '|') {                       // OR operator
            if (isTrue)
                ways = (ways + lT * rT + lT * rF + lF * rT) % mod;
            else
                ways = (ways + lF * rF) % mod;            // both false
        }
        else {                                            // XOR operator
            if (isTrue)
                ways = (ways + lT * rF + lF * rT) % mod;  // different values
            else
                ways = (ways + lT * rT + lF * rF) % mod;  // same values
        }
    }

    return dp[i][j][isTrue] = ways;                       // store answer
}

int countWays(string exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(
        n, vector<vector<long long>>(n, vector<long long>(2, -1))
    );                                                    // memo table

    return f(0, n - 1, 1, exp, dp);                      // count true results
}



// (optimal) -tabulation t.c- O(n ^ 3) s.c- O(n ^ 2)
const int mod = 1e9 + 7;

int countWays(string exp) {
    int n = exp.size();

    vector<vector<vector<long long>>> dp(
        n, vector<vector<long long>>(n, vector<long long>(2, 0))
    );                                                    // dp[i][j][0/1]

    for (int i = n - 1; i >= 0; i--) {
        if (exp[i] != 'T' && exp[i] != 'F') continue;    // process operands only

        dp[i][i][1] = (exp[i] == 'T');                   // single operand is true
        dp[i][i][0] = (exp[i] == 'F');                   // single operand is false

        for (int j = i + 2; j < n; j += 2) {             // expand interval
            for (int ind = i + 1; ind < j; ind += 2) {  // try each operator
                long long lT = dp[i][ind - 1][1];       // left true
                long long lF = dp[i][ind - 1][0];       // left false
                long long rT = dp[ind + 1][j][1];       // right true
                long long rF = dp[ind + 1][j][0];       // right false

                if (exp[ind] == '&') {                   // AND operator
                    dp[i][j][1] = (dp[i][j][1] + lT * rT) % mod;
                    dp[i][j][0] = (dp[i][j][0] + lF * rT
                                  + lT * rF + lF * rF) % mod;
                }
                else if (exp[ind] == '|') {              // OR operator
                    dp[i][j][1] = (dp[i][j][1] + lT * rT
                                  + lT * rF + lF * rT) % mod;
                    dp[i][j][0] = (dp[i][j][0] + lF * rF) % mod;
                }
                else {                                   // XOR operator
                    dp[i][j][1] = (dp[i][j][1] + lT * rF
                                  + lF * rT) % mod;
                    dp[i][j][0] = (dp[i][j][0] + lT * rT
                                  + lF * rF) % mod;
                }
            }
        }
    }

    return dp[0][n - 1][1];                             // count true results
}