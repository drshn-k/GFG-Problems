//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
              vector<int>dp(n);dp[0]=0;
        vector<int>ans; ans.push_back(0);
        unordered_map<int,int>m;m[0]++;
        for(int i=1;i<n;i++){
            int g=dp[i-1]-i;
            if(g>0 && m.find(g)==m.end())
            {
                dp[i]=g;
                m[g]++;
                ans.push_back(g);
            }
            else
            {
                dp[i]=dp[i-1]+i;
                ans.push_back(dp[i]);
                m[dp[i]]++;
            }
        }
       
        return ans; // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends