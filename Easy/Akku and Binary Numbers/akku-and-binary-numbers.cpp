//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
  #define ll long long
    void precompute()
    {
        // Code Here
    }
    
    long long solve(long long l, long long r){
        ll cnt=0;
        for(int i=0;i<63 && (1<<i)<=r;i++){
           for(int j=i+1;j<63 && (1<<j)<=r;j++){
              for(int k=j+1;k<63 && (1<<k)<=r;k++){
                  ll n=0;
                  n=n|(1ll<<i)|(1ll<<j)|(1ll<<k);
                  
                  if(n>=l && n<=r)
                   cnt++;
                  else if(n>r)
                   break;
               } 
           } 
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends