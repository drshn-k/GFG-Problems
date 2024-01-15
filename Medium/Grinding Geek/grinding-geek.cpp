//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   int solve(int ind, int n, int total, vector<int> &cost, vector<vector<int>> &dp) 
    {
        if(total <= 0)
            return 0;
        
        if(ind == n)
            return 0;
            
        if(dp[ind][total] != -1)
            return dp[ind][total];
            
        int notPick = solve(ind + 1, n, total, cost, dp);
        int pick = 0;
        
        if(cost[ind] <= total)
            pick = 1 + solve(ind + 1, n, total - cost[ind] + (0.9 * cost[ind]), cost, dp);
            
        return dp[ind][total] = max(pick, notPick);
    }

    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n, vector<int> (total + 1, -1));
        return solve(0, n, total, cost, dp);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends