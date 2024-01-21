//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
      int solve(int count ,int ans , int v  ,int n ,int m , vector<int> adj[] ,vector<int>&dp )
        {
            if(count == m){
                return ans;
            }
            
            if(v == (n+1)){
                return INT_MAX ;
            }
           
            int a = INT_MAX ,b = INT_MAX ;
            
            a = solve(count , ans ,v+1 ,n , m ,adj ,dp);
            
            count += adj[v].size();
            
            for(auto it : adj[v])
            {
                if(dp[it] > 0){
                    count--;
                }
            }
            
            dp[v]++;
            b = solve(count , ans+1 ,v+1 ,n , m ,adj ,dp);
            
            int c = min(a ,b);
            //cout<<c<<endl;
            
            return min(a ,b);
            
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            // code here
             int num=1<<n,ans=n,cnt=0,c=0,m=edges.size();
            // GENERATE THE SUBSETS .....
            for(int i=1;i<(num);i++){
                cnt=0;c=0;
                for(int j=0;j<m;j++){
                    int l=1<<(edges[j].first-1);
                    int r=1<<(edges[j].second-1);
                    if(!( (l & i) || (r & i) )){
                        c=1;
                        break;
                    }
                }
                cnt=__builtin_popcount(i);
                if( c == 0 ) ans=min(cnt,ans); 
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends