//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
      int maxCoins(int N, vector<int> &a)
    {
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(N + 2, vector<int> (N + 2, 0));
        
        for(int i = N; i > 0; i--) {
            for(int j = 1; j <= N; j++) {
                if(i > j) continue;
                int profit = 0;
                for(int k = i; k <= j; k++) {
                    int cost = a[i - 1] * a[k] * a[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    profit = max(profit, cost);
                }
                dp[i][j] = profit;
            }
        }
        
        return dp[1][N];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends