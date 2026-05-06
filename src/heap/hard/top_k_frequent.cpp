// statement- Given arr & int k, return k most frequent elements. return ans in any order


//(brute) t.c- O(nlog(k))  s.c- O(n)
vector<int> topKFrequent(vector<int> &nums, int k){
    // count freq of each element
    unordered_map<int, int> mp;
    for (int i : nums) mp[i]++;

    // Stores: {freq, number}, greater<pair<int,int>> compares using 1st value first & so we keep freq at 1st
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater<p> > pq; // min-heap

    // Push it in min-heap & maintain size k
    for (auto it : mp){
        pq.push({it.second, it.first}); //{freq, number}
        if (pq.size() > k) pq.pop();
    }

    // Pick all top K elements
    vector<int> result;
    while (!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}


//(optimal) -using bucket sort t.c- O()  s.c- O(1)
vector<int> topKFrequent(vector<int> &nums, int k){
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int &num : nums){
        mp[num]++;
    }

    // index = freq, val= list of elements having that freq
    // bucket[i] = elements occuring ith time
    vector<vector<int>> bucket(n + 1);
    for (auto &it : mp){
        int element = it.first;
        int freq = it.second;
        bucket[freq].push_back(element); //place element at ith index freq
    }

    /* if output is asked in descending order sort it before traversal
    for(int i = 1; i <= n; i++) { 
        sort(bucket[i].begin(), bucket[i].end(), greater<int>());
    }  */

    // traverse from back to find max freq elements
    vector<int> result;
    for(int i = n; i >= 1; i--) {
        for(int num : bucket[i]) {
            result.push_back(num); // push all existing numbers having freq = i

            if(result.size() == k) {  // Stop once k elements collected
                return result;
            }
        }

    }

    return result;
}