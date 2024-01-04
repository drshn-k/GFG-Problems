//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int a[33] = {0};
        for(int i=0;i<N;i++)
        {
            int val = 0;
            if(arr[i] < 0) a[32]++;
            while(arr[i])
            {
                if(arr[i]%2) a[val]++;
                val++;
                arr[i] /= 2;
            }
        }
        int num = 0;
        for(int i=0;i<32;i++)
        {
            if(a[i]%3) num += (1<<i);
        }
        return a[32]%3 != 0 ? -1*num: num;  // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends