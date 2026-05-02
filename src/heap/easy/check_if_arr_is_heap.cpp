// statement- Check if given arr represents binary max-heap or not. Return true if it does, otherwise return false

//(optimal) t.c- O()  s.c- O(1)
bool isMaxHeap(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n / 2; i++){
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }

    return true;
}



// statement- Check if given arr represents binary min-heap or not. Return true if it does, otherwise return false

//(optimal) t.c- O()  s.c- O(1)
bool isMinHeap(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n / 2; i++){
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left]) return false;
        if (right < n && arr[i] > arr[right]) return false;
    }
    return true;
}
