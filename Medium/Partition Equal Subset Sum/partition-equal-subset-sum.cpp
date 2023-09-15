//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(vector<vector<int>>& dp, int n, int i, int target, int sum, int arr[]){
        if(sum > target)return 0;
        if(i > n)return 0;
        if(sum == target)return 1;
        bool a = find(dp,n,i+1,target,sum+arr[i],arr);
        if(a){
            dp[i][sum] = 1;
            return 1;
        }
        bool b = find(dp,n,i+1,target,sum,arr);
        dp[i][sum] = (a | b);
        return dp[i][sum];
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        if(sum % 2 == 1)return 0;
        sum /= 2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return find(dp,n,0,sum,0,arr);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends