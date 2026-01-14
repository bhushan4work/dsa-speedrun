//statement- Find the floor and ceiling of 'x' in sorted arr
//floor- largest num <= x (val just 1 index before x which is <= x)
//ceil- smallest num >= x (val just 1 index after x which is >= x)   -lowerBound algo can be used here


//(optimal) t.c- O(logn)  s.c- O(1)
pair<int, int> getFloorAndCeil(int a[], int n, int x) {
    int floor = -1, ceil = -1;  // Default set to -1 (if x not found)
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == x) { 
            return {x, x}; //floor & index will be same
        }
        else if (a[mid] < x) {
            floor = a[mid];
            low = mid + 1; //floor is largestNum <= x & so we further check to the right to get largest
        }
        else {
            ceil = a[mid];
            high = mid - 1;  //ceil is smallestNum >= x & so we further check to the left to get smallest
        }
    }
    return {floor, ceil};
}
