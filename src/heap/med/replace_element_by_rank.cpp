// statement- Given arr of N integers, task is to replace each element of arr by its rank in arr


//(brute) t.c- O(n^2)  s.c- O(n)
vector<int> replaceWithRank(vector<int> &arr, int N){
    vector<int> ans(N);

    for (int i = 0; i < N; i++){
        int rank = 1; //rank counter

        for (int j = 0; j < N; j++){
            // If we find an element strictly smaller than arr[i]
            if (arr[j] < arr[i]){
                rank++; // it means arr[i]'s rank should incr
            }
        }
        // After counting all smaller elements,
        ans[i] = rank; // assign computed rank to curr index
    }

    return ans;
}

//(optimal) t.c- O(nlogn)  s.c- O(n)
vector<int> replaceWithRank(vector<int> &arr){
    vector<int> sortedArr = arr; // Copy the original array for sorting
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> rankMap; // Create map to store rank of each unique number
    int rank = 1; //rank counter

    // Assign rank to each unique element in sorted order
    for (int num : sortedArr){
        // If this number is not already assigned a rank (ensures duplicates dont get wrong rank)
        if (rankMap.find(num) == rankMap.end()){  // also written as rankMap.count(num) == 0
            rankMap[num] = rank;
            rank++;
        }
    }

    // Replace each element in original array with its rank
    vector<int> result;
    for (int num : arr){
        result.push_back(rankMap[num]);
    }

    return result;
}
