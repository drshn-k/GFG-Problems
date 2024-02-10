//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
     int f(int i,int j, vector<vector<int>> &arr,int k,int n, vector<vector<vector<long long>>> &dp){
        if(i<0 || j<0 || k<0) return 0;
        if(i==0 && j==0) {
            if(k==arr[0][0]) return 1;
            else return 0;
        }
        
         if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ways=f(i-1,j,arr,k-arr[i][j],n,dp)+f(i,j-1,arr,k-arr[i][j],n,dp);
        
        return dp[i][j][k]=ways;
    }

 

 


    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        vector<vector<vector<long long>>> dp(n, vector<vector<long long >>(n, vector<long long>(k+1, -1)));
        return f(n-1,n-1,arr,k,n,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends