#include <iostream>
#include <algorithm> //for reverse 
using namespace std ;

//method1 - using extra array
//Function to print array
void printArray1(int ans1[], int n) {
    cout << "Reversed array is:- " ;
    for (int i = 0; i < n; i++) {
        cout << ans1[i] << " " ;
    }
}

//Function to reverse array using an auxiliary array
void reverseArray1(int arr[], int n) {
    int ans1[n];  //new auxiliary array is created
    for (int i = n - 1; i >= 0; i--) {
        ans1[n - i - 1] = arr[i];
    }
    printArray1(ans1, n);
}

//method2 - space optimised iterative method
//Function to print array
void printArray2(int arr2[], int n){
    cout << endl ;
    cout << "Reversed array is:- " ;
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " " ;
    }
}
    
//Function to reverse array
void reverseArray2(int arr2[], int n) {
    int p1 = 0, p2 = n - 1;
    while (p1 < p2) {
        int tmp = arr2[p1];
        arr2[p1] = arr2[p2]; //swaps element at index 0 with 4
        arr2[p2] = tmp;  //swaps element at index 4  with 0
        p1++;
        p2--;
    }
    printArray2(arr2, n);
}

//method3 - recursive method
//Function to print array
void printArray3(int arr3[], int n) {
    cout << endl ;
    cout << "Reversed array is:- " ;
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " " ;
    }
}

//Function to reverse array using recursion
void reverseArray3(int arr3[], int start, int end) {
    if (start < end) {
        int tmp = arr3[start];
        arr3[start] = arr3[end];
        arr3[end] = tmp;
        reverseArray3(arr3, start + 1, end - 1);
    }
}

//method4 - using library fxn
//Function to print array
//ex: int[] primitiveArray = {1, 2, 3};        Won't work with Collections
//    Integer[] objectArray = {1, 2, 3};       Works with Collections
void printArray4(int arr4[], int n) {
    cout << endl ;
    cout << "Reversed array is:- " ;
    for (int i = 0; i < n; i++) {
        cout << arr4[i] << " " ;
    }
}
    
//Reverse array using library function
void reverseArray4(int arr4[] , int n) {
    //fetching array as list object
    //reversing the fetched object
    reverse(arr4, arr4 + n);  //aslist converts array to list
}

int main(){
    //1
    int n = 5;
    int arr1[] = { 5, 4, 3, 2, 1};
    reverseArray1(arr1, n);

    //2
    n = 5;
    int arr2[] = { 5, 4, 3, 2, 1};
    reverseArray2(arr2, n);

    //3
    n = 5;
    int arr3[] = { 5, 4, 3, 2, 1};
    reverseArray3(arr3, 0, n - 1);
    printArray3(arr3, n);

    //4
    n = 5;
    int arr4[] = {5,4,3,2,1};
    reverseArray4(arr4 , n);
    printArray4(arr4, n);
}