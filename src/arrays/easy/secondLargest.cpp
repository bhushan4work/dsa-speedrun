#include <bits/stdc++.h>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    //method1(bruteForce) t.c.- nlogn + n    
    sort(a.begin(), a.end()); //sort the arr
    int largest = a[n - 1];
    int slargest = -1;  //if arr contains -ve num,take slargest=INT_MIN or smallest value possible
    for (int i = n - 2; i >= 0; i--) { 
        if (a[i] != largest) {
            slargest = a[i];
            break;
        }
    }
    return slargest;

    //method2-(better approach) t.c.- O(n+n)
    int largest = a[0];
    for(int i=0;i<arr.size();i++){
        if(a[i] > largest){
            largest = a[i];
        }
    }
    int slargest = -1; //if arr contains -ve num,take slargest=INT_MIN or smallest value possible
    for(int i=0;i<n;i++){
        if(a[i] != largest && a[i] > slargest){
            slargest = a[i];
        }
    }
    return slargest;

    //method3(best approach)
    //2nd largest t.c.- O(n)
    int largest = a[0];
    int slargest = -1; //take smallest value possible or INT_MIN
    for(int i=0;i<n;i++){
        if(a[i] > largest){
            slargest = largest; //if bigger value than largest exists then it changes & prev largest value is given to slargest
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > slargest){
            slargest = a[i];
        }
    }
    return slargest;
    
    //2nd smallest - same approach as above
    int smallest = a[0];
    int ssmallest = INT_MAX; //take greatest value possible
    for(int i=0;i<n;i++){
        if(a[i] < smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < ssmallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;

}
