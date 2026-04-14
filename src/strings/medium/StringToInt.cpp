// statement- converts given str to a 32-bit signed integer
//algo is as : 1.Whitespace: Ignore any leading whitespace (" ")
//  2.Signedness: Determine the sign by checking if next character is '-' or '+', assuming +ve if neither present
//  3.Conversion: Read the integer by skipping leading 0's until a non-digit char is encountered or end of the str is reached. If no digits were read, then result is 0 
//  4.Rounding: If the integer is out of 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in range (i.e handle overflow)
//  Return the integer as the final result


//(optimal) t.c- O(n + n)  s.c- O(1)
int myAtoi(string s){
    int i = 0;
    int sign = 1;
    long long ans = 0; // use long long to detect overflow

    //skip leading spaces
    while (i < s.size() && s[i] == ' '){
        i++;
    }

    //check sign & assign -ve +ve accordingly
    if (i < s.size() && (s[i] == '+' || s[i] == '-')){
        if (s[i] == '-') sign = -1;
        i++;
    }

    //convert digits from str to int, handle overflow
    while (i < s.size() && isdigit(s[i])){
        ans = ans * 10 + (s[i] - '0');
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;
        i++;
    }
    return (int)(sign * ans); //as ans is longlong but fxn returns int so we define (int) before
}