//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findWinner(int n, int A[]){
          int a=0;
        for(int i=0;i<n;i++)
        {
            a=a^A[i];    // getting xor of array and storing it into a
        }
        if(a==0)   //checking value of a is already 0 or not
        {
            return 1;
        }else
        {
            if(n%2!=0)   //if value of a is not  0, then cheking whether it is even or odd
            {
                return 2;
            }else
            {
              return 1;  
            }  // code here
    }}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends