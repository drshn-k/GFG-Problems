//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
       // code here
        vector<int> sol;
        fun(sol,N);
        return sol;
    }
    void fun(vector<int> &sol,int N){
        sol.push_back(N);
        if(N<=0){
            return ;
        }
        else{
            fun(sol,N-5);
        }
        sol.push_back(N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends