// statement- Given 2 arr & int k, return max k valid sum combinations from all. A valid sum combin is made by adding 1 element from both arr arr. Return ans in descending order


//(brute) t.c- O(n1 * n2 * n1n2log(n1n2))  s.c- O(n + m)
vector<int> maxCombinations(vector<int> &nums1, vector<int> &nums2, int k){
    vector<int> allSums;

    for (int i = 0; i < nums1.size(); i++){
        for (int j = 0; j < nums2.size(); j++){
            allSums.push_back(nums1[i] + nums2[j]); // Compute pair sum & store it
        }
    }

    sort(allSums.begin(), allSums.end(), greater<int>()); // Sort all sums in descending order

    // Return first k elements from sorted list
    vector<int> result(allSums.begin(), allSums.begin() + k);
    return result;
}


//(optimal) t.c- O(klogk)  s.c- O(k)
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B){
    // Sort both arr in descending order to get final ans in descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq; // Max heap: {sum, {i, j}}
    set<pair<int, int>> visited; // To avoid pushing duplicate index pairs


    // Start with largest possible sum
    pq.push({A[0] + B[0], {0, 0}});
    visited.insert({0, 0});


    while (K--){
        auto top = pq.top(); // Get current max {a[0] + b[0], {0,0}}
        pq.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        ans.push_back(sum);

        // Move to next element in A (i+1, j)
        if (i + 1 < N && !visited.count({i + 1, j}) ){
            pq.push({A[i + 1] + B[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }

        // Move to next element in B (i, j+1)
        if (j + 1 < N && !visited.count({i , j+1}) ){
            pq.push({A[i] + B[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return ans;
}