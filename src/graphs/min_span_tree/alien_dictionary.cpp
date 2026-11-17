//statement- Given sorted dictionary of an alien language having N words & K starting alphabets of standard dictionary. Find order of characters in alien language.
//           There may be multiple valid orders for a particular test case, thus u may return any valid order as string. output will be True if order returned by fxn is correct,
//           else False denoting an incorrect order. If given arrangement of words is inconsistent with any possible letter ordering, return an empty string ""


// (brute) t.c- O(n + v + e)  s.c- O(v + e)
bool dfs(char node, unordered_map<char, set<char>>& graph, unordered_map<char, int>& state, string& order) {
    if (state[node] == 1) { // 1 means active; if visited again in the same path, it's a cycle.
        return false;
    }
    if (state[node] == 2) { // 2 means fully processed; safely skip.
        return true;
    }
    state[node] = 1; // Mark node as active while exploring its children.
    for (char nextChar : graph[node]) { // Traverse all adjacent nodes (characters that must come after).
        if (!dfs(nextChar, graph, state, order)) {
            return false;
        }
    }
    state[node] = 2; // Mark as fully processed after exploring all children.
    order.push_back(node); // Add to postorder result.
    return true;
}
string alienOrder(vector<string>& words) {
    unordered_map<char, set<char>> graph;
    unordered_map<char, int> state;
    for (string& word : words) { // Initialize graph and states for all unique characters.
        for (char symbol : word) {
            graph[symbol];
            state[symbol] = 0; // 0 means unvisited.
        }
    }
    for (int wordIndex = 0; wordIndex + 1 < (int)words.size(); wordIndex++) { // Compare adjacent words to build the graph.
        string first = words[wordIndex];
        string second = words[wordIndex + 1];
        int minLength = min(first.size(), second.size());
        if (first.size() > second.size() && first.substr(0, minLength) == second) { // Invalid case: longer word before its prefix.
            return "";
        }
        for (int pos = 0; pos < minLength; pos++) { // Find the first mismatch to establish a directed edge.
            if (first[pos] != second[pos]) {
                graph[first[pos]].insert(second[pos]);
                break;
            }
        }
    }
    string order = "";
    for (auto& entry : state) { // Attempt DFS topological sort from all unvisited nodes.
        char node = entry.first;
        if (state[node] == 0) {
            if (!dfs(node, graph, state, order)) {
                return ""; // Cycle detected, invalid ordering.
            }
        }
    }
    reverse(order.begin(), order.end()); // Reverse the postorder to get the correct topological sort.
    return order;
}



// (optimal) t.c- O(c)  s.c- O(1)
string alienOrder(vector<string>& words) {
    unordered_map<char, set<char>> graph;
    unordered_map<char, int> indegree;
    for (string& word : words) { // Create graph node and indegree entry for every character.
        for (char symbol : word) {
            graph[symbol];
            indegree[symbol] = 0;
        }
    }
    for (int wordIndex = 0; wordIndex + 1 < (int)words.size(); wordIndex++) { // Build directed rules from adjacent sorted words.
        string first = words[wordIndex];
        string second = words[wordIndex + 1];
        int minLength = min(first.size(), second.size());
        if (first.size() > second.size() && first.substr(0, minLength) == second) { // Longer word before equal prefix creates invalid order.
            return "";
        }
        for (int pos = 0; pos < minLength; pos++) { // Add one unique edge from first mismatch.
            if (first[pos] != second[pos]) {
                if (graph[first[pos]].insert(second[pos]).second) {
                    indegree[second[pos]]++;
                }
                break;
            }
        }
    }
    queue<char> q;
    for (auto& entry : indegree) { // Push all characters without prerequisites.
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }
    string order = "";
    while (!q.empty()) { // Remove zero-indegree characters level by level.
        char node = q.front();
        q.pop();
        order.push_back(node);
        for (char nextChar : graph[node]) { // Reduce indegree for every dependent character.
            indegree[nextChar]--;
            if (indegree[nextChar] == 0) {
                q.push(nextChar);
            }
        }
    }
    if (order.size() != indegree.size()) { // Missing characters in order means cycle.
        return "";
    }
    return order;
}