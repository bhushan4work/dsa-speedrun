#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//Note: locally(inside main)     int array max size(10^6) ; bool array max size(10^7)
//      globally(outside main)   int array max size(10^7) ; bool array max size(10^8)
//array of size > 10^7 can be done by map\unordered_map in cpp

int main(){
    // ---NumHashing---
    //instead of making a 'for' loop & checking freq of num in array we do hashing as it takes less time
    //input goes like - ex : 5 -         size of array
    //                       2 3 4 5 6   array
    //                       3           num of queries
    //                       2 4 5       query is num 2 ,4, 5
    //                       1           prints the output & it goes on till u give all 3 queries
    //                       1
    //                       1
    //T.C - O(q*n) as we arent looping instead, we having 'q' num of queries
    int n1;
    cin >> n1;
    int arr1[n1]; //makes an array of size n
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i]; //iterates over each input of the array given
    }

    //precompute:
    //Let's say arr = [3, 5, 3]:
    //for i = 0: arr at [0] = 3
    //hash[3]++ i.e, hash[3] goes from 0 → 1
    //for i = 1: arr at [1] = 5
    //hash[5]++ i.e, hash[5] goes from 0 → 1
    //for i = 2: arr at [2] = 3
    //hash[3]++ i.e, hash[3] goes from 1 → 2
    int hash1[13] = {0}; //creates an array of size 13, initialized to 0
    //num here which is 13 rn depends on the max num of the given array
    for (int i = 0; i < n1; i++) {
        hash1[arr1[i]]++;
    }

    int q1;
    cin >> q1; //query which is asked i.e, freq of a num here
    while (q1--) {
        int number;
        cin >> number; //stores the query input
        // fetching:
        cout << hash1[number] << endl; //prints the freq of occurence of query in array
    }

    //---char hashing---
    //instead of making a 'for' loop & checking freq of num in array we do hashing as it takes less time
    //only lowercase: char-'a' ; only uppercase char-'A'
    //if not mentioned then char (make an array of size 256 so it allocates the respective ascii num)

    //-when string contain only lowercase
    string s2;
    cin >> s2;
    //ex s = abgfuidt

    //precompute
    int hash2[26] = {0};
    for(int i = 0; i < s2.size(); i++){
        hash2[s2[i] - 'a']++;
    }

    //queries
    int q2;
    cin >> q2; 
    while(q2--){
        char c2;
        cin >> c2; 
        //fetch
        cout << hash2[c2 - 'a'] << endl;
    }

    //-when string contains both uppercase and lowercase
    string s3;
    cin >> s3;

    //precompute
    int hash3[256] = {0};
    for(int i = 0; i < s3.length(); i++){
        hash3[s3[i]]++;
    }

    //queries
    int q3;
    cin >> q3;
    while(q3--){
        char c3;
        cin >> c3; // Fixed: removed Java scanner syntax
        //fetch
        cout << hash3[c3] << endl;
    }

    //map large nums like 10^9 or by using map\unordered_map
    int n2;
    cin >> n2;
    int arr2[n2];
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }

    //precompute
    unordered_map<int, int> mp; // Fixed: Changed from Java HashMap to C++ unordered_map
    for(int i = 0; i < n2; i++){
        mp[arr2[i]]++; // Simplified: directly increment the count
    }

    // Iterate over the map (example):
    /* for (auto it : mp) {
        cout << it.first << "->" << it.second << endl;
    } */

    int q4; 
    cin >> q4;
    while (q4--) {
        int number;
        cin >> number;
        // fetch:
        cout << mp[number] << endl; // Simplified: mp[number] returns 0 if key doesn't exist
    }

    return 0;
}

//---collision & How the hashing works---
//Hashing is done using many methods, most imp is Division method
//for ex:
//Assume, given array: [2, 5, 16, 28, 139]. Here, we can apply array hashing, & to use that, we gotta create array of size 140.
// Now, what if we are given a condition that we cant use array whose length is greater than 10?
//we'll use division method. We'll consider modulo 10 of each element of array(element % 10) & we'll hash(pre-store and fetch) elements on the basis of remainder.
//Steps will look like this: Pre storing: hash[arr[i]%10] += 1 and Fetching: hash[number%10]
//Now if we apply this method to given array, hash array will look like this:
// 0 1 2 3 4 5 6 7 8 9
// 0 0 1 0 0 1 1 0 1 1
//This is how the division method works. We simply reduce the array elements and apply array hashing.

//-Question: What if 2 or more array elements give same remainder for modulo 10?
//here, we apply linear chaining method. This method is implemented using LinkedList.
//Here, we just need to understand the logic. While storing the elements we'll maintain a chain(i.e. inserting the element itself to the corresponding index instead of just keeping the count) for each index(i.e. the remainder we get). & in that chains, we'll store the elements in a sorted manner
//for ex: Given array: [2, 5, 16, 28, 139, 38, 48, 28, 18]
//In this array 28, 38, 48, 18 are giving same value for modulo 10. So, we'll apply linear chaining. The hash array will look like this:
// 0
// 1
// 2 -> 2
// 3
// 4
// 5 -> 5
// 6 -> 16
// 7
// 8 -> 18 -> 28 -> 28 -> 38 -> 48
// 9 -> 139
//Now to get frequency of number, we'll first go to (number % 10) indexed chain and count the frequency of that number.