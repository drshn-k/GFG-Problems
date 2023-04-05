//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
          unordered_map<int, bool> map;
    int ans = 0;

    // Traverse the entire array
    for (int i = 0; i < N; i++) {
      // If the element is already checked for then use that result by accessing
      // it from map
      if (map[arr[i]]) {
        ans++;
        continue;
      }
      // If it is the first time encountering that result then perform another
      // traversal on the array and find the first number which is a divisor of
      // the current number execpt itself
      for (int j = 0; j < N; j++) {
        if (i != j && !(arr[i] % arr[j])) {
          map[arr[i]] = 1;
          ans++;
          break;
        }
      }
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends