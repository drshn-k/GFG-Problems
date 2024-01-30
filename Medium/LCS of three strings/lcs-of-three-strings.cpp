//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

      int getMaxCommomnLCS(string& A, string& B, string& C, vector<vector<vector<int>>>& dp, 
    int i, int j, int k){
        if(i < 0 || j < 0 || k < 0){
            return 0;
        }else if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }else if(A[i] == B[j] && A[i] == C[k]){
            return dp[i][j][k] = 1 + getMaxCommomnLCS(A, B, C, dp, i-1, j-1, k-1);
        }else{
            return dp[i][j][k] = max({getMaxCommomnLCS(A, B, C, dp, i-1, j, k), getMaxCommomnLCS(A, B, C, dp, i, j-1, k),
            getMaxCommomnLCS(A, B, C, dp, i, j, k-1)});
        }
    }
    public:
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
            int maxComSeq{getMaxCommomnLCS(A, B, C, dp, n1-1, n2-1, n3-1)};
            return maxComSeq;
        }

};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends