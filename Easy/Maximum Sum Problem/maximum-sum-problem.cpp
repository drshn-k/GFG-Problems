//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
           vector<int>dp(n + 1 , INT_MIN);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 3;
            dp[4] = 4;
            
            for(int i = 5 ; i <= n ; i++) {
               int sum = dp[i / 2] + dp[i / 3] + dp[i / 4];
               dp[i] = max(i,sum);
            }
            return dp[n]; //code here.
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends