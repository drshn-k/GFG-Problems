//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
int solve(int *arr,int n,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int t=0,nt=0;
        t = arr[n] + solve(arr,n-2,dp);
        nt = solve(arr,n-1,dp);
        return dp[n] = max(t,nt);
    }
    
    int solve2(int *arr,int n){
        vector<int>dp(n,0);
        
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i]=arr[i];
                continue;
            }
            else if(i==1){
                dp[i] = max(arr[i],arr[i-1]);
            }
            else{
                dp[i] = max((arr[i]+dp[i-2]),dp[i-1]);
            }
        }
        return dp[n-1];
    }
    
    int solve3(int *arr,int n){
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        
        int prv2=arr[0],prv1=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){
                int curr = max((arr[i]+prv2),prv1);
                prv2=prv1;
                prv1=curr;
        }
        
        return prv1;
    }
    
    int solve4(int *arr,int n){
        int prv2=0,prv1=0;
        
        for(int i=0;i<n;i++){
                int curr = max((arr[i]+prv2),prv1);
                prv2=prv1;
                prv1=curr;
        }
        
        return prv1;
    }
 
// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n) {
    // code here
    vector<int>dp(n,-1);
   // return solve(arr,n-1,dp);
   //return solve2(arr,n);
   //return solve3(arr,n);
   return solve4(arr,n);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends