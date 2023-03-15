//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
   void Recursion(string s1,string &s2,int ind,int &mini,int &n1,int &n2){
    if(ind+n2>n1) return;
    int i = ind,j = 0,ct = 0;
    string t = s1;
    for(int i=ind;i<n2+ind;i++){
        if(t[i]!=s2[i-ind]){
            t[i] = s2[i-ind];
            ct++;
        }
    }
    int l = 0, r = n1-1;
    bool flag = false;
    while(l<r){
        if(t[l]!=t[r]){
            if(l<ind){
                t[l] = t[r];
            }
            else if(r>=n2+ind){
                t[r]=t[l];
            }
            else{
                flag = true;
                break;
            }
            ct++;
        }
        l++;
        r--;
    }
    // cout<<ct<<" f "<<flag<<endl;
    if(!flag) mini = min(mini,ct);
    return Recursion(s1,s2,ind+1,mini,n1,n2);
}
int specialPalindrome(string s1, string s2){
    int mini = INT_MAX,n1 = s1.length(),n2 = s2.length();
    Recursion(s1,s2,0,mini,n1,n2);
    if(mini==INT_MAX) return -1;
    return mini;
}



};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends