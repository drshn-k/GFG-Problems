//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
    int dp[1001][1001];
    int help(int n,int m,int a[],int b[]){
       if(n==0 && m==0) return 0;
        if(n<=0) return INT_MIN;
        if(m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int take=a[n-1]*b[m-1]+help(n-1,m-1,a,b);
        int nottake=help(n-1,m,a,b);
       return dp[n][m]=max(take,nottake);
    }
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        
        memset(dp,-1,sizeof(dp));
        int ans=help(n,m,a,b);
        return ans;	// Your code goes here
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends