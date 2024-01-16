//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  int calc(int i,int m, int n, vector<vector<int>>&dp)
    {
        if(n == 0)
            return 1;
        if(dp[i][n] != -1)
            return dp[i][n];
        int ans = 0;
        for(int j = 2*i; j<=m; ++j)
            ans += calc(j,m,n-1,dp);
        return dp[i][n] = ans;
    }
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = 0;
        for(int i = 1;i<=m;++i)
        {
            ans += calc(i,m,n-1,dp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends