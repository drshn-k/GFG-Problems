//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
         int i = 0;
        int j = i+1;
        int len = 1;
        string ans = "";
        int maxSize = 0;
        
        while(j < n && i < n){
            string str1 = s.substr(i, len);
            string str2 = s.substr(j, n - j);
            
            if(str2.find(str1) != string::npos){
                if(str1.length() > maxSize){
                    ans = str1;
                    maxSize = str1.length();
                }    
                
                j++;
                len++;
            }
            
            else{
                i++;
                j = i+1;
                len = 1;
            }
        }
        return ans == "" ? "-1" : ans; // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends