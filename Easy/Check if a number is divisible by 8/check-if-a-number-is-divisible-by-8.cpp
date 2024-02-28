//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
         //code here
        int n = s.length();
        if (n < 3) {
        int num = stoi(s); // Convert string to integer
        if (num % 8 == 0) {
            return 1;
        } else {
            return -1;
        }
    }
        string ltd = s.substr(n - 3);

    // Convert last three digits to an integer
        int lt = stoi(ltd);

    // If the last three digits are divisible by 8, the entire number is divisible by 8
        if (lt % 8 == 0) {
            return 1;
        } else {
         return -1;  }  //code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends