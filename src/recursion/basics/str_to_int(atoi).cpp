// statement- Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer. The algorithm for myAtoi(string s) is as follows:
//  -Ignore any leading whitespace (" ")
//  -Determine sign by checking if next char is '-' or '+', assuming positivity if neither present
//  -Read int by skipping leading zeros until non-digit char is encountered or end of str is reached. If no digits were read, then result is 0
//  -If int is out of 32-bit signed int range [-231, 231 - 1], then round int to remain in range. int < -231 should be rounded to -231, int  > 231 - 1 should be rounded to 231 - 1


// (optimal) t.c- O(n)  s.c- O(n)
int solve(string &s, int i, long long num, int sign){ // Helper recursive fxn

    if (i >= s.size() || !isdigit(s[i])){ // Base case: end of string OR non-digit encountered
        return sign * num;
    }
    int digit = s[i] - '0'; // Convert current character to digit
    num = num * 10 + digit; // Build number

    // Handle overflow
    if (sign == 1 && num > INT_MAX) return INT_MAX;
    if (sign == -1 && -num < INT_MIN) return INT_MIN;

    return solve(s, i + 1, num, sign); // Recurse for next char
}

int myAtoi(string s){
    int i = 0, n = s.size();

    while (i < n && s[i] == ' ') i++; // Skip leading spaces

    //  Handle sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')){
        if (s[i] == '-') sign = -1;
        i++;
    }
    return solve(s, i, 0, sign); // Call recursive parser
}