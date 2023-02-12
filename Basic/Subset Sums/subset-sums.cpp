//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    void sum(int i,vector<int>&arr,int n,vector<int> &ans, int s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        sum(i+1,arr,n,ans,s+arr[i]);
        sum(i+1,arr,n,ans,s);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        // vector<int>ds;
        int s=0;
        sum(0,arr,N,ans,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends