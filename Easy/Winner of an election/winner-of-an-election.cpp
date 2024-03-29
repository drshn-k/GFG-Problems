//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
   unordered_map<string,int> mp;
     for(int i=0;i<n;i++)
     mp[arr[i]]++;
     vector<string> v;
     int mx=0;
     string s="";
     for(auto it:mp){
     if(it.second >mx || (it.second >=mx && it.first < s) )
       {
         mx = it.second;
         s = it.first;
        }  }
        v.push_back(s);
        v.push_back(to_string(mx));
        return v;      // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends