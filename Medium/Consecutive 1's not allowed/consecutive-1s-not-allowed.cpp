//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
    #define ll long long
    #define mod 1000000007
    ll countStrings(int n) {
        // code here
        ll zero=1;
        ll one =1;
        
        for(int i=2;i<=n;i++){
            int temp=one;
            one=zero;
            zero=(zero+temp)%mod;
        }
        return (one+zero)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends