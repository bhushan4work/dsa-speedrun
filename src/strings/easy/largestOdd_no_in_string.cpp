// statement- return largest odd integer (as string) i.e substring. if no odd digit found return ""

// method1(optimal) t.c- O(n)  s.c- O(1)
string largestOddNumber(string arr){
    //find odd digit from end and return whole substring from start to this end 
    for (int i = arr.size() - 1; i >= 0; i--){ 
        // arr[i] - '0' is done to convert char to int
        if ((arr[i] - '0') % 2 != 0){
            return arr.substr(0, i + 1);
        }
    }
    return "";
}