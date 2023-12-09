//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
        int digitssum(int n) {
        int sum=0; 
        while(n>0) {
            sum+=(n%10) ; 
            n/=10; 
        }
        return sum; 
    }
    int smithNum(int n) {
        // code here
        int sum=digitssum(n); 
        int cur=n;
        int sum2=0; 
        bool prime=true; 
        for(int i=2; i*i<=n; i++) {
            while(cur%i==0) {
                sum2+=digitssum(i); 
                cur/=i; 
                prime=false; 
            }
        }
        if(cur>1) sum2+=digitssum(cur); 
        return (sum==sum2 && prime==false); 
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends