//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int> r;
        for(int i = 0; i<n; i++){
            r[arr[i]]++;
        }
        for(int i = 0; i<arr.size();i++){
            reverse(arr[i].begin(),arr[i].end());
            r[arr[i]]++;
        }
        for(auto it:r){
            if(it.second%2!=0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends