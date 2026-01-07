//statement- Given arr of integers, rearrange the numbers of given array into lexicographically next greater permutation of numbers
//            If such an arrangement is not possible, it must rearrange to lowest possible order(i.e. sorted in ascending)
//approach: generate all combinations in sorted form(using recursion), do a linear search of input, pick the next index

// method1(brute)  t.c- O( n!(combinations)*n(length) )  s.c- O(n!*n)
vector<int> nextPermutation(vector<int> &nums){
    vector<vector<int>> all;  //'all' stores every permutation of arr & each permutation is vector<int>
    vector<int> original = nums; //stores copy of original nums arr, will need this during comparing as we sort it below & modify it

    sort(nums.begin(), nums.end()); //sort given arr to get lexicographical order

    do{
        all.push_back(nums);  //store current permutation
    } while (next_permutation(nums.begin(), nums.end()));  //generates the next lexicographical permutation

    for (int i = 0; i < all.size(); i++){  //Traverse the list to find current permutation
        if (all[i] == original){
            if (i == all.size() - 1)
                return all[0];  //if it's the last permutation

            return all[i + 1]; //else return the next one
        }
    }
    return nums; //safety return if permutation is not found
}


// method2(optimal)  t.c- O(3n)  s.c- O(n) if said that modifying arr takes extraSpace by interviewer else O(1)
void nextPermutation(vector<int> &arr){
    int ind = -1;
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--){   // iterating from right to left
        if (arr[i] < arr[i + 1]){      // when dip\smaller element is found
            ind = i;     // store index of dip and so we get breakpoint
            break;
        }
    }

    if (ind == -1){ // no dip found so return the 1st permutation after reversing
        reverse(arr.begin(), arr.end());
        return arr; // dont run further part and simply return
    }

    for (int i = n - 1; i >= 0; i--){
        if (arr[i] > arr[ind]){   // finds smallest element which is greater than dip
            swap(arr[i], arr[ind]); // swap them
            break;
        }
    }

    reverse(arr.begin() + ind + 1, arr.end()); // reverse part from breakpoint index to end

    return arr; // returns the next permutation
}