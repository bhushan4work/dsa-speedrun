// statement- 2 arr represent arrival & departure time of trains that stop at the platform. find min no of platforms needed at railway station so that no train has to wait


// method1(brute) t.c- O(n^2)  s.c- O(1)
int countPlatforms(int n, int arr[], int dep[]){
    int maxCount = 1; // Initialize answer to 1

    for (int i = 0; i < n; i++){
        int count = 1; // Initialize count of overlapping intervals

        for (int j = i + 1; j < n; j++){

            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i])){ // Check if there is overlap betn train i & j
                count++;
            }
        }
        maxCount = max(maxCount, count); // Update max platform count
    }
    return maxCount;
}


// method2(optimal) t.c- O(2 * nlogn + 2n)  s.c- O(1)
int countPlatforms(int n, int arr[], int dep[]){
    // Sort the arrival & departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // Initialize pointers and counters
    int platform = 1;
    int maxPlatform = 1;
    int i = 1, j = 0;

    while (i < arr.size() && j < dep.size()){
        if (arr[i] <= dep[j]){ // If next train arrives before curr one departs
            platform++; // One more platform needed
            i++;
        }
        else{ // One train departs, platform freed
            platform--;
            j++;
        }
        maxPlatform = max(maxPlatform, platform); // Update max required platforms
    }
    return maxPlatform;
}