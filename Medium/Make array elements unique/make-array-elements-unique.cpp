//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) 

    {

        unordered_map <long long, int> mpp;

        

        int count = 0;

        for(int i = 0; i < N; i++)

        {

             mpp[arr[i]]++;

             

             while(mpp[arr[i]] > 1)

             {

                 count++;

                 arr[i] += 1;

                 mpp[arr[i]]++;

             }

        }

        return count;

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
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends