//statement- Given an integer array containing values from [1, n] & each value appears exactly once except for A which appears twice & B which is missing.
//           Return values A & B, as an array of size 2. Note: You are not allowed to modify original arr


// (brute) t.c- O(n^2)  s.c- O(1)
vector<int> findNumbers(vector<int>& nums) { // Finds duplicate and missing numbers by counting every candidate.
    int n = nums.size();
    int repeating = -1;
    int missing = -1;

    for (int candidate = 1; candidate <= n; candidate++) { // Count occurrences of every expected value.
        int frequency = 0;
        for (int value : nums) {
            if (value == candidate) { // Increase count when current candidate is found.
                frequency++;
            }
        }

        if (frequency == 2) { // Save a candidate that appears twice as duplicate.
            repeating = candidate;
        }
        else if (frequency == 0) { // Save a candidate that never appears as missing number.
            missing = candidate;
        }

        if (repeating != -1 && missing != -1) { // No further candidates can change the unique answer.
            break;
        }
    }

    return {repeating, missing};
}



// (better) using hashing t.c- O(2n)  s.c- O(n)
vector<int> findNumbers(vector<int>& nums) { // Finds the duplicate and missing numbers using a frequency array.
    int n = nums.size();
    vector<int> frequency(n + 1, 0);
    for (int value : nums) { // Store the count of each value at its matching index.
        frequency[value]++;
    }

    int repeating = -1;
    int missing = -1;
    for (int value = 1; value <= n; value++) { // Inspect all valid values to locate counts two and zero.
        if (frequency[value] == 2) { // A count of two identifies the duplicate number.
            repeating = value;
        }
        else if (frequency[value] == 0) { // A count of zero identifies the missing number.
            missing = value;
        }

        if (repeating != -1 && missing != -1) { // Stop after both required numbers have been found.
            break;
        }
    }

    return {repeating, missing};
}



// (optimal1) math sum approach t.c- O(n)  s.c- O(1)
vector<int> findNumbers(vector<int>& nums) { // Finds duplicate and missing numbers using sums and square sums.
    long long n = nums.size();
    long long actualSum = 0;
    long long actualSquareSum = 0;

    for (long long value : nums) { // Accumulate two actual totals using wide integers.
        actualSum += value;
        actualSquareSum += value * value;
    }

    long long expectedSum = n * (n + 1) / 2;
    long long expectedSquareSum = n * (n + 1) * (2 * n + 1) / 6;
    long long difference = actualSum - expectedSum;
    long long sumOfAnswers = (actualSquareSum - expectedSquareSum) / difference;
    long long repeating = (difference + sumOfAnswers) / 2; // Use sum and difference of answers to find both numbers.
    long long missing = repeating - difference;
    
    return {(int)repeating, (int)missing};
}



// (optimal2) xor approach t.c- O(n)  s.c- O(1)
vector<int> findNumbers(vector<int>& nums) { // Finds duplicate and missing numbers by separating XOR results.
    int n = nums.size();
    int xorAll = 0;
    for (int value : nums) { // Cancel all values that occur once in both collections.
        xorAll ^= value;
    }

    for (int value = 1; value <= n; value++) {
        xorAll ^= value;
    }

    int rightmostSetBit = xorAll & -xorAll;
    int first = 0;
    int second = 0;

    for (int value : nums) { // Partition input according to differing bit.
        if ((value & rightmostSetBit) != 0) { // Place value in group selected by differing bit.
            first ^= value;
        }
        else {
            second ^= value;
        }
    }

    for (int value = 1; value <= n; value++) { // Partition expected range in same way.
        if ((value & rightmostSetBit) != 0) { // Place value in group selected by differing bit.
            first ^= value;
        }
        else {
            second ^= value;
        }
    }

    int firstCount = 0; // Determine which survivor actually appears twice.
    for (int value : nums) {
        if (value == first) { // Count how often first result appears in input.
            firstCount++;
        }
    }

    if (firstCount == 2) { // Return result that appears twice as duplicate.
        return {first, second};
    }

    return {second, first};
}