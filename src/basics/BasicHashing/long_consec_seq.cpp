//statement- Given an arr. Return length of longest seq of consecutive integers. integers in this seq can appear in any order


// (brute) t.c- O(n^2)  s.c- O(1)
bool linearSearch(vector<int>& nums, int target) { // Returns true when target value occurs in array.
    for (int scanIndex = 0; scanIndex < nums.size(); scanIndex++) { // Inspect every array position for requested value.
        if (nums[scanIndex] == target) { // A match confirms that target is present.
            return true;
        }
    }

    return false;
}

int longestConsecutive(vector<int>& nums) { // Returns length of longest consecutive sequence.
    int n = nums.size();
    int longestLength = 0;

    for (int startIndex = 0; startIndex < n; startIndex++) { // Use every array element as beginning of a possible sequence.
        int currentLength = 1;
        int nextValue = nums[startIndex] + 1;

        while (linearSearch(nums, nextValue)) { // Extend sequence while next integer exists in array.
            currentLength++;
            nextValue++;
        }

        longestLength = max(longestLength, currentLength);
    }

    return longestLength;
}



// (better) t.c- O(nlogn + n)  s.c- O(n)
int longestConsecutive(vector<int>& nums) { // Returns length of longest consecutive sequence.
    vector<int> sortedNums = nums;
    if (sortedNums.empty()) { // An empty array contains no sequence.
        return 0;
    }

    sort(sortedNums.begin(), sortedNums.end()); // Sorting a copy preserves original input.

    int currentLength = 1;
    int longestLength = 1;
    int previousValue = sortedNums[0];

    for (int index = 1; index < sortedNums.size(); index++) { // Compare each sorted value with previous distinct value.
        if (sortedNums[index] == previousValue) { // A duplicate must not change current sequence length.
            continue;
        }
        else if (sortedNums[index] == previousValue + 1) { // A value exactly one greater extends current sequence.
            currentLength++;
        }
        else { // Any larger gap starts a new sequence at current value.
            currentLength = 1;
        }

        previousValue = sortedNums[index];
        longestLength = max(longestLength, currentLength);
    }

    return longestLength;
}



// (optimal) t.c- O(n)  s.c- O(n)
int longestConsecutive(vector<int>& nums) { // Returns length of longest consecutive sequence.
    unordered_set<int> values(nums.begin(), nums.end());
    int longestLength = 0;

    for (int value : values) { // Examine every distinct value as a possible sequence start.
        if (values.count(value - 1)) { // A present predecessor means this value lies inside a sequence.
            continue;
        }

        int currentLength = 1;
        int nextValue = value + 1;
        while (values.count(nextValue)) { // Extend sequence while each next consecutive value exists.
            currentLength++;
            nextValue++;
        }

        longestLength = max(longestLength, currentLength);
    }
    
    return longestLength;
}