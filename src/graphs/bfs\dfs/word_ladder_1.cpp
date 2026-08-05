// statement- Given 2 distinct words startWord targetWord, list denoting wordList of unique words of equal lengths. Find length of shortest transformation seq from startWord to targetWord
//            In this problem statement, we need to keep the following conditions in mind:
//                word can only consist of lowercase characters
//                Only one letter can be changed in each transformation
//                Each transformed word must exist in wordList including targetWord
//                startWord may or may not be part of wordList
//  Note:  If there’s no possible way to transform seq from startWord to targetWord return 0


//(optimal) -using bfs t.c- O(n * wordlen * 26 * logn )  s.c- O(n * wordlen)
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList){
    queue<pair<string, int>> q; // Queue for BFS storing {curr word, steps taken}
    q.push({startWord, 1});

    // set ds for quick lookup & deletion
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while (!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord) return steps; // If target word is found, return steps
        
        // Try changing every char in curr word. ex : word = hot
        for (int i = 0; i < word.size(); i++){
            char original = word[i]; // curr letter to be changed from a-z & checked in curr word
            for (char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch; // ex: if og is 'h' in word hot, so aot,bot,... & checking it 
                if (st.find(word) != st.end()){ // if it exists in set
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            // replace curr letter changed back to its og letter
            word[i] = original; //i.e after last iteration zot -> hot back again
        }
    }
    return 0; // If no sequence exists
}