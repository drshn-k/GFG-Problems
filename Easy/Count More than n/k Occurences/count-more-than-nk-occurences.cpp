//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
          sort(arr,arr+n);
       int count=0,ans=0;
       int i=0,j;
       while(i<n)
       {
           
            int count=0;
           for(j=i;j<n;j++)
           {
            
               if(arr[i]==arr[j])
               {
                   count++;
               }
               if(arr[i]!=arr[j])
               {
                   break;
               }
           }
           
           if(count>n/k)
           {
              // cout<<count<<endl;
               ans+=1;
           }
           i=j;
       }
       return ans; // Your code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends