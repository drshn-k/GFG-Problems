//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        // code here
        
        int sum = 0;
        int m = N;
        
        while(m != 0){
            int dig = m%10;
            sum = sum + dig;
            m = m/10;
        }
        
        string sample = "abcdefghijklmnopqrstuvwxyz";
        
        string ans = "";
        
        if(N >= 26){
            int a = N/26;
            for(int i = 0 ; i < a ; i++)
            ans = ans + sample;
        }
        
        
        N = N%26;
        
         if(N&1){
            
            if(sum%2 == 0){
                int start = (N+1)/2;
                int end = (26 - (N-1)/2);
                
                for( int i = 0 ; i < start ; i++) ans = ans + sample[i];
                
                for(int i = end ; i < 26 ; i++) ans = ans + sample[i];
                
                
            }
            
            else {
                
                 int start = (N-1)/2;
                int end =  (26 - (N+1)/2);
                
                  for( int i = 0 ; i < start ; i++) ans = ans + sample[i];
                  
                     for(int i = end ; i < 26 ; i++) ans = ans + sample[i];
                
                
            }
            
            
        }
        
        else {
            int start = N/2;
            
            int end = 26 - N/2;
             for( int i = 0 ; i < start ; i++) ans = ans + sample[i];
                  
                     for(int i = end ; i < 26 ; i++) ans = ans + sample[i];
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends