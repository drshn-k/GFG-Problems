//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

    public:

        // Function to return the length of the

        //longest subarray with ppositive product

        // int solve(vector<int> arr,int p,int i){

        //     if(i<0) return 

        // }

        int maxLength(vector<int> &arr,int n){

           //code here

          int p=1;int ans=0;int j=0;vector<int> v;

           v.push_back(1);

           for(int i=0;i<n;i++){

               if(arr[i]<0) p*=-1;

               else if(arr[i]>0) p*=1;

               

               if(arr[i]!=0) v.push_back(p);

               else{

               v.push_back(0);p=1;

               }

           }

           int f=v[0];j=-1;int k=-1;

           for(int i=0;i<=n;i++){

              if(v[i]==1&&j==-1) j=i;

              if(v[i]==1) k=i;

              if(v[i]==0) j=i;

              if(j!=-1&&k!=-1)

              ans=max(ans,k-j);

           }

           j=-1;k=-1;

           

           for(int i=0;i<=n;i++){

              if(v[i]==-1&&j==-1) j=i;

              if(v[i]==-1) k=i;

              if(v[i]==0) j=-1;

               if(j!=-1&&k!=-1)

              ans=max(ans,k-j);

           }

           return ans;

        }

};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends