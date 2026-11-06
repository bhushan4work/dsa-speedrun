//statement- Given an integer arr. Return all elements which appear more than n/3 times. output can be returned in any order


// (brute) t.c- O(n^2)  s.c- O(1)
vector<int> majorityElement(vector<int>& nums) { // Returns all elements appearing more than one-third of the time.
    int n = nums.size();
    int threshold = n / 3;
    vector<int> answer;

    for (int candidateIndex = 0; candidateIndex < n; candidateIndex++) { // Test the value at every index as a possible qualifying candidate.
        int candidate = nums[candidateIndex];
        int frequency = 0;
        for (int scanIndex = 0; scanIndex < n; scanIndex++) { // Count the current candidate with an index-controlled full scan.
            if (nums[scanIndex] == candidate) { // Equal values contribute to the candidate's frequency.
                frequency++;
            }
        }

        bool notAdded = find(answer.begin(), answer.end(), candidate) == answer.end();
        if (frequency > threshold && notAdded) { // Store a qualifying candidate only once.
            answer.push_back(candidate);
        }

        if (answer.size() == 2) { // No third value can occur more than one-third of the time.
            break;
        }
    }

    return answer;
}



// (better) -using hashing t.c- O(nlogn)  s.c- O(n)
vector<int> majorityElement(vector<int>& nums) { // Returns all elements appearing more than one-third of the time.
    int threshold = nums.size() / 3;
    map<int, int> frequency;
    vector<int> answer;

    for (int value : nums) { // Store the final frequency of every distinct value.
        frequency[value]++;
    }

    for (const auto& entry : frequency) { // Inspect each distinct value directly in ascending key order.
        if (entry.second > threshold) { // Store the value when its final frequency crosses the threshold.
            answer.push_back(entry.first);
        }

        if (answer.size() == 2) { // At most two distinct values can satisfy the condition.
            break;
        }
    }

    return answer;
}



// (optimal) -using moore voting algo t.c- O(n)  s.c- O(1)
vector<int> majorityElement(vector<int>& nums) { // Returns all elements appearing more than one-third of the time.
    int candidate1 = nums[0];
    int candidate2 = nums[0];
    int count1 = 0;
    int count2 = 0;

    for (int value : nums) { // Select at most two possible candidates through vote cancellation.
        if (value == candidate1) { // A match strengthens the first candidate.
            count1++;
        }
        else if (value == candidate2) { // A match strengthens the second candidate.
            count2++;
        }
        else if (count1 == 0) { // An empty first slot accepts the current value as its candidate.
            candidate1 = value;
            count1 = 1;
        }
        else if (count2 == 0) { // An empty second slot accepts the current value as its candidate.
            candidate2 = value;
            count2 = 1;
        }
        else { // A third distinct value cancels one vote from both candidates.
            count1--;
            count2--;
        }
    }

    int verified1 = 0;
    int verified2 = 0;

    for (int value : nums) { // Count the real frequencies of the selected candidates.
        if (value == candidate1) { // An occurrence of the first candidate increases its verified count.
            verified1++;
        }
        else if (value == candidate2) { // An occurrence of the second candidate increases its verified count.
            verified2++;
        }
    }

    int threshold = nums.size() / 3;
    vector<int> answer;
    if (verified1 > threshold) { // Include the first candidate only when its real frequency qualifies.
        answer.push_back(candidate1);
    }

    if (candidate2 != candidate1 && verified2 > threshold) { // Include a distinct second candidate only when it also qualifies.
        answer.push_back(candidate2);
    }
    
    return answer;
}