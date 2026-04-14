// statement- given valid parentheses string s, return nesting depth of s. The nesting depth is max no of nested parentheses

// (optimal) t.c- O(n)  s.c- O(1)
int maxDepth(string s){
    int ans = 0; //store max nested depth cnt of string
    int currCnt = 0; //max depth seen so far
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            currCnt++; //decr currCnter on )
        }
        else if (s[i] == ')'){ 
            currCnt--; //decr currCnter on )
        }
        ans = max(ans, currCnt); //update max depth if curr depth is greater
    }
    return ans;
}