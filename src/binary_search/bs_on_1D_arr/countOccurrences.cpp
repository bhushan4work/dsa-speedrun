//statement- find the total occurrences of x in the given sorted arr

//method1(brute) t.c- O(n)  s.c- O(1)   -normal iteration is done i.e bs not used here
int count(vector<int>& arr, int n, int x) {
	int cnt = 0;
  for (int i = 0; i < n; i++){
    if (arr[i] == x){
		cnt++;
    }
  }
  return cnt;
}

//method2(optimal) t.c- O(2logn)  s.c- O(1)   -using lb & ub
int lowerBound(vector<int> &arr, int x){
  int n = arr.size();
  int low = 0 , high = n - 1;
  int ans = n; // Default set to n (if x not found)

  while (low <= high){  // Binary search loop
    int mid = (low + high) / 2; // gives Middle index

    if (arr[mid] >= x){
      ans = mid;      // Stores possible answer
      high = mid - 1; // Try to find smaller index on left side
    }
    else{
      low = mid + 1; // Move right if current element is less than x
    }
  }
  return ans; // Return index of lb
}

int upperBound(vector<int> &arr, int x){
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n; // Default set to n (if x not found)

  while (low <= high){
    int mid = (low + high) / 2;

    if (arr[mid] > x){
      ans = mid;      // Potential answer found
      high = mid - 1; // Try to find smaller valid index on the left
    }
    else{
      low = mid + 1; // Move right if mid is <= x
    }
  }
  return ans; // Return index of ub
}

vector<int> searchRange(vector<int> &arr, int x){
  int n = arr.size();
  int lb = lowerBound(arr, x);
  int ub = upperBound(arr, x);
  if (lb == n || arr[lb] != x) return {-1, -1}; //if lb not found then obv no occurence exists
  return {lb, ub - 1}; // ub gives 1 index greater than last occurence & so we did '-1'
}

int count(vector<int> &arr, int n, int x) {
    pair<int,int> ans = searchRange(arr, n, x);
    if( ans.first == -1 ) return 0;  //first is syntax of pair & not the variable here
    return ans.second - ans.first + 1;  //second & first is syntax of pair & not the variable here
}


//method3(optimal) t.c- O(2logn)  s.c- O(1)   -without using lb\ub algo, by writing specific bs for this
int firstOccurrence(vector<int>& arr, int n, int x){
  int low = 0 ,high = n - 1;
  int ans = -1; // Default set to -1 (if x not found)

  while (low <= high){  // Binary search loop
    int mid = (low + high) / 2; // gives Middle index

    if (arr[mid] == x){
      ans = mid;      // Stores possible answer
      high = mid - 1; // Try to find 1st occurrence on left side
    }
    else if (arr[mid] > x){
      high = mid - 1; // Move left if current element is > x
    }
    else{
      low = mid + 1; // Move right if current element is < x
    }
  }
  return ans;
}

int lastOccurrence(vector<int> &arr,int n, int x){
  int low = 0, high = n - 1;
  int ans = -1; // Default set to -1 (if x not found)

  while (low <= high){
    int mid = (low + high) / 2;

    if (arr[mid] == x){
      ans = mid;     // Potential answer found
      low = mid + 1; // Try to find last occurrence on right side
    }
    else if (arr[mid] > x){
      high = mid - 1; // Move left if current element is > x
    }
    else{
      low = mid + 1; // Move right if current element is < x
    }
  }
  return ans;
}

pair<int,int> searchRange(vector<int> &arr,int n, int x){
  int first = firstOccurrence(arr, n, x);
  int last = lastOccurrence(arr, n,  x);
  if(first == -1) return {-1,-1};
  return {first, last};
}

int count(vector<int>& arr, int n, int x) {
    pair<int,int> ans = searchRange(arr, n, x);
    if(ans.first == -1) return 0;  //first is syntax of pair & not the variable here
    return ans.second - ans.first + 1;  //second & first is syntax of pair & not the variable here
}