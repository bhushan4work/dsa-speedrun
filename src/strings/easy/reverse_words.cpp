// statement- The words in s are separated by at least one space. Return a string with words in reverse order, concatenated by single space

// method1(brute) t.c- O(n)  s.c- O(n)
string reverseWords(string s){
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end()); //Reverse the entire string

    for (int i = 0; i < n; i++){
        string word = "";

        // Stop when we reach a space or end of string
        while (i < n && s[i] != ' '){
            word += s[i]; // Collect characters of the current word
            i++;
        }

        reverse(word.begin(), word.end()); // Reverse the current word to get original word order

        if (word.length() > 0){ // If word is not empty, add it to answer with a space before it
            ans += " " + word;
        }
    }
    return ans.substr(1); // started from (1) to remove the 1st extra space & return result
}


// method2(optimal) t.c- O(n)  s.c- O(n)
string reverseWords(string s){
    string result = ""; // Result string to store final output
    int i = s.size() - 1; // Pointer starting from the last character

    while (i >= 0){
        while (i >= 0 && s[i] == ' '){ // Skip spaces at the current position
            i--;
        }

        if (i < 0) break; // If pointer is out of bounds, break

        int end = i;  // Mark the end of the current word
        while (i >= 0 && s[i] != ' '){ // Move left until a space or start of string is found
            i--;
        }

        string word = s.substr(i + 1, end - i); // Extract the current word

        if (!result.empty()){ // Add space before appending next word if result is not empty
            result += " ";
        }
        result += word; // Append the word to the result
    }
    return result;
}
