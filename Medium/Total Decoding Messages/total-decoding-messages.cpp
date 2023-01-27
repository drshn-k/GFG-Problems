//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int CountWays(string s)
        {
            int mod = 1e9+7;
            int n = s.size();
            int curr=0, prev[2]={0};
            if(s[0]!='0') 
		           prev[0] = prev[1] = 1;
            
            for(int i=1;i<=n;i++)
            {
                int single = 0;
                if(s[i-1]!='0')
                    single = prev[1];
                
                int doubles = 0;
                if((s[i-2]=='1') or (s[i-2]=='2' && s[i-1]<='6'))
                    doubles = prev[0]; 
                
                curr = (single+doubles)%mod;
                prev[0] = prev[1];
                prev[1] = curr;
                
            }
            return prev[1];
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends