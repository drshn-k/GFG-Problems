//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {      string org=A;

       while(A.length()<B.length())

       {

          A+=org;

           

       }

       if(A.find(B)!=string::npos)return A.length()/org.length();

       A+=org;

       if(A.find(B)!=string::npos)return A.length()/org.length();

       return -1;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends