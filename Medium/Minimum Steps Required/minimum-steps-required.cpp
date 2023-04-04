//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int cnt = 0;
    
    for(int i = 0 ; i < str.size()-1 ; i++)if(str[i] != str[i+1])cnt++;
    
    if(cnt&1)return cnt/2+2;
    
    return cnt/2+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends