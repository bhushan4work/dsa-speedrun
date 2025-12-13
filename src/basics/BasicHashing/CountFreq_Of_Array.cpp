#include <iostream>
#include <unordered_map>
using namespace std;

//in hashmap- keys are placed in sorted order
void CountFreq1(int arr1[], int n1){
    bool visited[n1] = {false}; // Initialize all to false

    for(int i = 0; i < n1; i++){
        //skip this element if already processed
        if(visited[i] == true)
            continue; //used to skip the element

        //count freq
        int count = 1;
        for(int j = i + 1; j < n1; j++){ // Fixed: start from i+1, not 0
            if(arr1[i] == arr1[j]){
                visited[j] = true;
                count++;
            }
        }
        cout << arr1[i] << " " << count << endl;
    }
}

void CountFreq2(int arr2[], int n2) {
    unordered_map<int, int> map; // Fixed: Changed from Java Map to C++ unordered_map

    for (int i = 0; i < n2; i++) {
        map[arr2[i]]++; // Simplified: directly increment count
    }

    // Traverse through map and print frequencies
    for (auto entry : map) { // Fixed: Changed from Java syntax to C++ range-based for loop
        cout << entry.first << " " << entry.second << endl; // Fixed: Added endl and semicolon
    }
}

int main(){
    //---1)using 2 loops---   [T.C - O(N*N) , S.C - O(N)]
    int arr1[] = {10, 5, 10, 15, 10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);  // calculates length of array
    CountFreq1(arr1, n1);
    
    cout << endl; // Separate outputs
    
    //---2)using hashmap---   [T.C - O(N) , S.C - O(N)]
    int arr2[] = {10, 5, 10, 15, 10, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);  // calculates length of array
    CountFreq2(arr2, n2);
    
    return 0;
}