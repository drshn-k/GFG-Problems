//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
 int mod = 1e9+7;
    int subsequenceCount(string S, string T)
    {
      int n=S.length();
      int m=T.length();
      vector<int>prev(m+1,0);
    prev[0] = 1;
    
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=1;j--) {
            if(S[i-1]==T[j-1])  prev[j] = (prev[j-1]%mod + prev[j]%mod)%mod;
            else  prev[j] = prev[j]%mod;
        }
        
    }
    return prev[m]%mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends