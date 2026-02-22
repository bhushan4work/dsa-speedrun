// statement- return a str with its words in reverse order, concatenated by a single space

// method1(brute) t.c- O(n)  s.c- O(n)
string reverseWords(string s){
    vector<string> words;  // Vector to store words
    string word = ""; // Temporary str to store a single word

    //we add a word to words list only when we encounter a ' '
    for (int i = 0; i < s.size(); i++){
        if (s[i] != ' '){ // If char is not a space, add it to the curr word
            word += s[i];
        }
        else if (s[i] == ' ' && !word.empty()){ // If we encounter a space and have a word collected
            words.push_back(word); // Push the collected word to words list
            word = ""; // Reset word for next word collection
        }
    }

    // Push the last word if it exists, as we might not have a space at last everytime
    if (!word.empty()){
        words.push_back(word);
    }
    reverse(words.begin(), words.end()); 

    // Join the words into a single string separated by spaces
    string result = "";
    for (int i = 0; i < words.size(); i++){
        result += words[i];
        if (i < words.size() - 1) { // Add a space if it's not the last word
            result += " ";
        }
    }
    return result;
}


// method2(optimal) t.c- O(n)  s.c- O(1)
string reverseWords(string s){
    string ans = "";
    reverse(s.begin(), s.end()); //reverse whole str

    for (int i = 0; i < s.size(); i++){
        string word = "";
        while (s[i] != ' ' && i < s.size()){
            word += s[i]; 
            i++;
        }
        reverse(word.begin(), word.end()); 
        if (word.length() > 0){ //to avoid extra space, add only when word exists
            ans += ' ' + word;
        }
    }
    if (!ans.empty()) return ans.substr(1); //started from 1 as we get 1 extra space while adding 1st word to ans
    return ans; //else when we dont find anything we return initial ans ""
}