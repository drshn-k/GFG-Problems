//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
         int idx=(n)/(1<<r);
        char c=s[idx];
        n-=idx*(1<<r);r--;
        while(n>0){
            idx=(n)/(1<<r);
                if(idx==0){
                    c=(c=='1')?'1':'0';
                }
                else{
                    c=(c=='1')?'0':'1';
                }
                n-=idx*(1<<r);r--;
        }
        return c;  //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends