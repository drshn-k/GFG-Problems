//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
         // Your code here
        if(m==n){
            return -1;
        }
        int ans =1;
        int m1 =0, n1= 0;
        
        while(m && n){
            m1 = m%2;
            n1 = n%2;
            if(m1 != n1){
                // ans++;
                return ans;
            }
            ans++;
            m=m/2;
            n=n/2;
        }
        
        return ans;  // Your code here
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends