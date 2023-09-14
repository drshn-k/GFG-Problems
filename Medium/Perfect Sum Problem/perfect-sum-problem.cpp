//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	
	int f(int i,int t,int sum,int arr[],int n, vector<vector<int>> &dp){
	    
	    if(i==n){
	        return 0;
	    }
	    
	    if(dp[i][t]!=-1){
	        return dp[i][t];
	    }
	    
	    int x=f(i+1,t,sum,arr,n,dp);
	    if(arr[i]+t<=sum){
	        if(arr[i]+t==sum){
	            x++;
	        }
	        
	        x+=f(i+1,t+arr[i],sum,arr,n,dp);
	    }
	    
	    return dp[i][t]= x%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(0,0,sum,arr,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends