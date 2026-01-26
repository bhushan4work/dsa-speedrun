// statement- ‘arr[i]’ represents no of pages in ith book. There are ‘m’ number of students, & task is to allocate all books to students
// Allocate books in such a way that:
// 1)each student gets at least 1 book 2)Each book should be allocated to only 1 student 3)Book allocation should be in contiguous manner
// You have to allocate the book to ‘m’ students such that max no of pages assigned to student is min. If allocation of books not possible return -1

// method1(brute) t.c- O( N * (sum(arr)-max(arr)) )  s.c- O(1)  -normal iteration is done i.e bs not used here
int countStudents(vector<int> &arr, int pages){
    int n = arr.size(); 
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++){
        if (pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];  // add pages to current student
        }
        else{
            students++; 
            pagesStudent = arr[i]; // add pages to next student
        }
    }
    return students;
}
int findPages(vector<int> &arr, int n, int m){
    if (m > n) return -1;

    int ans = 0;
    int low = *max_element(arr.begin(), arr.end()); //gives max in arr
    int high = accumulate(arr.begin(), arr.end(), 0); //gives sum of arr

    for (int pages = low; pages <= high; pages++){
        if (countStudents(arr, pages) == m){ 
            ans = pages;
            break;
        }
    }
    return ans;
}


// method2(optimal) t.c- O( N * log(sum(arr)-max(arr)) )  s.c- O(1)  -bs used here
int countStudents(vector<int> &arr, int pages){
    int n = arr.size(); 
    int students = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < n; i++){
        if (pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];   // add pages to current student
        }
        else{
            students++;
            pagesStudent = arr[i];  // add pages to next student
        }
    }
    return students;
}
int findPages(vector<int> &arr, int n, int m){
    if (m > n) return -1;

    int ans = 0;
    int low = *max_element(arr.begin(), arr.end()); //gives max in arr
    int high = accumulate(arr.begin(), arr.end(), 0); //gives sum of arr

    while (low <= high){
        int mid =  low + (( high - low) / 2);
        int students = countStudents(arr, mid); 
        // if (students > m){   //another way to write if else here
        //     low = mid + 1; // move right
        // }
        // else{
        //     ans = mid;
        //     high = mid - 1; //move left to minimize pgs so as to get m students
        // }
        if (students <= m){  
            ans = mid;
            high = mid - 1; //move left to minimize pgs so as to get m students
        }
        else{
            low = mid + 1; //else move right
        }
    }
    return ans;
}
