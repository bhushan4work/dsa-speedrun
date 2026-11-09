// statement- Given a sorted arr, containing integer positions of n gas stations on X-axis, integer k, place k new gas stations on X-axis. new gas stations can be
//            placed anywhere on non-negative side of X-axis, including non-integer positions. Let dist be max distance betw adj gas stations after adding k new
//            gas stations. Find min value of dist. ur ans will be accepted if it is within 1e-6 of true value


// (brute) t.c- O( (k * n)  s.c- O(n)
long double minimiseMaxDistance(vector<int> &arr, int k) { // Manually scans array k times to find and divide largest current gap
    int n = arr.size();
    vector<int> howMany(n - 1, 0); // Array to track how many new stations are added in each original gap

    for (int stations = 1; stations <= k; stations++) { // Place k stations one by one in largest available gaps
        long double maxSection = -1.0;
        int maxIndex = -1;

        for (int i = 0; i < n - 1; i++) { // Scan all gaps to find current maximum section length
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);

            if (sectionLength > maxSection) { // Keep track of largest gap found
                maxSection = sectionLength;
                maxIndex = i;
            }
        }

        howMany[maxIndex]++; // Add one station to largest found gap
    }

    long double maxAns = -1.0;
    for (int i = 0; i < n - 1; i++) { // Calculate final maximum distance across all sections
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}



// (better) t.c- O( (n + k * logn)  s.c- O(n)
long double minimiseMaxDistance(vector<int>& arr, int k) { // Utilizes a max heap to continuously retrieve and divide largest available distance segment efficiently.
    int n = arr.size();
    vector<int> howMany(n - 1, 0); // Array to track how many new stations are added in each original gap.
    priority_queue<pair<long double, int>> pq; // Max heap to store pairs of current gap distance and its original index.
    for (int i = 0; i < n - 1; i++) { // Populate heap with initial gaps between stations.
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int stations = 1; stations <= k; stations++) { // Place k stations one by one by always splitting largest gap.
        auto top = pq.top(); // Retrieve maximum gap from top of heap.

        pq.pop();
        int secIndex = top.second;
        howMany[secIndex]++; // Add a station to this specific gap segment.

        long double originalDiff = arr[secIndex + 1] - arr[secIndex]; // Calculate newly divided segment length.
        long double newSectionLen = originalDiff / (long double)(howMany[secIndex] + 1);

        pq.push({newSectionLen, secIndex}); // Reinsert reduced gap back into heap for future operations.
    }

    return pq.top().first; // maximum distance is guaranteed to be at top of heap.
}



// (optimal) t.c- O( (n * log(max / 1e^-16))  s.c- O(1)
int numberOfGasStationsRequired(vector<int>& arr, long double dist) { // Helper function to verify how many gas stations are required to enforce a specific maximum distance rule across all gaps
    int required = 0;
    for (int i = 0; i < arr.size() - 1; i++) { // Check every existing gap between stations
        required += (int)((arr[i + 1] - arr[i]) / dist); // Count how many sections of 'dist' length fit inside gap
    }

    return required;
}

long double minimiseMaxDistance(vector<int> &arr, int k) { // Optimal approach using binary search to guess maximum distance and validate it against our allowed station capacity
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < arr.size() - 1; i++) { // Find absolute maximum gap to act as upper search boundary
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    while (high - low > 1e-6) { // Loop runs until search boundaries are precise to 6 decimal places
        long double mid = low + (high - low) / 2.0; // Guess middle distance
        if (numberOfGasStationsRequired(arr, mid) > k) { // Validate if guessed distance fits within our allowed k stations
            low = mid; // Too many stations needed, distance is too strict
        }
        else {
            high = mid; // Feasible distance, attempt to restrict it further
        }
    }

    return high; // Return precise finalized upper bound
}