//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
    #define ll long long 
class Solution{
    public:
    long long countWays(int n, int k){
          ll diff = k;
        ll same = 0;
        ll total = k;
        ll MOD = 1e9 + 7;
        if(n==1){
            return total;
        }
        else{
            for(int i=2;i<=n;i++){
                same = (diff)%MOD;
                diff = (total*(k-1))%MOD;
                total = (same + diff)%MOD;
            }
        }
        return (total)%MOD;  // code here
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends