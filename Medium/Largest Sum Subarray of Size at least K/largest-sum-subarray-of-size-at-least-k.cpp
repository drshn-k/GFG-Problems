//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
       long long int i = 0, j = 0;
        long long int mx = INT_MIN;
        long long int sum = 0, preNeg = 0;
        while(j<n)
        {
            sum += a[j];
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                mx = max(mx, sum);
                j++;
            }
            else
            {
                mx = max(mx, sum);
                preNeg += a[i++];
                if(preNeg < 0)
                {
                    sum -= preNeg;
                    mx = max(mx, sum);
                    preNeg = 0;
                }
                j++;
            }
        }
        return mx; 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends