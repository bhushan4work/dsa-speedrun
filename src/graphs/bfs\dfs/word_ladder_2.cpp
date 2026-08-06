// statement- Given 2 distinct words startWord & targetWord, & list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order
//            In this problem statement, we need to keep following conditions in mind:
//            A word can only consist of lowercase char.
//            Only 1 letter can be changed in each transformation.
//            Each transformed word must exist in wordList including targetWord.
//            startWord may or may not be part of wordList.
//            Return an empty list if there is no such transformation sequence.




//(optimal) -use this for interview, this soln may give tle in lc, t.c- O(n * l * 26)  s.c- O(n)
vector<vector<string>> findSequences(string beginWord, string endWord,
                                     vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end()); // Store all dictionary words for O(1) lookup and deletion
    queue<vector<string>> q;                                    // Queue stores complete transformation sequences

    q.push({beginWord}); // Start BFS with the begin word

    vector<string> usedOnLevel; // Tracks words used at the current BFS level
    usedOnLevel.push_back(beginWord);
    int level = 0; // Current BFS depth

    vector<vector<string>> ans; // Stores all shortest transformation sequences

    while (!q.empty())
    {
        vector<string> vec = q.front(); // Get current sequence
        q.pop();

        // Remove words used in the previous level
        if (vec.size() > level)
        {
            level++; // Move to the next BFS level
            for (auto it : usedOnLevel)
            {
                st.erase(it); // Prevent revisiting words from previous levels
            }
        }

        string word = vec.back(); // Current word in the sequence

        // If target word is reached
        if (word == endWord)
        {
            if (ans.size() == 0) // Store the first shortest sequence
            {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size()) // Store other sequences of the same minimum length
            {
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++) // Try changing every character
        {
            char original = word[i]; // Save original character

            for (char c = 'a'; c <= 'z'; c++) // Replace with every lowercase letter
            {
                word[i] = c;

                if (st.count(word) > 0) // Valid unvisited dictionary word
                {
                    vec.push_back(word);         // Extend current sequence
                    q.push(vec);                 // Push new sequence into BFS queue
                    usedOnLevel.push_back(word); // Mark word as used on this level
                    vec.pop_back();              // Backtrack
                }
            }

            word[i] = original; // Restore original character
        }
    }

    return ans; // Return all shortest sequences
}

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";

    for (string i : a)
        x += i; // Concatenate first sequence

    for (string i : b)
        y += i; // Concatenate second sequence

    return x < y; // Lexicographical comparison
}



//(optimal) -optimal approach for lc which doesnt give tle (dont prefer this for interview), t.c- O(n * l )  s.c- O(n)
map<string, int> mp; // Stores BFS level (distance) of each visited word

void dfs(string endWord, string beginWord, vector<vector<string>> &vec, vector<string> &vs)
{
    if (endWord == beginWord) // Reached the starting word
    {
        reverse(vs.begin(), vs.end()); // Reverse to get path from beginWord -> endWord
        vec.push_back(vs);             // Store the current shortest transformation sequence
        reverse(vs.begin(), vs.end()); // Restore original order for backtracking
        return;
    }

    for (int j = 0; j < endWord.size(); j++) // Try changing every character position
    {
        string ss = endWord; // Create a temporary word

        for (char c = 'a'; c <= 'z'; c++)
        { // Replace with every lowercase letter

            ss[j] = c; // Modify one character

            if (mp.find(ss) != mp.end() && // Word exists in BFS traversal
                mp[ss] + 1 == mp[endWord])
            {                                // It is exactly one level before current word
                vs.push_back(ss);            // Include this predecessor in the path
                dfs(ss, beginWord, vec, vs); // Continue searching backwards
                vs.pop_back();               // Backtrack
            }
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    queue<string> q;         // BFS queue
    unordered_set<string> s; // Fast lookup for unvisited words

    for (string i : wordList)
    {
        s.insert(i); // Insert all dictionary words
    }

    s.erase(beginWord); // Mark beginWord as visited
    q.push(beginWord);  // Start BFS from beginWord

    int h = 0; // Current BFS level

    while (!q.empty())
    {
        int l = q.size(); // Number of nodes at current level
        h++;              // Move to next level

        while (l--)
        {
            string i = q.front(); // Current word
            mp[i] = h;            // Store its BFS level
            q.pop();

            for (int j = 0; j < i.size(); j++)
            { // Change every character position

                string ss = i; // Temporary word

                for (char c = 'a'; c <= 'z'; c++)
                { // Try every possible character

                    ss[j] = c; // Replace current character

                    if (s.find(ss) != s.end())
                    {                // Valid and unvisited dictionary word
                        q.push(ss);  // Visit it in BFS
                        s.erase(ss); // Remove to avoid revisiting
                    }
                }
            }
        }
    }

    vector<vector<string>> vec; // Stores all shortest transformation sequences

    if (mp.find(endWord) != mp.end())
    { // Proceed only if endWord is reachable
        vector<string> vs;
        vs.push_back(endWord);            // Start DFS from endWord
        dfs(endWord, beginWord, vec, vs); // Reconstruct all shortest paths
    }

    return vec; // Return all shortest transformation sequences
}