#include <iostream> 
#include <string> 
using namespace std ;

//palindrome - which gives same output as of input on reversal

//Leetcode - 125. Valid Palindrome - Easy
//method1
bool isPalindrome(string str) {
    int left = 0, right = str.length()-1;
    while(left<right){
        char l = str[left], r = str[right];
        if(!isalnum(l)) //if not letter or num then skip
            left++;
        else if(!isalnum(r)) //if not letter or num then skip
            right--;
        else if(tolower(l)!=tolower(r)) //lowercase both n compare,if not same then false
            return false;
        else {
            left++; //if char matches then move inward from both ends
            right--;
        }
    }
    return true;  //all checks passed so return true
    //if we finish loop without returning false then its palindrome
}

//method2 : by recursion
bool palindrome(int i, string s){
    // Base Condition
    // If i exceeds half of the string, means all the elements
    // are compared, we return true.
    if(i>=s.length()/2) return true;

    // If start is not equal to end, not palindrome.
    if(s[i] != s[s.length() - i - 1]) return false;

    // If both characters are same, increment i and check start+1 and end-1.
    return palindrome(i+1,s);
}

int main(){
    //for method1
        string str = "ABCDCBA";
        bool ans = isPalindrome(str);

        if (ans == true){
            cout << "Palindrome" ;
        }
        else{
            cout << "Not Palindrome" ;
        }

        //for method2
        // Example string.
        string s = "madam";
        cout << palindrome(0,s) ;
}