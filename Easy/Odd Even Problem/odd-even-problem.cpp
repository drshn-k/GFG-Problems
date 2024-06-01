//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
bool check(int a, int b){
        if((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0)) return 1;
        else return 0;
    }
  
    string oddEven(string s) {
        // code here 
        unordered_map<char, int>mpp;
        int n=s.length();
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }
        int cnt=0;
        for(auto &it:mpp){
            cnt+=(check(it.first-'a'+1, it.second));
        }
        if(cnt%2==0) return "EVEN";
        else return "ODD";   // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends