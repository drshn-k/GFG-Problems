//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	     const long long mod=(long long)(1e9+7);
	     long long a=1;
	     long long b=1;
	     for(int i=n-1;i>=0;i--)
	     {
	         long long c=a;
	         a=(a%mod+b%mod)%mod;
	         b=(c)%mod;
	         
	     }
	     long long res=(a%mod*a%mod)%mod;
	    return res;  // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends